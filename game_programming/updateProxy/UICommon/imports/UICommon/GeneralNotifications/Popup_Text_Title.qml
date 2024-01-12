import UICommon.CItems
import UICommon.Base
import QtQuick 2.15
Popup_Text {
    id: popup
    source: UIConstants.popup_background_text_title[selectBackground(textLineCount, UIConstants.popup_background_text_title.length)]
    textTopMargin: 112
    property string title: ""
    property int titleTopMargin: 48
    CText {
        id: title
        anchors.top: parent.top
        anchors.topMargin: popup.titleTopMargin
        anchors.horizontalCenter: parent.horizontalCenter
        width: 688
        height: lineCount * 40
        text: qsTrId(popup.title)
        textID: popup.title
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        _font: CFont._BODY
        color: "#ffffff"
    }
}
