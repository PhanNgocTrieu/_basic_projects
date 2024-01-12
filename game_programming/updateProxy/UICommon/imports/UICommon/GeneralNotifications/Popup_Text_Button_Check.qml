import UICommon.CItems
import UICommon.Base
import UICommon.Effects
import QtQuick 2.15
Popup_Text_Button {
    id: rootItem
    property string textRadio: ""
    property alias isSelected: indicator.isSelected
    buttonBottomMargin: 144
    textTopMargin: textLineCount ? 68 : 48
    source: UIConstants.popup_background_text_button_Check[selectBackground(textLineCount, UIConstants.popup_background_text_button_Check.length)]
    CMouseArea {
        id: mouseItem
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenter: parent.horizontalCenter
        width: textIndicator.width + 32
        height: 80
        isObject: false
        onReleased: {
            indicator.isSelected = !indicator.isSelected
        }
        CItem {
            id: textIndicator
            y: 16
            anchors.horizontalCenter: parent.horizontalCenter
            width : (notDisplayNextTime.contentWidth + 74)
            height: 48
            RadioIndicator {
                id: indicator
            }
            CText {
                id:notDisplayNextTime
                x     : 56
                y     : 6
                height: 36
                text  : qsTrId(rootItem.textRadio)
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                _font: CFont._SUBBODY
            }

            BlurShadow {
                source : notDisplayNextTime
                width  : notDisplayNextTime.width
                height : notDisplayNextTime.height
                visible: (mouseItem.pressed && mouseItem.isValidEvent)
                x      : notDisplayNextTime.x
                y      : notDisplayNextTime.y
            }
        }
    }
}
