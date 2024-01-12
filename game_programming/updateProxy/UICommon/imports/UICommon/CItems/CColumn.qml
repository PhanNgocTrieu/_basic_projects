import QtQuick 
import UICommon.Base
Column {
    /*
        Apply the driving restriction on Item
        When the car has the driving restriction, it would be faded
    */
    property bool isAppliedDrivingRestriction:false
    QtObject{
        id: privateVal
        property bool isDriving: VehicleGeneralState.isDriving
    }
    /*
        The condition that the item will not be faded (true condition)
    */
    property bool tonedownCondition:false
    opacity: privateVal.isDriving || tonedownCondition ? 0.5 : 1
    Component.onCompleted: {
        if (!isAppliedDrivingRestriction) privateVal.isDriving = false
    }

}
