#include "controller.h"

void Controller::initFileSystem()
{
    this->FileSystem = new QFileSystemModel;
    this->FileSystem->setRootPath("/home/amrelsersy");
//    this->FileSystem->setOption(QFileSystemModel::DontUseCustomDirectoryIcons);
//    this->FileSystem->setData(this->FileSystem->index("/"),Qt::UserRole + 1,QFileSystemModel::FilePathRole	);

    QIcon ray2 = this->FileSystem->fileIcon(this->FileSystem->index("/home/amrelsersy"));
    QPushButton* btn = new QPushButton;
    btn->setIcon(ray2);
//    btn->show();

}

void Controller::RegisterQML()
{
    engine->rootContext()->setContextProperty("Controller", this);
    engine->rootContext()->setContextProperty("fileSystemModel", this->FileSystem);
}

Controller::Controller(QQmlApplicationEngine* Engine,QObject* parent) : QObject(parent)
{
    this->engine = Engine;

    this->initFileSystem();
    this->RegisterQML();
}

QString Controller::fileSelected(QModelIndex index)
{
    QString path = this->FileSystem->filePath(index);
    cout << path.toStdString() << endl;
    return path;
}

void Controller::setRootPathFileSystemPath(QString path)
{
    this->FileSystem->setRootPath(path);
}
