import QtQuick
import QtQuick.Controls
import UICommon.Base
import UICommon.Effects

Flickable {
    id:flickView
    property QtObject fader
    property int marginListView: 2
    property bool isCustomHidenFooterFader: false
    property bool customHidenFaderValue: false
    property int leftMarginOfFader: 0
    property int rightMarginOfFader: 0
    property int opacityMaskWidth           : flickView.width
    property int opacityMaskHeight          : flickView.height
    property bool isUsingFader              : true
    property bool enableFaderMask           : true
    property bool interactiveConditions     : true  
    property bool isUsingScrollBar          : false
    property bool isUsedCustomizeScrollBar  : false
    layer.enabled: true
    // layer.sourceRect: Qt.rect(0,0, 200, flickView.height)
    layer.effect: OpacityMask{
        maskSource:
        CImage
        {
            width: flickView.width
            height: flickView.height
            source: UIConstants._FADER

            // This rectangle is to provide the alpha channel=1 for the scroll bar, so that it won't be blurred by the gradient.
            Rectangle{
                width: 20
                height: flickView.height 
                anchors.right: parent.right
                anchors.top: parent.top
                color: "black"
            }

            // This rectangle is to provide the alpha channel=1 to hide the upper fader when the listview is at the beginnign of the list
            Rectangle{
                visible: !privateVal.applyUpperFading
                width: flickView.width
                height: 60
                anchors.top: parent.top
                color: "black"
            }

            // This rectangle is to provide the alpha channel=1 to hide the bottom fader when the listview is at the end of the list
            Rectangle{
                visible: !privateVal.applyFading
                width: flickView.width
                height: 60
                anchors.bottom: parent.bottom
                color: "black"
            }
        }
        
    }

    ScrollBar.vertical     : CustomizedScrollBar{
        id                 : scrollBar
        rightOffset        : -16
        isHidenWhenDriving : true
        enabled            : !VehicleGeneralState.isDriving && flickView.isUsedCustomizeScrollBar
        visible            : flickView.isUsedCustomizeScrollBar
        topPadding         : 16
        bottomPadding      : 16
    }

    interactive: !VehicleGeneralState.isDriving && interactiveConditions
    onInteractiveChanged:{
        Logger.logInf("Interactive state changed")
    }
    /**
      * @brief The current pressed item in list
      *        It is used for many cases such as releasing highlighted
      *        item when dragging or moving, showing what is already selected...
      */
    property int currentPressedIndex: -1
	property int currentPressedIndex1: -1
    /**
      * @brief Store the set of release signals for children's event handler
      *        When flickable object is dragging or moving, it steals the mouse or touch event
      *        from the child item underneath. To make the business logic (highlighting and releasing) 
      *        be still the same, we use this map to propagate the release event when the flickable stops
      */
    property var userEventsTracking: []
	property var userEventsTracking1: []
    onDraggingChanged: {
        // When the flick view stops dragging, propagate the release event to the already current item
        if (dragging){
            // Needed to check the contentItem count 
            if (currentPressedIndex != -1){
                userEventsTracking[currentPressedIndex](undefined)
            }
			if (currentPressedIndex1 != -1){
				userEventsTracking1[currentPressedIndex1](undefined)
			}
        }
    }

    property int offSetFromBottom: 45
    property int offSetFromTop: offSetFromBottom

    QtObject{
        id: privateVal
        property double position   : (flickView.height - flickView.offSetFromBottom ) / flickView.height
        property double fadeOutPosition: (flickView.height - 5 ) / flickView.height

        property double upperPosition   : flickView.offSetFromTop / flickView.height
        property double upperFadeOutPosition: 5 / flickView.height

        // property bool applyFading  : !flickView.atYEnd //&& flickView.interactive

        property bool applyFading       : !flickView.atYEnd  //&& flickView.interactive
        property bool applyUpperFading  : !flickView.atYBeginning   //&& flickView.interactive
        
    }

}
