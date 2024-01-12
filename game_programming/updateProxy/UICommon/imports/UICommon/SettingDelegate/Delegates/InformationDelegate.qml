import QtQuick
import UICommon.CItems
import UICommon.Base
NavigateDelegate {
    id: informationDelegate
    property bool isSubInfoVisible  : true
    property string subInfoText     : ""

    onSettingApply  :{
        if (setting === undefined) { return; }

        if(typeof setting.subInfoText != "undefined"){
            informationDelegate.subInfoText = Qt.binding(function() { return setting.subInfoText;})
        }

        if(typeof setting.isSubInfoVisible != "undefined"){
            informationDelegate.isSubInfoVisible = Qt.binding(function() { return setting.isSubInfoVisible;})
        }
    }

    CText {
        id      : versionInfor
        text    : qsTrId(informationDelegate.subInfoText)
        visible : informationDelegate.isSubInfoVisible
        anchors{
            right       : parent.right
            rightMargin : informationDelegate.isArrowVisible ? 56 : 16
            verticalCenter: parent.verticalCenter
        }
        horizontalAlignment : Text.AlignRight
        verticalAlignment   : Text.AlignVCenter
        pressedState: informationDelegate.pressedState
        inActiveState: informationDelegate.disableActions
        _font               : CFont._SUBBODY
    }
}
