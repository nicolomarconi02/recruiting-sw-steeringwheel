import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import QtQuick.Layouts
import io.qt.SteeringWheel.backend 1.0

// CREAZIONE FINESTRA
Window {
    id: finestra;
    width: 800
    height: 480
    visible: true
    title: qsTr("Steering Wheel")
    minimumWidth: finestra.width
    minimumHeight: finestra.height
    maximumWidth: finestra.width
    maximumHeight: finestra.height

    // IMPOSTAZIONE DEL BACKGROUND
    Background{ id: backgroundShape }

    GroupBox{
        width: 800; height: 480
        // CREAZIONE TABELLA CON TRE RIGHE E TRE COLONNE CHE OCCUPA L'INTERA FINESTRA
        GridLayout{
            id: screen
            rows: 3
            columns: 3
            flow: GridLayout.TopToBottom
            columnSpacing:0; rowSpacing: 0
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            width: 800; height: 480

            // CREAZIONE CELLA MOTORTEMP, POSIZIONE CELLA (0,0)
            TempBox{
                id: motorTemp
                width: screen.width/4; height: screen.height/3

                // BINDING DINAMICO PER CAMBIARE LO STATO DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO E' CAMBIATO,
                // ACCEDE AL VALORE E LO IMPOSTA
                state: _backend.stateMOTORTEMP

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: motorTempValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valueMOTORTEMP.toFixed(2)

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateMOTORTEMP === "criticalRedState" || _backend.stateMOTORTEMP === "criticalBlueState") ? "yellow" : "white"

                    // BINDING DINAMICO PER CAMBIARE LA SOTTOLINEATURA DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    font.underline: (_backend.stateMOTORTEMP === "criticalRedState" || _backend.stateMOTORTEMP === "criticalBlueState")
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: motorTempText
                    text: "MOTOR_TEMP"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateMOTORTEMP === "criticalRedState" || _backend.stateMOTORTEMP === "criticalBlueState") ? "yellow" : "white"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: motorTempCText
                    text: "°C"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateMOTORTEMP === "criticalRedState" || _backend.stateMOTORTEMP === "criticalBlueState") ? "yellow" : "white"
                }
            }

            // CREAZIONE CELLA BMS_LV_TEMP, POSIZIONE CELLA (1,0)
            TempBox{
                id: bmsLVTemp
                width: screen.width/4; height: screen.height/3

                // BINDING DINAMICO PER CAMBIARE LO STATO DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO E' CAMBIATO,
                // ACCEDE AL VALORE E LO IMPOSTA
                state: _backend.stateBMSLVTEMP

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: bmsLVTempValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valueBMSLVTEMP.toFixed(2)

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateBMSLVTEMP === "criticalRedState" || _backend.stateBMSLVTEMP === "criticalBlueState") ? "yellow" : "white"

                    // BINDING DINAMICO PER CAMBIARE LA SOTTOLINEATURA DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    font.underline: (_backend.stateBMSLVTEMP === "criticalRedState" || _backend.stateBMSLVTEMP === "criticalBlueState")
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: bmsLVTempText
                    text: "BMS_LV_TEMP"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateBMSLVTEMP === "criticalRedState" || _backend.stateBMSLVTEMP === "criticalBlueState") ? "yellow" : "white"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: bmsLVTempCText
                    text: "°C"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateBMSLVTEMP === "criticalRedState" || _backend.stateBMSLVTEMP === "criticalBlueState") ? "yellow" : "white"
                }
            }

            // CREAZIONE CELLA INVERTER_TEMP, POSIZIONE CELLA (2,0)
            TempBox{
                id: inverterTemp
                width: screen.width/4; height: screen.height/3

                // BINDING DINAMICO PER CAMBIARE LO STATO DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO E' CAMBIATO,
                // ACCEDE AL VALORE E LO IMPOSTA
                state: _backend.stateINVERTERTEMP

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: inverterTempValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valueINVERTERTEMP.toFixed(2)

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateINVERTERTEMP === "criticalRedState" || _backend.stateINVERTERTEMP === "criticalBlueState") ? "yellow" : "white"

                    // BINDING DINAMICO PER CAMBIARE LA SOTTOLINEATURA DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    font.underline: (_backend.stateINVERTERTEMP === "criticalRedState" || _backend.stateINVERTERTEMP === "criticalBlueState")
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: inverterTempText
                    text: "INVERTER_TEMP"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateINVERTERTEMP === "criticalRedState" || _backend.stateINVERTERTEMP === "criticalBlueState") ? "yellow" : "white"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: inverterTempCText
                    text: "°C"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateINVERTERTEMP === "criticalRedState" || _backend.stateINVERTERTEMP === "criticalBlueState") ? "yellow" : "white"
                }
            }

            // RIGA CHE CONTIENE I SENSORI SPEED E RPM, POSIZIONE (0,1)
            RowLayout{
                id: riga
                width: screen.width/2; height: screen.height/3
                spacing: 0

                // CREAZIONE CELLA SPEED
                Box{
                    id: speed
                    width: riga.width/2; height: riga.height

                    // TESTO DEL VALORE DEL SENSORE
                    MiddleText{
                        id: speedValue

                        // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                        // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A ZERO CIFRE DECIMALI
                        text: _backend.valueSPEED.toFixed(0)
                    }

                    // TESTO DEL NOME DEL SENSORE
                    TopText{
                        id: speedText
                        text: "SPEED"
                    }

                    // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                    BottomText{
                        id: speedKmhText
                        text: "Km/h"
                    }
                }

                // CREAZIONE CELLA RPM
                Box{
                    id: rpm
                    width: riga.width/2; height: riga.height

                    // TESTO DEL VALORE DEL SENSORE
                    MiddleText{
                        id: rpmValue

                        // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                        // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A ZERO CIFRE DECIMALI
                        text: _backend.valueRPM.toFixed(0)
                    }

                    // TESTO DEL NOME DEL SENSORE
                    TopText{
                        id: rpmText
                        text: "RPM"
                    }

                    // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                    BottomText{
                        id:rpmRPMText
                        text: "rpm"
                    }
                }
            }

            // CREAZIONE CELLA BMS_HV_VOLTAGE, POSIZIONE CELLA (1,1)
            Box{
                id: bmsHVVoltage
                width: screen.width/2; height: screen.height/3

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: bmsHVVoltageValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valueBMSHVVOLTAGE.toFixed(2)
                    font.pixelSize: 65
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: bmsHVVoltageText
                    text: "BMS_HV_VOLTAGE"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: bmsHVVoltageVText
                    text: "V"
                }
            }

            // CREAZIONE CELLA BMS_HV_VOLTAGE, POSIZIONE CELLA (2,1)
            TempBox{
                id: bmsHVTemp
                width: screen.width/2; height: screen.height/3

                // BINDING DINAMICO PER CAMBIARE LO STATO DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO E' CAMBIATO,
                // ACCEDE AL VALORE E LO IMPOSTA
                state: _backend.stateBMSHVTEMP

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: bmsHVTempValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valueBMSHVTEMP.toFixed(2)

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateBMSHVTEMP === "criticalRedState" || _backend.stateBMSHVTEMP === "criticalBlueState") ? "yellow" : "white"

                    // BINDING DINAMICO PER CAMBIARE LA SOTTOLINEATURA DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    font.underline: (_backend.stateBMSHVTEMP === "criticalRedState" || _backend.stateBMSHVTEMP === "criticalBlueState")
                    font.pixelSize: 65
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: bmsHVTempText
                    text: "BMS_HV_TEMP"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateBMSHVTEMP === "criticalRedState" || _backend.stateBMSHVTEMP === "criticalBlueState") ? "yellow" : "white"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: bmsHVTempCText
                    text: "°C"

                    // BINDING DINAMICO PER CAMBIARE IL COLORE DEL TESTO QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE LO STATO DEL SENSORE
                    // E' DIVENTATO CRITICO
                    color: (_backend.stateBMSHVTEMP === "criticalRedState" || _backend.stateBMSHVTEMP === "criticalBlueState") ? "yellow" : "white"
                }
            }

            // CREAZIONE CELLA POWER_LIMITER, POSIZIONE CELLA (0,2)
            Box{
                id: powerLimiter
                width: screen.width/4; height: screen.height/3

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: powerLimiterValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valuePOWERLIMITER.toFixed(0)
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: powerLimiterText
                    text: "POWER_LIMITER"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: powerLimiterPercentText
                    text: "%"
                }
            }

            // CREAZIONE CELLA BMS_LV_VOLTAGE, POSIZIONE CELLA (1,2)
            Box{
                id: bmsLVVoltage
                width: screen.width/4; height: screen.height/3

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: bmsLVVoltageValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valueBMSLVVOLTAGE.toFixed(2)
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: bmsLVVoltageText
                    text: "BMS_LV_VOLTAGE"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: bmsLVVoltageVText
                    text: "V"
                }
            }

            // CREAZIONE CELLA BMS_LV_CURRENT, POSIZIONE CELLA (2,2)
            Box{
                id: bmsLVCurrent
                width: screen.width/4; height: screen.height/3

                // TESTO DEL VALORE DEL SENSORE
                MiddleText{
                    id: bmsLVCurrentValue

                    // BINDING DINAMICO PER CAMBIARE IL VALORE DEL SENSORE QUANDO VIENE NOTIFICATO DAL FILE "backend.cpp" CHE IL VALORE E' CAMBIATO,
                    // ACCEDE AL VALORE E LO VISUALIZZA COME TESTO, FISSANDO IL VALORE A DUE CIFRE DECIMALI
                    text: _backend.valueBMSLVCURRENT.toFixed(2)
                }

                // TESTO DEL NOME DEL SENSORE
                TopText{
                    id: bmsLVCurrentText
                    text: "BMSLVCURRENT"
                }

                // TESTO DELL'UNITA' DI MISURA DEL VALORE DEL SENSORE
                BottomText{
                    id: bmsLVCurrentAText
                    text: "A"
                }
            }
        }
    }
}

