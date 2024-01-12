import QtQuick
import QtQuick.Controls
import UICommon.CItems
import UICommon.Base
SettingDelegateTemplate{
    id: toggleSettingDelegate
    textWidth: 808
    property bool enableInnerSwitch : true
    property bool status  : false
    property bool enableDrivingRestriction : true
    property bool tonedownToggle : false
    onSettingApply:{
        if (setting){
            status = Qt.binding(function() {return setting.status})
            if(toggleSettingDelegate.visible) {
                control.enableAnimation = true
                control.enableAnimationOnSwitch()
            } else {
                privateController.isEnableAnimationNextTime = true
 
            }
        }
    }
 
    onVisibleChanged: {
        if(toggleSettingDelegate.visible && privateController.isEnableAnimationNextTime) {
            privateController.isEnableAnimationNextTime = false
            control.enableAnimation = true
            control.enableAnimationOnSwitch()
        }
    }
 
    onReleased:{
        // If the processor is differ from undefined, that means the processor
        // has been applied. Thus no need of exposing handling to outside world
        if (setting?.processor && setting.processor != undefined){
            if(!toggleSettingDelegate.tonedownToggle) {setting.processor(setting.settingType, !status)}
        }
    }
    CSwitch{
        id : control
        z: tonedownToggle ? 1 : -1
        checked: toggleSettingDelegate.status
        width: 80
        indicatorWidth: 80
        indicatorHeight:44
        sizeIndicator:  38
        indicatorRadius:25
        enableAnimation: privateController.enabledAnimation
        enabled : toggleSettingDelegate.enableInnerSwitch
        isToggle: true
        toneDownCondition: toggleSettingDelegate.disableActions || toggleSettingDelegate.tonedownToggle
        enableDrivingRestriction : toggleSettingDelegate.enableDrivingRestriction
        leftPadding: 0
        anchors {
            right: parent.right
            rightMargin: 20
            verticalCenter: parent.verticalCenter
        }
 
    }
    QtObject{
        id: privateController
        property bool enabledAnimation: (typeof _IN_LIST_SETTING == "undefined")
        property bool isEnableAnimationNextTime: false
    }
}
