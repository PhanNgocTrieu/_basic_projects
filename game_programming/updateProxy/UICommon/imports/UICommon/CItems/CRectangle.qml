import QtQuick
import QtQuick.Controls
import UICommon.Base

Rectangle {
    /*
        Apply the driving restriction on Rectangle
        When the car has the driving restriction, it would be faded
    */
    property bool isAppliedDrivingRestriction: false
    property bool isDriving: VehicleGeneralState.isDriving
    /*
        The condition that the item will not be faded (true condition)
    */
    property bool tonedownCondition: false

    /*
        The condition that the item will be enabled (true condition)
    */
    property bool disableCondition: false

    opacity: (isDriving || tonedownCondition) ? 0.5 : 1
    // enabled: (isDriving || disableCondition) ? false : true

    Component.onCompleted: {
        if (!isAppliedDrivingRestriction) isDriving = false
    }
}
