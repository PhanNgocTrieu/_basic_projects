import QtQuick
import UICommon.CItems
CItem{
    id: container
    parent: typeof DelegateConstants._ROOT_ITEM == "object" ? DelegateConstants._ROOT_ITEM : undefined
    anchors.fill: parent
    CImage{
        x: 136
        y: 80
        width: 1008
        height: 624
        source: "qrc:/qt-project.org/imports/UICommon/CItems/MaskPopup.png"
        CMouseArea{
            anchors.fill: parent
            isEnableSound: false
        }
    }
    signal accept()
    signal reject()
    CImage{
        anchors.centerIn: parent
        source:"qrc:/IMG_RESOURCES/DrivingAssistanceIcon/background_popup.png"
        CText {
            id: txt
            color: "white"
            text: qsTrId(title)

            font{
                weight: 275
                family: "Suzuki_IF TazuganeInfo"
                pixelSize: 28
            }
            horizontalAlignment: Text.AlignHCenter
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 388/2
            }
        }
        Confirm_Button{
            id : okButton
            x: 144
            indicator: "はい"//qsTrId(STRING.SDS13_POPUP_TURN_OFF_OK)
            onReleased: container.accept()
        }
        Confirm_Button{
            id: cancelButton
            x: 144 + 256
            indicator: "キャンセル"//qsTrId(STRING.SDS13_POPUP_TURN_OFF_CANCEL)
            onReleased: container.reject()
        }
        component Confirm_Button: ButtonWidget{
            id: button
            normalColor     : "#2D2D37"
            pressedColor    : "grey"
            sizeIndicator   : 26
            buttonOnlyIcon  : false
            width           : 240
            height          : 50
            typeOfButton    : 1
            radius          : 6
            y               : 388
            normalTextColor : "#D2D2D2"
            pressedTextColor: "white"
        }
    }

    property string title //STRING.SDS_13_POPUP
    Binding{
        target  : DelegateConstants._ROOT_ITEM
        property: "maskBackgroundPopup"
        value   : container.visible
    }
}
