#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include "data.hpp"
#include <iostream>

class BackEnd : public QObject
{
    Q_OBJECT

    // LISTA PROPRIETA' PER CAMBIARE AUTOMATICAMENTE I VALORI DEI SENSORI NEL FILE QML
    Q_PROPERTY(float valueRPM READ valueRPM WRITE setValueRPM NOTIFY valueRPMChanged)
    Q_PROPERTY(float valueSPEED READ valueSPEED WRITE setValueSPEED NOTIFY valueSPEEDChanged)
    Q_PROPERTY(float valuePOWERLIMITER READ valuePOWERLIMITER WRITE setValuePOWERLIMITER NOTIFY valuePOWERLIMITERChanged)
    Q_PROPERTY(float valueBMSHVTEMP READ valueBMSHVTEMP WRITE setValueBMSHVTEMP NOTIFY valueBMSHVTEMPChanged)
    Q_PROPERTY(float valueBMSLVTEMP READ valueBMSLVTEMP WRITE setValueBMSLVTEMP NOTIFY valueBMSLVTEMPChanged)
    Q_PROPERTY(float valueINVERTERTEMP READ valueINVERTERTEMP WRITE setValueINVERTERTEMP NOTIFY valueINVERTERTEMPChanged)
    Q_PROPERTY(float valueMOTORTEMP READ valueMOTORTEMP WRITE setValueMOTORTEMP NOTIFY valueMOTORTEMPChanged)
    Q_PROPERTY(float valueBMSHVVOLTAGE READ valueBMSHVVOLTAGE WRITE setValueBMSHVVOLTAGE NOTIFY valueBMSHVVOLTAGEChanged)
    Q_PROPERTY(float valueBMSLVVOLTAGE READ valueBMSLVVOLTAGE WRITE setValueBMSLVVOLTAGE NOTIFY valueBMSLVVOLTAGEChanged)
    Q_PROPERTY(float valueBMSLVCURRENT READ valueBMSLVCURRENT WRITE setValueBMSLVCURRENT NOTIFY valueBMSLVCURRENTChanged)

    // LISTA PROPRIETA' PER CAMBIARE LO STATO DEI SENSORI DI TEMPERATURA NEL FILE QML
    Q_PROPERTY(QString stateMOTORTEMP READ stateMOTORTEMP WRITE setStateMOTORTEMP NOTIFY stateMOTORTEMPChanged)
    Q_PROPERTY(QString stateBMSHVTEMP READ stateBMSHVTEMP WRITE setStateBMSHVTEMP NOTIFY stateBMSHVTEMPChanged)
    Q_PROPERTY(QString stateBMSLVTEMP READ stateBMSLVTEMP WRITE setStateBMSLVTEMP NOTIFY stateBMSLVTEMPChanged)
    Q_PROPERTY(QString stateINVERTERTEMP READ stateINVERTERTEMP WRITE setStateINVERTERTEMP NOTIFY stateINVERTERTEMPChanged)

    QML_ELEMENT

public:
    explicit BackEnd(QObject *parent = nullptr);

    // DICHIARAZIONE FUNZIONI UTILIZZATE NEL FILE QML PER ACCEDERE AI VALORI DEI SENSORI
    float valueRPM();
    float valueSPEED();
    float valuePOWERLIMITER();
    float valueBMSHVTEMP();
    float valueBMSLVTEMP();
    float valueINVERTERTEMP();
    float valueMOTORTEMP();
    float valueBMSHVVOLTAGE();
    float valueBMSLVVOLTAGE();
    float valueBMSLVCURRENT();

    // DICHIARAZIONE FUNZIONI UTILIZZATE NEL FILE QML PER DEFINIRE LO STATO DEI SENSORI DI TEMPERATURA
    QString stateMOTORTEMP();
    QString stateBMSHVTEMP();
    QString stateBMSLVTEMP();
    QString stateINVERTERTEMP();

    // DICHIARAZIONE FUNZIONI UTILIZZATE NEL FILE "backend.h" PER IMPOSTARE I VALORI DEI SENSORI
    void setValueRPM(const float);
    void setValueSPEED(const float);
    void setValuePOWERLIMITER(const float);
    void setValueBMSHVTEMP(const float);
    void setValueBMSLVTEMP(const float);
    void setValueINVERTERTEMP(const float);
    void setValueMOTORTEMP(const float);
    void setValueBMSHVVOLTAGE(const float);
    void setValueBMSLVVOLTAGE(const float);
    void setValueBMSLVCURRENT(const float);

    // DICHIARAZIONE FUNZIONI UTILIZZATE NEL FILE "backend.cpp" PER IMPOSTARE LO STATO DEI SENSORI DI TEMPERATURA
    void setStateMOTORTEMP(const QString);
    void setStateBMSHVTEMP(const QString);
    void setStateBMSLVTEMP(const QString);
    void setStateINVERTERTEMP(const QString);

    // VARIABILI CHE MEMORIZZANO I VALORI DEI SENSORI
    float m_valueRPM = 0;
    float m_valueSPEED = 0;
    float m_valuePOWERLIMITER = 0;
    float m_valueBMSHVTEMP = 0;
    float m_valueBMSLVTEMP = 0;
    float m_valueINVERTERTEMP = 0;
    float m_valueMOTORTEMP = 0;
    float m_valueBMSHVVOLTAGE = 0;
    float m_valueBMSLVVOLTAGE = 0;
    float m_valueBMSLVCURRENT = 0;

    // VARIABILI CHE MEMORIZZANO GLI STATI DEI SENSORI DI TEMPERATURA
    QString m_stateMOTORTEMP = "blackState";
    QString m_stateBMSHVTEMP = "blackState";
    QString m_stateBMSLVTEMP = "blackState";
    QString m_stateINVERTERTEMP = "blackState";


signals:
    // SIGNALS UTILIZZATI PER NOTIFICARE AL FILE "main.qml" CHE I VALORI DEI SENSORI SONO STATI CAMBIATI
    void valueRPMChanged();
    void valueSPEEDChanged();
    void valuePOWERLIMITERChanged();
    void valueBMSHVTEMPChanged();
    void valueBMSLVTEMPChanged();
    void valueINVERTERTEMPChanged();
    void valueMOTORTEMPChanged();
    void valueBMSHVVOLTAGEChanged();
    void valueBMSLVVOLTAGEChanged();
    void valueBMSLVCURRENTChanged();

    // SIGNALS UTILIZZATI PER NOTIFICARE AL FILE "main.qml" CHE LO STATO DEI SENSORI DI TEMPERATURA E' STATO CAMBIATO
    void stateMOTORTEMPChanged();
    void stateBMSHVTEMPChanged();
    void stateBMSLVTEMPChanged();
    void stateINVERTERTEMPChanged();

public slots:

    // SLOT UTILIZZATO NEL FILE "main.cpp" PER CONNETTERE I VALORI GENERATI NEL FILE "data.hpp" CON IL BACKEND
    // IN BASE AL SENSORE CHE E' STATO MODIFICATO, VIENE CHIAMATA LA RELATIVA FUNZIONE PER IMPOSTARE I VALORI NELLE VARIABILI
    void ingestData(const Data::Sensor sensor,float value){
        switch (sensor) {
          case Data::RPM: setValueRPM(value); return;
          case Data::SPEED: setValueSPEED(value); return;
          case Data::POWER_LIMITER: setValuePOWERLIMITER(value); return;
          case Data::BMS_HV_TEMP: setValueBMSHVTEMP(value); return;
          case Data::BMS_LV_TEMP: setValueBMSLVTEMP(value); return;
          case Data::INVERTER_TEMP: setValueINVERTERTEMP(value); return;
          case Data::MOTOR_TEMP: setValueMOTORTEMP(value); return;
          case Data::BMS_HV_VOLTAGE: setValueBMSHVVOLTAGE(value); return;
          case Data::BMS_LV_VOLTAGE: setValueBMSLVVOLTAGE(value); return;
          case Data::BMS_LV_CURRENT: setValueBMSLVCURRENT(value); return;
          default: return;
        }
    }
};

#endif // BACKEND_H
