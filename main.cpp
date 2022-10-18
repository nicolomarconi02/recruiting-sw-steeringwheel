#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "data.hpp"
#include "backend.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Data generator
    Data *data = new Data(&app);
    BackEnd *backend = new BackEnd(&app);

    // You can received data using Qt Signals and Slots.
    // https://doc.qt.io/qt-5/signalsandslots.html

    // example:
    QObject::connect(data, SIGNAL(dataReceived(Data::Sensor, float)), backend, SLOT(ingestData(Data::Sensor,float)));

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/SteeringWheel/main.qml"_qs);
    QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
    engine.load(url);

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("_backend", backend);

    return app.exec();
}
