import QtQuick
import UICommon.Base
import UICommon.CItems

CText {
    property string msg_text: "Message Text"
    property bool is_button: false
    property bool is_self_align: true
    property bool is_wrap_text : false
    text: qsTrId(msg_text)
    color: is_button ? UIConstants._POPUP_COLOR_GRAY : UIConstants._POPUP_COLOR_WHITE
    horizontalAlignment: is_self_align ? Text.AlignHCenter : undefined
    verticalAlignment: Text.AlignVCenter
    anchors.verticalCenter: parent.verticalCenter
    lineHeightMode: Text.FixedHeight
    _font: is_button? CFont._SUBBODY : CFont._BODY
    wrapMode: is_wrap_text ? Text.WordWrap : Text.NoWrap
}
