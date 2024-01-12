import QtQuick
import UICommon.Base
import UICommon.CItems
SettingDelegateTemplate{
    id: adjustDelegate
    textWidth: 416
    property int currentValue   : 0
    property string unitText: ""
    isEnableSound: false
    isObject: false
    disableUserEvent: false
    disableUserEventWhenInActive   : false
    disableHighLightWhenPressed    : true
    disableActions: ((currentIndexInSetting != -1 && currentIndexInSetting != index) || VehicleGeneralState.isDriving)
    onCurrentValueChanged: {
        valueIndicator.text         = (adjustDelegate.currentValue > 0 && adjustDelegate.plusEnable) ?  "+" + adjustDelegate.currentValue.toString() + adjustDelegate.unitText 
                                                                                        : adjustDelegate.currentValue.toString() + adjustDelegate.unitText
    }
    property int upperThreshold : 0
    property int lowerThreshold : 0
    property var processor      : undefined
    property bool plusEnable    : false
    property string extraInformationText: ""
    property alias extraInformationTextNewX: extraInformation.x
    property alias valueString: valueIndicator.text
    // signal increase(int val)
    // signal decrease(int val)
    signal modified(int val)
    QtObject{
        id: privateController
        property var processor
        function processValue(val){
            if (privateController.processor != undefined){
                privateController.processor(setting.settingType, val)
            }
        }
    }
    Component.onCompleted:{
        if (adjustDelegate?.processor){
            privateController.processor = adjustDelegate.processor
        }
        valueIndicator.text         = (adjustDelegate.currentValue > 0 && adjustDelegate.plusEnable) ?  "+" + adjustDelegate.currentValue.toString() + adjustDelegate.unitText 
                                                                                        : adjustDelegate.currentValue.toString() + adjustDelegate.unitText
    }
    onSettingApply:{
        if (setting != undefined){
            adjustDelegate.upperThreshold  = setting.upperThreshold
            adjustDelegate.lowerThreshold  = setting.lowerThreshold
            adjustDelegate.currentValue    = Qt.binding(function(){return setting.currentValue})
            valueIndicator.text = (adjustDelegate.currentValue > 0 && adjustDelegate.plusEnable) ?  "+" + adjustDelegate.currentValue.toString() + adjustDelegate.unitText 
                                                                                                    : adjustDelegate.currentValue.toString() + adjustDelegate.unitText
            extraInformation.text          = setting.extraInformation
            if (setting?.processor && setting.processor != undefined){
                privateController.processor = setting.processor
            }
        }
    }

    CText {
        id: extraInformation
        x: 416
        property int textId: -1
        Component.onCompleted:  {
            textId = adjustDelegate.addLineCountElement(lineCount, 32)
        }
        onLineCountChanged: adjustDelegate.calculationHeightElement(textId, lineCount)
        wrapMode: Text.Wrap
        anchors.verticalCenter: parent.verticalCenter
        inActiveState: adjustDelegate.disableActions
        inActiveTextColor: "#64646E"
        normalTextColor: "#FFFFFF"
        verticalAlignment   : Text.AlignVCenter
        horizontalAlignment : Text.AlignRight
        width: 160
        textID: extraInformationText
        textWidth: 160
        textHeight: 36
        text:qsTrId(extraInformationText)
        _font: CFont._SUBBODY
    }
    Item{
        id: adjust
        x: 608
        width: 320
        height: parent.height
        ImageButton{
            id: buttonMinus
            width: 80
            height: 80
            normalSource  : UIConstants.background_minus_normal_80x80
            pressedSource : UIConstants.background_minus_pressed_80x80
            inActiveSource: UIConstants.background_minus_inactive_80x80
            tonedownItem: ((adjustDelegate.currentValue == adjustDelegate.lowerThreshold) || adjustDelegate.disableActions)
            anchors.verticalCenter: parent.verticalCenter
            onReleased:{
                privateController.processValue(adjustDelegate.currentValue - 1)
                adjustDelegate.modified(adjustDelegate.currentValue -1 )
            }
        }
        CText {
            id: valueIndicator
            inActiveState: adjustDelegate.disableActions
            inActiveTextColor: "#64646E"
            normalTextColor: "#FFFFFF"
            width: 128
            height: 36
            verticalAlignment   : Text.AlignVCenter
            horizontalAlignment : Text.AlignHCenter
            anchors.centerIn: parent
            _font: CFont._SUBBODY
        }
        ImageButton{
            id: buttonPlus
            width: 80
            height: 80
            x: 240
            normalSource  : UIConstants.background_plus_normal_80x80
            pressedSource : UIConstants.background_plus_pressed_80x80
            inActiveSource: UIConstants.background_plus_inactive_80x80
            tonedownItem: ((adjustDelegate.currentValue == adjustDelegate.upperThreshold) || adjustDelegate.disableActions)
            anchors.verticalCenter: parent.verticalCenter
            onReleased:{
                privateController.processValue(adjustDelegate.currentValue + 1)
                adjustDelegate.modified(adjustDelegate.currentValue + 1)
            }
        }
    }

}
