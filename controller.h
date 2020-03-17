#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <bits/stdc++.h>
#include <QObject>
#include <QModelIndex>
#include <QFileSystemModel>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QByteArray>
#include <QTextStream>

using namespace std;

class Controller : public QObject
{
    Q_OBJECT
private:
    QQmlApplicationEngine* engine;
    QFileSystemModel* FileSystem;
    void initFileSystem();
    void RegisterQML();

    QFile file;
    QString textFileContent;
    vector<string> supportedExtentions;
    void initExtentions();
    bool readFile(QString);
    bool setFilePath(QString path);

public:
    Controller(QQmlApplicationEngine* Engine,QObject* parent=nullptr);
    Q_INVOKABLE QString getFileContent();
    Q_INVOKABLE QString getFileName();
    Q_INVOKABLE bool fileSelected(QModelIndex index);
    Q_INVOKABLE void setRootPathFileSystemPath(QString path);
    Q_INVOKABLE bool writeFile(QString path , QString content);
signals:

};

#endif // CONTROLLER_H
