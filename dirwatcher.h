#ifndef DIRWATCHER_H
#define DIRWATCHER_H
#include <QObject>

enum class EventType{
    ADDED,
    MODIFIED,
    REMOVED,
    RENAMED
};

class DirWatcher: public QObject
{
    Q_OBJECT
public:
    DirWatcher();
    void SetPath(const QString& path);
    void SetRecursive(const bool is_recursive);
    void StartWatching();

signals:
    void FileModified(const QString& path);
    void FileAdded(const QString& path);
    void FolderAdded(const QString& path);
    void FileRemoved(const QString& path);
    void FolderRemoved(const QString& path);
    void FileRenamed(const QString& old_path, const QString& new_path);
    void FolderRenamed(const QString& old_path, const QString& new_path);

private:
    void HandleEntryChange(const EventType event_type, const QString& path);
    void HandleEntryRename(const QString& old_path, const QString& new_path);

    QString dir_path_;
    bool is_recursive_ = false;
    EventType event_type_;
};
#endif // DIRWATCHER_H
