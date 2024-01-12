import UICommon.CItems
import UICommon.Base
import QtQuick 2.15

PopupBase {
    id: popupText
    readonly property alias textLineCount: textPopup.lineCount
    source: UIConstants.popup_background_text[selectBackground(textLineCount, UIConstants.popup_background_text.length)]
    property string text: ""
    property int textTopMargin: 48
    property alias textID: textPopup.textID
    property bool isMouseMask: false

    function selectBackground(lineCount, lenght){
        let ret = 0
        if(lineCount >=0 && lineCount <= lenght) {
            ret = lineCount - 1
        } else {
            ret = lenght - 1
        }
        return ret
    }

    function removeEmptyLine(text) {
        var regex = /^[\s\r\n]*|[\s\r\n]*$/g;
        return text.replace(regex, '');
    }

    MouseArea{
        anchors.fill: parent
        enabled: popupText.isMouseMask
    }

    CText {
        id: textPopup
        anchors.top: parent.top
        anchors.topMargin: popupText.textTopMargin
        anchors.horizontalCenter: parent.horizontalCenter
        width: 688
        height: lineCount * 40
        text: removeEmptyLine(qsTrId(popupText.text))
        textID: popupText.text
        wrapMode: Text.Wrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        _font: CFont._BODY
        color: "#ffffff"
    }
}
