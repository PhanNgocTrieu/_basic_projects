import QtQuick
import QtQuick.Controls
import UICommon.Effects
import UICommon.Base
import SettingBattery 1.0
Image{
    id: battery
    property int batteryPercent: 70
    property int topValue: 40
    property int bottomValue: 50
    property double slope: 5.5
    property var sourecVehicle : UIConstants.default_vehicle_battery

    QtObject{
        id: privateVal
        property double beginPos:        battery.slope * 2
        property double step:            (battery.width - battery.slope * 2 * 2) / 100
        property double slopeEndHeight:  battery.height - 10
    }
    function calculate(){
        let batteryPercentcal = battery.batteryPercent
        if (batteryPercentcal >= 100) batteryPercentcal = 100
        else if (batteryPercentcal <= 0) batteryPercentcal = 0
        var topWidth    = privateVal.beginPos + batteryPercentcal * privateVal.step
        var bottomWidth = topWidth + (batteryPercentcal - 50) * battery.slope / 25
        battery.topValue = topWidth
        battery.bottomValue = bottomWidth
    }
    onBatteryPercentChanged: calculate()
    Component.onCompleted: calculate()

    source: battery.sourecVehicle
    anchors.centerIn: parent
    layer.enabled: true
    layer.effect: OpacityMask{
        maskSource:   Item{
            width:  battery.width
            height: battery.height
            SettingBatteries {
                height: parent.height
                width: parent.width
                topWidth: battery.topValue
                bottomWidth: battery.bottomValue
                heightBattery: battery.height
                beginPos: privateVal.beginPos
                slopeEndHeight: privateVal.slopeEndHeight
            }
        }
    }
}
