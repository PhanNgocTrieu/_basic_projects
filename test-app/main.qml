import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: _panel
        width: 400
        height: 200
        color: "green"
        anchors.centerIn: parent

        Text {
            id: _panel_text
            anchors.centerIn: parent
            text: "Hello World"
            font {
                pixelSize: 40
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                _panel_text.text = "Clicked on me!"
            }
            onReleased: {
                _panel_text.text = "Hello World!"
            }
        }
    }

}
