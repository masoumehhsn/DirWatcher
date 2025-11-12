#include "dirwatcher.h"
#include <windows.h>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#ifdef Q_OS_LINUX
#include <sys/inotify.h>
#elif defined(Q_OS_WIN)
#include <windows.h>
#else
#error Unsupported OS
#endif

DirWatcher::DirWatcher() {
}

void DirWatcher::SetPath(const QString& path){
    dir_path_ = path;
}

void DirWatcher::SetRecursive(bool is_recursive){
    is_recursive_ = is_recursive;
}

void DirWatcher::StartWatching(){
    if (dir_path_ == ""){
        return;
    }
    else {
        static QString file_old_name = "";
#ifdef _WIN32
        const std::wstring dir_path = dir_path_.toStdWString();
        HANDLE h_dir = CreateFileW(
            dir_path.c_str(),
            FILE_LIST_DIRECTORY,
            FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
            nullptr,
            OPEN_EXISTING,
            FILE_FLAG_BACKUP_SEMANTICS,
            nullptr
            );

        if (h_dir == INVALID_HANDLE_VALUE) {
            qDebug() << "Failed to open directory.\n";
            return;
        }

        char buffer[1024];
        DWORD bytesReturned;

        while (true) {
            BOOL success = ReadDirectoryChangesW(
                h_dir,
                &buffer,
                sizeof(buffer),
                is_recursive_,  // TRUE => watch subdirectories
                FILE_NOTIFY_CHANGE_FILE_NAME |
                    FILE_NOTIFY_CHANGE_DIR_NAME |
                    FILE_NOTIFY_CHANGE_SIZE |
                    FILE_NOTIFY_CHANGE_LAST_WRITE,
                &bytesReturned,
                nullptr,
                nullptr
                );

            if (!success) {
                qDebug() << "ReadDirectoryChangesW failed.\n";
                break;
            }

            FILE_NOTIFY_INFORMATION* info = (FILE_NOTIFY_INFORMATION*)buffer;
            do {
                std::wstring file_name(info->FileName, info->FileNameLength / sizeof(WCHAR));
                auto relative_path = QDir::fromNativeSeparators(QString::fromStdWString(file_name));
                QString full_path = QDir(dir_path_).filePath(relative_path);

                switch (info->Action) {
                case FILE_ACTION_ADDED:
                {
                    HandleEntryChange(EventType::ADDED,full_path);
                    break;
                }
                case FILE_ACTION_REMOVED:
                    HandleEntryChange(EventType::REMOVED, full_path);
                    break;
                case FILE_ACTION_MODIFIED:
                    HandleEntryChange(EventType::MODIFIED, full_path);
                    break;
                case FILE_ACTION_RENAMED_OLD_NAME:
                    file_old_name = full_path;
                    break;
                case FILE_ACTION_RENAMED_NEW_NAME:
                    if(file_old_name != ""){
                        HandleEntryRename(file_old_name, full_path);
                        file_old_name = "";
                    }
                    break;
                }

                if (info->NextEntryOffset == 0) break;
                info = (FILE_NOTIFY_INFORMATION*)((LPBYTE)info + info->NextEntryOffset);
            } while (true);
        }

        CloseHandle(h_dir);
#elif __linux__
        int fd = inotify_init1(IN_NONBLOCK);
        if (fd < 0) {
            qDebug() << "inotify_init failed";
            return;
        }

        QMap<int, QString> watch_map;  // maps watch-descriptor → directory path

        // --- Helper function to add watch (recursive if enabled) ---
        std::function<void(const QString&)> addWatchRecursive =
            [&](const QString& path)
        {
            int wd = inotify_add_watch(fd,
                                       path.toStdString().c_str(),
                                       IN_CREATE | IN_DELETE | IN_MODIFY |
                                           IN_MOVED_FROM | IN_MOVED_TO);

            if (wd < 0) {
                qDebug() << "Failed to add watch on" << path;
                return;
            }

            watch_map.insert(wd, path);

            // Only recurse when recursive mode is enabled
            if (!is_recursive_)
                return;

            QDir dir(path);
            QFileInfoList subdirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

            for (const QFileInfo& entry : subdirs) {
                addWatchRecursive(entry.absoluteFilePath());
            }
        };

        // Add initial watch (recursive or non-recursive)
        addWatchRecursive(dir_path_);

        char buffer[BUFFER_LEN];
        QString rename_old_path;

        while (true) {
            int length = read(fd, buffer, BUFFER_LEN);
            if (length <= 0)
                continue;

            int i = 0;
            while (i < length) {
                auto* event = reinterpret_cast<struct inotify_event*>(&buffer[i]);
                QString parent_dir = watch_map[event->wd];
                QString full_path = parent_dir + "/" + QString::fromUtf8(event->name);

                // Convert to QFileInfo once (for file/folder check)
                QFileInfo fi(full_path);

                if (event->mask & IN_CREATE) {
                    HandleEntryChange(EventType::ADDED, full_path);

                    // If recursive, add watcher when new dir appears
                    if (is_recursive_ && (event->mask & IN_ISDIR)) {
                        addWatchRecursive(full_path);
                    }
                }

                if (event->mask & IN_MODIFY) {
                    HandleEntryChange(EventType::MODIFIED, full_path);
                }

                if (event->mask & IN_DELETE) {
                    HandleEntryChange(EventType::REMOVED, full_path);
                }

                if (event->mask & IN_MOVED_FROM) {
                    rename_old_path = full_path;
                }

                if (event->mask & IN_MOVED_TO) {
                    if (!rename_old_path.isEmpty()) {
                        HandleEntryRename(rename_old_path, full_path);
                        rename_old_path.clear();
                    }
                }

                i += EVENT_SIZE + event->len;
            }
        }

        close(fd);
#endif

    }
}

void DirWatcher::HandleEntryChange(EventType event_type, const QString& path){
    QFileInfo file_info(path);
    switch (event_type) {
    case EventType::ADDED:
    {
        if(file_info.isFile())
            emit FileAdded(path);
        else
            emit FolderAdded(path);
        break;
    }
    case EventType::REMOVED:
    {
        if (!file_info.suffix().isEmpty())
            emit FileRemoved(path);
        else
            emit FolderRemoved(path);

        break;
    }
    case EventType::MODIFIED:
    {
        if(file_info.isFile())
            emit FileModified(path);
        break;
    }
    default:
        break;
    }
}

void DirWatcher::HandleEntryRename(const QString& old_path, const QString& new_path){
    QFileInfo file_info(new_path);
     if(file_info.isFile())
    {
        emit FileRenamed(old_path, new_path);
    }
}

