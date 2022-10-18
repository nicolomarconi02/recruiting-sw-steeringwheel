#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QRandomGenerator>
#include <QMetaEnum>

// if you want to add additional sensors feel free :)

class Data: public QObject {
    Q_OBJECT
public:
  enum Sensor {
    RPM,
    SPEED,
    POWER_LIMITER,
    BMS_HV_TEMP,
    BMS_LV_TEMP,
    INVERTER_TEMP,
    MOTOR_TEMP,
    BMS_HV_VOLTAGE,
    BMS_LV_VOLTAGE,
    BMS_LV_CURRENT,
    _SENSOR_SIZE
  };
  Q_ENUM(Sensor)

  Data(QObject *parent = nullptr) : QObject(parent) {
    _clock = new QTimer();
    _clock->setInterval(1000); // every second
    _clock->start();
    connect(_clock, &QTimer::timeout, this, &Data::generateData);
  }

  ~Data() {
    delete _clock;
  }

private slots:
  void generateData() {
    Sensor sensor = static_cast<Sensor>(QRandomGenerator::global()->generate() % Sensor::_SENSOR_SIZE);

    // GENERAZIONE AUTOMATICA DEI VALORI INIZIALI DI BMS_HV_VOLTAGE, BMS_LV_VOLTAGE E BMS_LV_CURRENT
    if(primaVolta){
        primaVolta = false;
        emit dataReceived(BMS_HV_VOLTAGE, 350.0f + QRandomGenerator::global()->bounded(110.0f));
        emit dataReceived(BMS_LV_VOLTAGE, 12.0f + QRandomGenerator::global()->bounded(6.0f));
        emit dataReceived(BMS_LV_CURRENT, QRandomGenerator::global()->bounded(30.0f));

        // PER TESTARE IL COMPORTAMENTO DEL POWER_LIMITER CON I PARAMETRI SPEED E RPM, TOGLIERE IL COMMENTO SULLA MODALITA' SCELTA
        //emit dataReceived(POWER_LIMITER, 0.0f);
        //emit dataReceived(POWER_LIMITER, 0.2f);
        //emit dataReceived(POWER_LIMITER, 0.4f);
        //emit dataReceived(POWER_LIMITER, 0.6f);
        //emit dataReceived(POWER_LIMITER, 0.8f);
        //emit dataReceived(POWER_LIMITER, 1.0f);
    }

    switch (sensor) {
      case RPM: emit dataReceived(sensor, QRandomGenerator::global()->bounded(15000.0f)); return;
      case SPEED: emit dataReceived(sensor, QRandomGenerator::global()->bounded(120.0f)); return;

        // IN FASE DI TESTING DEL COMPORTAMENTO DEL POWER_LIMITER, COMMENTARE LA RIGA SEGUENTE
      case POWER_LIMITER: emit dataReceived(sensor, QRandomGenerator::global()->bounded(6) * 0.2f); return;
        ////////

      case BMS_HV_TEMP: emit dataReceived(sensor, QRandomGenerator::global()->bounded(60.0f)); return;
      case BMS_LV_TEMP: emit dataReceived(sensor, QRandomGenerator::global()->bounded(70.0f)); return;
      case INVERTER_TEMP: emit dataReceived(sensor, QRandomGenerator::global()->bounded(90.0f)); return;
      case MOTOR_TEMP: emit dataReceived(sensor, QRandomGenerator::global()->bounded(110.0f)); return;
      case BMS_HV_VOLTAGE: emit dataReceived(sensor, 350.0f + QRandomGenerator::global()->bounded(110.0f)); return;
      case BMS_LV_VOLTAGE: emit dataReceived(sensor, 12.0f + QRandomGenerator::global()->bounded(6.0f)); return;
      case BMS_LV_CURRENT: emit dataReceived(sensor, QRandomGenerator::global()->bounded(30.0f)); return;
      default: return;
    }
  };

signals:
  void dataReceived(Data::Sensor sensor, float data);

private:
  QTimer *_clock;
  bool primaVolta = true;
};

#endif // DATA_H
