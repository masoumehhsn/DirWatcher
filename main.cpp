#include <QCoreApplication>
#include "dirwatcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DirWatcher dir_watcher;
    dir_watcher.SetPath("C:/Users");
    QObject::connect(&dir_watcher, &DirWatcher::FileModified,[](const QString& path){qDebug()<<"file modified"<< path;});
    QObject::connect(&dir_watcher, &DirWatcher::FileAdded,[](const QString& path){qDebug()<<"file added"<< path;});
    QObject::connect(&dir_watcher, &DirWatcher::FolderAdded,[](const QString& path){qDebug()<<"folder added"<< path;});
    QObject::connect(&dir_watcher, &DirWatcher::FileRemoved,[](const QString& path){qDebug()<<"file removed"<< path;});
    QObject::connect(&dir_watcher, &DirWatcher::FolderRemoved,[](const QString& path){qDebug()<<"folder removed"<< path;});
    QObject::connect(&dir_watcher, &DirWatcher::FileRenamed,[](const QString& old_path, const QString& new_path){qDebug()<<"file renamed"<< old_path << "to" << new_path;;});
    QObject::connect(&dir_watcher, &DirWatcher::FolderRenamed,[](const QString& old_path, const QString& new_path){qDebug()<<"folder renamed"<< old_path << "to" << new_path;});

    dir_watcher.StartWatching();
    return a.exec();
}
