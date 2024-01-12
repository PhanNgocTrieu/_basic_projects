import QtQuick
import UICommon.CItems
import UICommon.Base
SettingDelegateTemplate{
    id: naviSettingDelegate
    property bool isOnlyNavigator: true
    property bool isArrowVisible: true
    property bool isEnabled: true
    textWidth: 872
    CImage {
        states:[
            State{
                when: naviSettingDelegate.disableActions
                PropertyChanges{target:arrow_right; source: UIConstants.arrow_right_inactive}
            },
            State{
                when: naviSettingDelegate.pressedState
                PropertyChanges{target:arrow_right; source: UIConstants.arrow_right_pressed}
            }
        ]
        id: arrow_right
        anchors.right: parent.right
        anchors.rightMargin: 16
        anchors.verticalCenter: parent.verticalCenter
        visible: isArrowVisible
        source: UIConstants.arrow_right_normal
    }
    onSettingApply:{
        if (setting != undefined){
            if (setting?.processor && setting.processor != undefined){
                prvController.moveToAnotherScreen = false
            }else{
                prvController.moveToAnotherScreen = true
            }

            if(typeof setting.isArrowVisible != "undefined"){
                isArrowVisible = Qt.binding(function() { return setting.isArrowVisible;})
            }
        }
    }

    QtObject{
        id: prvController
        property bool moveToAnotherScreen: true
    }
    enabled: isEnabled
    onReleased:{
        if (isOnlyNavigator){
            if (prvController.moveToAnotherScreen)
            {
                DelegateConstants._UI_COMMUNICATION.sendEvent(setting.eventID)
            }
            else
            {
                setting.processor(setting.settingType)
            }
        }
    }

}
