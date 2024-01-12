import QtQuick
import UICommon.Base
import UICommon.CItems

Item {
    width: 144
    height: 280
    id: adjustDate
    property int currentValue: -1
    property int upperThreshold : 12
    property int lowerThreshold : 0
    property bool isDriving: VehicleGeneralState.isDriving
    function padValue(value) {
        return (value < 10) ? ("0" + value) : value;
    }
    function getLastDayOfMonth(year, month) {
        var lastDayOfMonth = new Date(year, month, 0).getDate();
        return lastDayOfMonth;
    }
    onUpperThresholdChanged: {
        if(adjustDate.currentValue !== -1 && adjustDate.currentValue > upperThreshold) {
            adjustDate.currentValue = upperThreshold
        }
    }

    ModifyButton {
        id: adjustUp
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        normalSource: UIConstants.arrow_up_normal_80x80
        pressedSource: UIConstants.arrow_up_pressed_80x80
        inActiveSource: UIConstants.arrow_up_inactive_80x80
        tonedownItem: (adjustDate.currentValue >= adjustDate.upperThreshold)
        onAdjustDateChanged: {
            adjustDate.currentValue += 1
        }
    }

    CText {
        id: valueIndicator
        topPadding: 1
        anchors.centerIn: parent
        inActiveState: VehicleGeneralState.isDriving
        inActiveTextColor: "#64646E"
        normalTextColor: "#FFFFFF"
        width: 144
        height: 72
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: adjustDate.padValue(adjustDate.currentValue)
        _font: CFont._TITLE
    }

    ModifyButton {
        id: adjustDown
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        normalSource: UIConstants.arrow_down_Normal_80x80
        pressedSource: UIConstants.arrow_down_Pressed_80x80
        inActiveSource: UIConstants.arrow_down_inactive_80x80
        tonedownItem: (adjustDate.currentValue <= adjustDate.lowerThreshold)
        onAdjustDateChanged: {
            adjustDate.currentValue -= 1
        }
    }
    component ModifyButton: ImageButton {
        id: button
        width : 80
        height: 80
        signal adjustDateChanged()
        isConsumePressAndHold : true
        isDisablePressAndHoldEventWhenOutside: true
        property bool isPressAndHold: false
        onPressedStateChanged: {
            if (!pressedState) timer.stop()
        }
        onPressAndHold: {
            isPressAndHold = true
            timer.start()
        }
        onReleased: {
            timer.stop()
            if(!disableUserEvent && !isPressAndHold) {
                button.adjustDateChanged()
            }
            isPressAndHold = false
        }
        Timer {
            id: timer
            running: false
            repeat: true
            interval: 300
            onTriggered: {
                button.adjustDateChanged()
            }
        }
    }
}
