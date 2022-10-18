import QtQuick 2.15

// TESTO DELLE UNITA' DI MISURA POSIZIONATO NELLA PARTE BASSA DI OGNI CELLA
Text {
    color: "white"
    anchors.horizontalCenter: parent.horizontalCenter
    y: parent.height - 25
    style: Text.Outline
    styleColor: "black"
    font.pixelSize: 15
}
