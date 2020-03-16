#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <QObject>
#include <QFileSystemModel>
#include <QModelIndex>

class FileSystem : public QObject
{
    Q_OBJECT
    QFileSystemModel* fileSystem;
public:
    FileSystem();
    Q_INVOKABLE QString getPath(QModelIndex index);


};

#endif // FILESYSTEM_H
