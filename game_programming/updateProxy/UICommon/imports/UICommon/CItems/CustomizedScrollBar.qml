import QtQuick
import QtQuick.Controls
import UICommon.Base
ScrollBar{
    id:topMostItem
    width:1
    property bool isHidenWhenDriving: true
    property int rightOffset: -4
    visible: !(VehicleGeneralState.isDriving && topMostItem.isHidenWhenDriving)
    interactive: innerItem.visible && !VehicleGeneralState.isDriving
    anchors.horizontalCenter: parent.right
    anchors.horizontalCenterOffset: rightOffset
    // topPadding: -2
    topPadding: 0
    bottomPadding: 0
    property var invisibleScrollBarTimer:invisibleScrollBar
    property var dragFetchFromparent
    property var contentYFetchFromParent
    property bool expandSize:(innerItem.width===8)
    property int parentHeight:parent.height
    property real initialSize:1-topMostItem.size
    property bool enableScrolling:false
    property bool disableMoving:false
    property real storedPos:-1
    property int roundValue
    
    property bool isStopAtBound: false


    property real heightOfContentItem
    
    
    property alias scrollBarVisible : innerItem.visible
    property alias scrollBarWidth   : innerItem.width
    property alias scrollBarHeight  : innerItem.height
    property alias scrollBarRadius  : innerItem.radius
    property alias scrollBarY       : parentItem.y
    property alias scrollBarX       : parentItem.x

    //
    property var contentHeightFetchFromParent
    Component.onCompleted: {
        dragFetchFromparent             = Qt.binding(function(){return parent.dragging});
        contentYFetchFromParent         = Qt.binding(function(){return parent.contentY});
        contentHeightFetchFromParent    = Qt.binding(function(){return parent.contentHeight})
    }
    onDragFetchFromparentChanged: if (!dragFetchFromparent) invisibleScrollBarTimer.start();
    onContentYFetchFromParentChanged:  {
        if (contentYFetchFromParent===roundValue) return;
        if (!innerItem.visible) innerItem.visible = true;
        if (!expandSize&&!dragFetchFromparent) invisibleScrollBarTimer.start();
        if (checkPressAndHold.running) checkPressAndHold.stop();
        roundValue = Math.round(contentYFetchFromParent)
    }
    // onPressedChanged: {
    //     if (pressed){
    //         checkPressAndHold.start();
    //         invisibleScrollBarTimer.stop();
    //     }else{
    //         topMostItem.revertSizeOfScrollBar();
    //         checkPressAndHold.stop();
    //         invisibleScrollBarTimer.start();
    //     }
    // }
    onPositionChanged: {
        if (disableMoving){
            position = storedPos;
            disableMoving = false;
        }
        if (topMostItem.pressed) {
            topMostItem.pressed = false;
            topMostItem.interactive = false;
            enableInteractive.start();
            storedPos = topMostItem.position;
            disableMoving = true;
        }

        if (topMostItem.isStopAtBound)
        {
            if (topMostItem.position <= 0.0)
            {
                topMostItem.position = 0.0;
            }

            if (topMostItem.position >= ((contentHeightFetchFromParent - topMostItem.height) / contentHeightFetchFromParent))
            {
                topMostItem.position = ((contentHeightFetchFromParent - topMostItem.height) / contentHeightFetchFromParent);
            }
        }
        invisibleScrollBarTimer.restart()
    }
    // MouseArea{
    //     anchors.fill:parent
    //     visible:!innerItem.visible
    //     preventStealing: true
    // }
    contentItem:Item{
        id:parentItem
        Rectangle{
            id:innerItem
            visible: false
            onVisibleChanged: {
                topMostItem.widthScrollBar()
            }
            width:2
            height:parentItem.height
            radius:0
            anchors.horizontalCenter: parent.horizontalCenter
            color:"white"
            onHeightChanged:{
                topMostItem.heightOfContentItem = height
            }
        }
        MouseArea{
            id:topMostMouseAreaToDetectRangeOfEnableExpandSize
            anchors{
                fill:parent
                topMargin: -40
                bottomMargin: -40
            }
            preventStealing: true
            hoverEnabled: true
            property real initialPos:-1
            property real stepSizeOfMoving:0
            property bool movingBackward:false
            property bool movingForward:false
            onPressed: (mouse)=>{
                            // Logger.logInf("onPresssssssssinggg scrollBarrrrrrrrrrrrrrrrrrrrrrrr")
                           // calculate step size to make the ScrollBar moving when touching the extended Range of Detecting Expanding ScrollBar
                           let currentY = mouse.y
                           let lowMouseAreaRange = 40, highMouseAreaRange = topMostItem.heightOfContentItem-40
                           if (currentY<lowMouseAreaRange){
                               stepSizeOfMoving = (lowMouseAreaRange-currentY)/(topMostItem.parentHeight);
                               movingBackward = true
                           }else if (currentY>highMouseAreaRange){
                               stepSizeOfMoving = (currentY-highMouseAreaRange)/(topMostItem.parentHeight);
                               movingForward = true
                           }
                           if (stepSizeOfMoving){
                               topMostItem.stepSize = stepSizeOfMoving
                           }
                           checkPressAndHold.start()
                           initialPos = mouse.y;
                           topMostItem.invisibleScrollBarTimer.stop();
                       }
            onPositionChanged: (mouse)=>{
                                    // Logger.logInf("onPositionChangedddddddddddddddddddd scrollBarrrrrrrrrrrrrrrrrrrrrrrr")
                                   let currentY = mouse.y;
                                   let diff = Math.abs(currentY - initialPos);
                                   if (diff>20) checkPressAndHold.stop();
                                   if (topMostItem.enableScrolling)
                                   {
                                       let diffToContentHeight = (currentY - initialPos)/(topMostItem.parentHeight);
                                       let tempPos = topMostItem.position+diffToContentHeight;
                                       if (tempPos<0) topMostItem.position = 0;
                                       else if (tempPos>topMostItem.initialSize) topMostItem.position = topMostItem.initialSize;
                                       else topMostItem.position+=diffToContentHeight;
                                   }
                               }
            onReleased: (mouse)=>{
                            // Logger.logInf("onReleaseddddddddddddddddddddd scrollBarrrrrrrrrrrrrrrrrrrrrrrr")
                            if (!topMostItem.expandSize){
                                if (movingForward) topMostItem.increase()
                                if (movingBackward) topMostItem.decrease()
                            }
                            movingForward = false
                            movingBackward = false
                            stepSizeOfMoving = 0
                            checkPressAndHold.stop();
                            initialPos = mouse.y;
                            topMostItem.enableScrolling = false;
                            topMostItem.revertSizeOfScrollBar();
                            topMostItem.invisibleScrollBarTimer.start();
                        }
            onExited:  {
                // Logger.logInf("onExitedddddddddddddddddddddddddddddddd scrollBarrrrrrrrrrrrrrrrrrrrrrrr")
                checkPressAndHold.stop();
            }
        }
    }

    Timer{
        id:enableInteractive
        interval:10
        onTriggered: {
            topMostItem.interactive = innerItem.visible;
            topMostItem.interactive = Qt.binding(function(){return innerItem.visible});

        }
    }
    Timer{
        id:invisibleScrollBar
        interval:3000
        onTriggered: {innerItem.visible = false}
    }
    Timer{
        id:checkPressAndHold
        interval:1000
        onTriggered: {
            topMostItem.expandSizeOfScrollBar();
            topMostItem.enableScrolling = true;
        }
    }
    function expandSizeOfScrollBar(){
        innerItem.width = 8;
        innerItem.radius = 2;
    }
    function revertSizeOfScrollBar(){
        innerItem.width = 2;
        innerItem.radius = 0;
    }
    function widthScrollBar(){
        if(innerItem.visible){
            topMostItem.width = 84
        }else{
            topMostItem.width = 1
        }
    }
    function visibleScrollBar(check){

    }
}
