import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

GroupBox{
    width: 800; height: 480
    GridLayout{
        id: screen
        rows: 3
        columns: 3
        flow: GridLayout.TopToBottom
        columnSpacing:0; rowSpacing: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        TempBox{
            id: motorTemp
            MyText{
                text: "Motor_Temp"
            }
            width: screen.width/4; height: screen.height/3

        }
        TempBox{
            id: bmsLVTemp
            MyText{ text: "BMS_LV_TEMP" }
            width: screen.width/4; height: screen.height/3
        }
        TempBox{
            id: inverterTemp
            MyText{ text: "Inverter_Temp" }
            width: screen.width/4; height: screen.height/3
        }
        RowLayout{
            id: riga
            width: screen.width/2; height: screen.height/3
            spacing: 0
            SpeedBox{
                id: speed
                MyText{ text: "Speed" }
                width: riga.width/2; height: riga.height
            }
            RPMBox{
                id: rpm
                MyText{ text: "RPM" }
                width: riga.width/2; height: riga.height
            }
        }
        VoltageBox{
            id: bmsHVVoltage
            MyText{ text: "BMS_HV_VOLTAGE" }
            width: screen.width/2; height: screen.height/3
        }
        TempBox{
            id: bmsHVTemp
            MyText{ text: "BMS_HV_TEMP" }
            width: screen.width/2; height: screen.height/3
        }
        VoltageBox{
            id: powerLimiter
            MyText{ text: "POWER_LIMITER" }
            width: screen.width/4; height: screen.height/3
        }
        VoltageBox{
            id: bmsLVVoltage
            MyText{ text: "BMS_LV_VOLTAGE" }
            width: screen.width/4; height: screen.height/3
        }
        VoltageBox{
            id: bmsLVCurrent
            MyText{ text: "BMS_LV_CURRENT" }
            width: screen.width/4; height: screen.height/3
        }

    }
}
