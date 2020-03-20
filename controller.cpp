#include "controller.h"
void Controller::initGenerators()
{
    // add any new generator in the same way
    this->generatorsAdapter.push_back(new AdapterPattern(new GPIO_Generator));
    this->generatorsAdapter.push_back(new AdapterPattern(new UART_Generator));
}


void Controller::initFileSystem()
{
    this->FileSystem = new QFileSystemModel;
    this->FileSystem->setRootPath("/home/amrelsersy/charts");
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
    this->initGenerators();
//    this->initTiva();
    this->tivaC["GPIO_A0"] = "Output";
    this->tivaC["GPIO_A1"] = "Output";
    this->tivaC["GPIO_A2"] = "Output";

    this->tivaC["GPIO_C4"] = "UART_RX";
    this->tivaC["GPIO_C5"] = "Input";
    this->tivaC["GPIO_C6"] = "Output";

    this->tivaC["UART_BaudRate"] = "1599";
    this->tivaC["UART_FIFO"] = "FIFO_DISABLE";
    this->tivaC["UART_HighSpeed"] = "HIGH_SPEED_ENABLE";
    this->tivaC["UART_ParityEnable"] = "PARITY_ENABLE";
    this->tivaC["UART_StopBits"] = "UART_STOPBITS_1";


    for(int i =0 ; i < this->generatorsAdapter.size();i++) {
        GeneratedCode y =  this->generatorsAdapter[i]->generateCode(this->tivaC);
        cout << "include" << y.includes << ", c:" << y.dot_c_Path << ", h:" << y.dot_h_Path << ", function:" << y.FunctionName << endl;
        for (int j = 0; j < y.code.size(); ++j)
            cout <<y.code[j] << endl;
    }

    emit addTab("ray2","int main {cout << ray2}");
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

bool Controller::saveFile(QString path, QString content)
{
    this->file.close();
    string Path = path.toStdString();
    // delete the "file://" comming from the FileDialog from QML
    Path.erase(0,7);
    path = QString::fromStdString(Path);

    if (!this->setFilePath(path))
    {
        cout << "not supported extention" << endl;
        return false;
    }
    this->file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!this->file.isOpen())
    {
        cout << "error write file path[" << path.toStdString() << "]" << endl;
        return false;
    }


    this->file.write(content.toLocal8Bit());
    //    QTextStream out( & this->file);
    //    out << content;


    cout << "content:" << content.toStdString() << endl;

    this->file.close();
    return true;
}


bool Controller:: readFile(QString path)
{
    if (!this->setFilePath(path))
    {
        cout << "not supported extention" << endl;
        return false;
    }
    this->file.close();
    cout << path.toStdString() << endl;
    if(!this->file.open(QIODevice::ReadOnly | QIODevice ::Text))    {
        cout << "error read file path[" << path.toStdString() << "]" << endl;
        return false;
    }

    QByteArray textByteArray = this->file.readAll();
    QString textString = QString ::fromStdString(textByteArray.toStdString() ) ;

    //    cout << textString.toStdString() << endl;
    this->textFileContent = textString;
    this->file.close();
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

void Controller::initTiva()
{
    string arr[6] = {"A","B","C","D","E"};
    for(int j =0 ; j< 5; j++)
        for(int i = 0 ; i<8; i ++)
        this->tivaC["GPIO_"+arr[j] + to_string(i)] = (i%2 == 0) ? "Output" : "Input";
    cout << "ray2";
}

void Controller::printTiva()
{

}
