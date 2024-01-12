import QtQuick
import QtQuick.Controls
import UICommon.Base
import UICommon.Effects
ListView {
    id:listView
    /**
      * @brief To customize the usage of the scroll bar
      */
    property bool isUsedCustomizeScrollBar:true
    /**
      * @brief Apply driving restriction on the List view
      */
    property bool isAppliedDrivingRestriction:true
    /**
      * @brief When the driving restriction is set
      *        The scrollBar should not be displayed
      */
    property bool isScrollbarHidenWhenDriving: true
    /**
      * @brief To customize the usage of the bottom Fader
      */
    property bool isUsedFader: false
    property bool isScrollbarUsed: true
    signal startMovement()
    signal stopMovement()
    /**
     * @brief This property is used to limit the scroll Bar
     *        In case the total item's height and the list height
              is roughly the same
     */
    property bool isRequestLimitScrollBar: false

    property int rightOffset: -4
    property int rightMarginValue: 32
    property int leftMarginValue: 32
    property bool isPreventDrag: true
    property bool preventShowinFirstTime: false
    property int  paddingScrollBar      : 0
    property int  topPaddingScrollBar   : 0
    property bool isUsedOpacityMask: true
    onIsScrollbarUsedChanged: {
        scrollBar.visible = listView.isScrollbarUsed
    }
    layer.enabled: listView.isUsedOpacityMask
    layer.effect: OpacityMask{
        maskSource:
            CItem
        {
            width: listView.width
            height: listView.height
            CImage {
                id: fade_top
                width: listView.width
                height: 60
                anchors.top: parent.top
                source: UIConstants._FADER_TOP
            }
            CImage {
                id: fade_mid
                width: listView.width
                height: listView.height - 120
                anchors.top: fade_top.bottom
                source: UIConstants._FADER_MID
            }
            CImage {
                id: fade_bottom
                width: listView.width
                height: 60
                anchors.top:fade_mid.bottom
                source: UIConstants._FADER_BOTTOM
            }

            // This rectangle is to provide the alpha channel=1 for the scroll bar, so that it won't be blurred by the gradient.
            Rectangle{
                anchors.horizontalCenter: parent.right
                anchors.horizontalCenterOffset: listView.rightOffset
                y       : scrollBar.scrollBarY
                width   : scrollBar.scrollBarWidth
                height  : scrollBar.scrollBarHeight
                color   : "black"
                visible : scrollBar.scrollBarVisible
                radius  : scrollBar.scrollBarRadius
            }

            // This rectangle is to provide the alpha channel=1 to hide the upper fader when the listview is at the beginnign of the list
            Rectangle{
                visible: !privateVal.applyTopFading
                width: listView.width
                height: 60
                anchors.top: parent.top
                color: "black"
            }

            // This rectangle is to provide the alpha channel=1 to hide the bottom fader when the listview is at the end of the list
            Rectangle{
                visible: !privateVal.applyBotFading
                width: listView.width
                height: 60
                anchors.bottom: parent.bottom
                color: "black"
            }
        }
    }

    function visibleScrollBarClistView(check){
        scrollBar.visibleScrollBar(check)
    }
    CustomizedScrollBar{
        id                 : scrollBar
        topPadding         : topPaddingScrollBar
        bottomPadding      : paddingScrollBar
        rightOffset        : listView.rightOffset
        isHidenWhenDriving : listView.isScrollbarHidenWhenDriving
        enabled            : !VehicleGeneralState.isDriving && listView.isUsedCustomizeScrollBar
    }
    property bool interactiveCondition:true
    interactive: (!VehicleGeneralState.isDriving || !isAppliedDrivingRestriction) && interactiveCondition
    boundsBehavior: Flickable.StopAtBounds
    clip: false
    property int offSetFromBottom: 80
    property int offSetFromTop: 80
    property bool fadingActive: false
    property bool fadingAtYEnd: false

    QtObject{
        id: privateVal
        property double topPosition   : offSetFromTop / listView.height
        property double botPosition   : (listView.height - listView.offSetFromBottom ) / listView.height
        property bool applyTopFading  : !listView.atYBeginning && (listView.interactive || listView.fadingActive)
        property bool applyBotFading  : (!listView.atYEnd && (listView.interactive || listView.fadingActive)) || fadingAtYEnd
        function modifyListViewEffect(status){    // ScrollBar and Fader
            scrollBar.visible = status;
        }
    }
    // When the interactive status changes, Depending on the value of interactive
    // We accordingly enable or disable ScrollBar, fader
    onInteractiveChanged:{
        privateVal.modifyListViewEffect(interactive)
    }

    onMovementStarted: {
        listView.startMovement()
        if(preventShowinFirstTime)
        {
            //            preventShowinFirstTime = false
            isScrollbarUsed = true
        }
        if(isScrollbarUsed) scrollBar.visible = true
    }

    onMovementEnded: {
        listView.stopMovement()
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
      *        When listView object is dragging or moving, it steals the mouse or touch event
      *        from the child item underneath. To make the business logic (highlighting and releasing)
      *        be still the same, we use this map to propagate the release event when the flickable stops
      */
    property var userEventsTracking: []
	property var userEventsTracking1: []
//    onDraggingChanged: {
//        // When the list view stops dragging, propagate the release event to the already current item
//        if (dragging && listView.isPreventDrag){
//            // Needed to check the contentItem count
//            if (currentPressedIndex != -1){
//                userEventsTracking[currentPressedIndex](undefined)
//            }
//            if (currentPressedIndex1 != -1){
//                userEventsTracking1[currentPressedIndex1](undefined)
//            }
//        }
//    }
    Component.onCompleted: {
        scrollBar.visible = false
        if (isRequestLimitScrollBar){
            if (listView.contentHeight - 10 < listView.height){
                isScrollbarUsed = false;
                listView.interactive = false
                isUsedFader = false;
            }
        }
        if (isUsedCustomizeScrollBar)  ScrollBar.vertical = scrollBar
    }
}
