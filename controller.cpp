#include "controller.h"

void Controller::initFileSystem()
{
    this->FileSystem = new QFileSystemModel;
    this->FileSystem->setRootPath("/home/amrelsersy");
}

void Controller::RegisterQML()
{
    engine->rootContext()->setContextProperty("Controller", this);
    engine->rootContext()->setContextProperty("fileSystemModel", this->FileSystem);
}

void Controller::initExtentions()
{
    this->supportedExtentions.push_back(".txt");
    this->supportedExtentions.push_back(".cpp");
    this->supportedExtentions.push_back(".c");
    this->supportedExtentions.push_back(".h");
}


Controller::Controller(QQmlApplicationEngine* Engine,QObject* parent) : QObject(parent)
{
    this->engine = Engine;

    this->initFileSystem();
    this->initExtentions();
    this->RegisterQML();
}

bool Controller::fileSelected(QModelIndex index)
{
    QString path = this->FileSystem->filePath(index);
    if(this->readFile(path))
        return true;
    return false;
}

void Controller::setRootPathFileSystemPath(QString path)
{
    this->FileSystem->setRootPath(path);
}

bool Controller::writeFile(QString path, QString content)
{
    if (!this->setFilePath(path))
    {
        cout << "not supported extention" << endl;
        return false;
    }

    if(!this->file.open(QIODevice::ReadOnly | QIODevice ::Text))    {
        cout << "error open file path[" << path.toStdString() << "]" << endl;
        return false;
    }

    QTextStream out( & this->file);
    out << content;
    return true;
}


bool Controller:: readFile(QString path)
{
    if (!this->setFilePath(path))
    {
        cout << "not supported extention" << endl;
        return false;
    }

    if(!this->file.open(QIODevice::ReadOnly | QIODevice ::Text))    {
        cout << "error open file path[" << path.toStdString() << "]" << endl;
        return false;
    }

    QByteArray textByteArray = this->file.readAll();
    QString textString = QString ::fromStdString(textByteArray.toStdString() ) ;

//    cout << textString.toStdString() << endl;
    this->textFileContent = textString;
    return true;

}

bool Controller::setFilePath(QString  path)
{
    string Path = path.toStdString();
    bool Supported = false;

    // iterate over supported extentions & find out if there is any of them supported
    for (int i =0 ; i < this->supportedExtentions.size(); i ++)
    {
        int pos = Path.find(this->supportedExtentions[i]);
        // we don't care which is supported, we pass it to the file and it will handle it
        if (pos != string::npos)
            Supported = true;
    }
    if( ! Supported)
        return false;

    this->file.setFileName(path);
//    cout << "supported extention!" << endl;
    return true;
}

QString Controller::getFileContent()
{
    return this->textFileContent;
}

QString Controller::getFileName()
{
    string path = this->file.fileName().toStdString();
    // find the last / for finding the last file name
    int pos = path.find_last_of("/");
    // check for not found
    if(pos == string :: npos)
        return "error";
    // substring from pos to last index
    string fileName = path.substr(pos);
    fileName.erase(0,1);
    return QString::fromStdString(fileName);
}
