import QtQuick
import QtQuick.Controls
import UICommon.Effects
import UICommon.Base
Image{
    id: battery
    property int batteryPercent: 50
    property double slope: 5.5
    property var sourecVehicle : UIConstants.default_vehicle_battery
    QtObject{
        id: privateVal
        property Canvas canVas
        property double beginPos:        battery.slope * 2
        property double step:            (battery.width - battery.slope * 2 * 2) / 100
        property double slopeEndHeight:  battery.height - 10
    }
    onBatteryPercentChanged: {
        if(privateVal.canVas != undefined){
            privateVal.canVas.requestPaint()
        }

    }
    source: battery.sourecVehicle
    anchors.centerIn: parent
    layer.enabled: true
    layer.effect: OpacityMask{
        maskSource:   Item{
            width:  battery.width
            height: battery.height
            Canvas{
                id: canVasId
                anchors.fill: parent
                onPaint: {
                    var context = getContext("2d");
                    context.reset()
                    let batteryPercent = battery.batteryPercent
                    if (batteryPercent >= 100) batteryPercent = 100
                    else if (batteryPercent <= 0) batteryPercent = 0
                    var topWidth    = privateVal.beginPos + batteryPercent * privateVal.step
                    var bottomWidth = topWidth + (batteryPercent - 50) * battery.slope / 25
                    // Draw the mask
                    context.beginPath();
                    context.moveTo(privateVal.beginPos,0)
                    context.lineTo(topWidth ,0)
                    context.lineTo(bottomWidth, privateVal.slopeEndHeight)
                    context.lineTo(bottomWidth, battery.height)
                    context.lineTo(0,battery.height)
                    context.lineTo(0,privateVal.slopeEndHeight)
                    context.closePath();
                    // the fill color
                    context.fillStyle = "#FFCC00"; // anycolor
                    context.fill();
                }
                Component.onCompleted:  privateVal.canVas = this
            }
        }
    }
}
