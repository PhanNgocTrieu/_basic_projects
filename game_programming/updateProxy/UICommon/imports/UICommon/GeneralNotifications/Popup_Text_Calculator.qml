import UICommon.CItems
import UICommon.Base
import QtQuick 2.15

Popup_Text {
    id: calculator
    source: UIConstants.popup_background_text_calculator[selectBackground(textLineCount, UIConstants.popup_background_text_calculator.length)]
    property int buttonBottomMargin: 48
    Image {
        id: icon
        width: 80
        height: 80
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 48
        anchors.horizontalCenter: parent.horizontalCenter
        source: UIConstants.calculator_80x80
        RotationAnimator {
            target: icon
            from: 0
            to: 360
            duration: 1000
            running: true
            loops: Animation.Infinite
        }
    }
}
