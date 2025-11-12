# 📂 DirWatcher

**DirWatcher** is a lightweight C++/Qt class for monitoring file system changes on both **Windows** and **Linux**.  
It detects file and folder **creation, deletion, modification, and renaming** events — with optional recursive watching.

---

## 🚀 Features

- ✅ Cross-platform support (Windows / Linux)
- ✅ Detects:
  - File created / deleted / modified
  - Folder created / deleted
  - File or folder renamed
- ✅ Optional recursive directory watching
- ✅ Simple signal-based event handling (Qt style)
- ✅ Can be easily extended or run inside a thread

---

## 🖥️ Supported Platforms

| OS | API Used | Recursive Support |
|----|-----------|-------------------|
| Windows | `ReadDirectoryChangesW` | ✅ |
| Linux | `inotify` | ✅ |

---

## ⚙️ Example Usage
```cpp
#include "dirwatcher.h"
#include <QObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    DirWatcher watcher;
    watcher.SetPath("/home/user/testdir");
    watcher.SetRecursive(true);

    QObject::connect(&watcher, &DirWatcher::FileAdded, [](const QString &path) {
        qDebug() << "File added:" << path;
    });

    QObject::connect(&watcher, &DirWatcher::FileModified, [](const QString &path) {
        qDebug() << "File modified:" << path;
    });

    QObject::connect(&watcher, &DirWatcher::FileRemoved, [](const QString &path) {
        qDebug() << "File removed:" << path;
    });

    watcher.StartWatching();

    return app.exec();
}
