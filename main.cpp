#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QFileSystemModel>
#include <QQmlContext>
#include "controller.h"
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    Controller* controller = new Controller(&engine);


    return app.exec();
}
