#include "log.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *ui = component.create();
    QObject *button = ui->findChild<QObject*>("saveButton");

    Log log;
    QObject::connect(button, SIGNAL(clicked()),
                         &log, SLOT(insertLog()));

    return app.exec();
}
