import QtQuick
import QtQuick.Controls
import UICommon.Base

Item {
    id: rootItem
    property bool status: true
    property string pathImage: "qrc:/qt-project.org/imports/UICommon/Resources/imports/UICommon/Resources/"
    signal clicked()

    width:CConstants.toggle_small_width
    height:CConstants.toggle_small_height

    states: [
        State {
            name: "on"
            when: (rootItem.status === true)
            PropertyChanges {
                target: ellipseItem
                y:(CConstants.toggle_small_height-CConstants.toggle_small_ellipse_width)/2
                x:CConstants.toggle_small_width - CConstants.toggle_small_ellipse_width - y
            }
            PropertyChanges {
                target: onBkgrndItem
                visible: true
            }
            PropertyChanges {
                target: offBkgrndItem
                visible: false
            }
        },
        State {
            name: "off"
            when: (rootItem.status === false)
            PropertyChanges {
                target: ellipseItem
                y:(CConstants.toggle_small_height-CConstants.toggle_small_ellipse_width)/2
                x:y+1
            }
            PropertyChanges {
                target: onBkgrndItem
                visible: false
            }
            PropertyChanges {
                target: offBkgrndItem
                visible: true
            }
        }
    ]

    transitions: [
        Transition {
            id: animationCtrl
            enabled: false
            NumberAnimation { properties: "x"; easing.type: Easing.InOutQuad }
        }
    ]

    Rectangle {
        id:onBkgrndItem
        anchors.fill: parent
        radius: CConstants.toggle_small_border_radius
//        gradient: Gradient {
//            orientation: Gradient.Horizontal
//            GradientStop { position: 0; color: CConstants.toggle_small_on_background_color1 }
//            GradientStop { position: 1; color: CConstants.toggle_small_on_background_color2 }
//        }
        color: "transparent"
        Image {
            id: onBgItem
            source: pathImage + "Background_Toggle_ON_Normal.png"
        }
        visible: false
    }

    Rectangle {
        id:offBkgrndItem
        anchors.fill: parent
        radius: CConstants.toggle_small_border_radius
//        gradient: Gradient {
//            orientation: Gradient.Horizontal
//            GradientStop { position: 0; color: CConstants.toggle_small_off_background_color1 }
//            GradientStop { position: 1; color: CConstants.toggle_small_off_background_color2 }
//        }
        color: "transparent"
        Image {
            id: offBgItem
            source: pathImage + "Background_Toggle_OFF_Normal.png"
        }
    }

    Rectangle {
        id:ellipseItem
        y:(CConstants.toggle_small_height-CConstants.toggle_small_ellipse_width)/2
        x:y+1
        width: CConstants.toggle_small_ellipse_width
        height: CConstants.toggle_small_ellipse_width
        radius: CConstants.toggle_small_ellipse_radius
        //color: CConstants.toggle_small_ellipse_color
        color: "transparent"
        Image {
            id: ellipseImage
            x: rootItem.status ? -4 : -5
            source: pathImage + "Circle_Normal.png"
        }
    }

    MouseArea {
        id: touchCtrItem
        anchors.fill: parent
        enabled: rootItem.enabled
        onClicked: {
            rootItem.clicked();
        }
    }

    Component.onCompleted: {
        animationCtrl.enabled = true;
    }
}


