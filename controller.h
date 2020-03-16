#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QModelIndex>
#include <QFileSystemModel>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>

#include <QDirModel>

using namespace std;

class Controller : public QObject
{
    Q_OBJECT
private:
    QQmlApplicationEngine* engine;
    QFileSystemModel* fileSystem;

    void initFileSystem();
    void RegisterQML();

public:
    Controller(QQmlApplicationEngine* Engine,QObject* parent=nullptr);
    Q_INVOKABLE QString fileSelected(QModelIndex index);
    Q_INVOKABLE void setRootPathFileSystemPath(QString path);
signals:

};

#endif // CONTROLLER_H
