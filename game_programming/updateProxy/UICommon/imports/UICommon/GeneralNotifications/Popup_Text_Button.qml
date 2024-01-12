import UICommon.CItems
import UICommon.Base
import UICommon.Effects
import QtQuick 2.15

Popup_Text {
    id: button
    source: UIConstants.popup_background_text_button[selectBackground(textLineCount, UIConstants.popup_background_text_button.length)]
    property int buttonBottomMargin: 40
    property string textButton1: ""
    property string textButton2: ""
    signal releasedButton1()
    signal releasedButton2()
    property bool isUsedRedButton: false
    property bool isButtonWidth480: false
    property alias textButton1ID: button1.textID
    property alias textButton2ID: button2.textID

    property alias turnDownButton1: button1.tonedownItem
    property alias turnDownButton2: button2.tonedownItem
    
    property alias iconDelegate1: button1.iconDelegate

    Component.onCompleted: {
        if(button.textButton2 != ""){
            button2.visible = true
        }
    }

    CItem {
        width: 496
        height: 80
        anchors.bottom: parent.bottom
        anchors.bottomMargin: button.buttonBottomMargin
        anchors.horizontalCenter: parent.horizontalCenter
        CRow {
            spacing: 16
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            ImageButton {
                id: button1
                width: (!isButtonWidth480)? 240 : 480
                height: 80
                normalSource: (!isButtonWidth480)? (button.isUsedRedButton ? UIConstants.button_red_240x80 : UIConstants.button_normal_240x80) : UIConstants.button_normal_480x80
                pressedSource: (!isButtonWidth480)? UIConstants.button_pressed_240x80 : UIConstants.button_pressed_480x80
                inActiveSource: (!isButtonWidth480)? UIConstants.button_inActive_240x80 : UIConstants.button_inActive_480x80
                textButton: button.textButton1
                isObject: false
                onReleased: {
                    button.releasedButton1()
                }
            }
            ImageButton {
                id: button2
                width: 240
                height: 80
                visible: false
                normalSource: UIConstants.button_normal_240x80
                pressedSource: UIConstants.button_pressed_240x80
                inActiveSource: UIConstants.button_inActive_240x80
                textButton: button.textButton2
                isObject: false
                onReleased: {
                    button.releasedButton2()
                }
            }
        }
    }
}
