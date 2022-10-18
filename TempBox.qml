import QtQuick 2.15

// PROPRIETA' DELLE CELLE DEI SENSORI DI TEMPERATURA
Rectangle {
    id: box
    color: "black"
    border.color: "white"
    border.width: 2
    opacity: 30

    // DEFINIZIONE DEGLI STATI DEI SENSORI TEMPERATURA
    states: [

        // PRIMO STATO, CRITICO
        State {
            name: "criticalBlueState"
            PropertyChanges {
                target: box
                color: "blue"
                border{
                    color: "yellow"
                    width: 4
                }
            }
        },

        // SECONDO STATO, NORMALE
        State {
            name: "lightBlueState"
            PropertyChanges {
                target: box
                color: "mediumslateblue"
                border{
                    color: "white"
                    width: 2
                }
            }
        },

        // TERZO STATO, NORMALE
        State {
            name: "azureState"
            PropertyChanges {
                target: box
                color: "dodgerblue"
                border{
                    color: "white"
                    width: 2
                }
            }
        },

        // QUARTO STATO, NORMALE
        State{
            name: "greenBlueState"
            PropertyChanges {
                target: box
                color: "lightseagreen"
                border{
                    color: "white"
                    width: 2
                }
            }
        },

        // QUINTO STATO, CONDIZIONI OTTIMALI
        State {
            name: "blackState"
            PropertyChanges {
                target: box
                color: "black"
                border{
                    color: "white"
                    width: 2
                }
            }
        },

        // SESTO STATO, NORMALE
        State{
            name: "greenYellowState"
            PropertyChanges {
                target: box
                color: "#C1C400"
                border{
                    color: "white"
                    width: 2
                }
            }
        },

        // SETTIMO STATO, NORMALE
        State{
            name: "goldState"
            PropertyChanges {
                target: box
                color: "gold"
                border{
                    color: "white"
                    width: 2
                }
            }
        },

        // OTTAVO STATO, NORMALE
        State{
            name: "orangeState"
            PropertyChanges {
                target: box
                color: "orange"
                border{
                    color: "white"
                    width: 2
                }
            }
        },

        // NONO STATO, CRITICO
        State {
            name: "criticalRedState"
            PropertyChanges {
                target: box
                color: "red"
                border{
                    color: "yellow"
                    width: 4
                }
            }
        }
    ]
}
