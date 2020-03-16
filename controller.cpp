#include "controller.h"

void Controller::initFileSystem()
{
    this->fileSystem = new QFileSystemModel;
    this->fileSystem->setRootPath("/home/amrelsersy");
    this->fileSystem->setResolveSymlinks(true);

}

void Controller::RegisterQML()
{
    engine->rootContext()->setContextProperty("Controller", this);
    engine->rootContext()->setContextProperty("fileSystemModel", this->fileSystem);
}

Controller::Controller(QQmlApplicationEngine* Engine,QObject* parent) : QObject(parent)
{
    this->engine = Engine;

    this->initFileSystem();
    this->RegisterQML();
}

QString Controller::fileSelected(QModelIndex index)
{
    QString path = this->fileSystem->filePath(index);
    cout << path.toStdString() << endl;
    return path;
}

void Controller::setRootPathFileSystemPath(QString path)
{
    this->fileSystem->setRootPath(path);
}
