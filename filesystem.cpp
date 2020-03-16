#include "filesystem.h"

FileSystem::FileSystem()  : QObject()
{
    this->fileSystem = new QFileSystemModel();
    this->fileSystem->setRootPath(QDir::homePath());
    this->fileSystem->setResolveSymlinks(true);



}

QString FileSystem::getPath(QModelIndex index)
{
    return this->fileSystem->filePath(index);
}
