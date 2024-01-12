import UICommon.CItems
import UICommon.Base
import QtQuick 2.15

Popup_Text_Button {
    id: popup
    source: UIConstants.popup_background_text_button_icon[selectBackground(textLineCount, UIConstants.popup_background_text_button_icon.length)]
    textTopMargin: 184
    property string sourceIcon: ""
    property int iconTopMargin: 40
    CImage {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: popup.iconTopMargin
        width: 120
        height: 120
        source: popup.sourceIcon
    }
}
