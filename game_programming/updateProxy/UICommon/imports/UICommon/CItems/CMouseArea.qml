import QtQuick
import UICommon.Base
Item {
    id:root
    signal canceled()
    signal clicked(var mouse)
    signal doubleClicked(var mouse)
    signal entered()
    signal exited()
    signal positionChanged(var mouse)
    signal pressAndHold(var mouse)
    signal press(var mouse)
    signal released(var mouse)
    signal releaseMouse(var mouse)
    signal wheel(var wheel)
    signal releaseWhenDisable(var mouse)
    property alias acceptedButtons : innerMouse.acceptedButtons
    property alias containsMouse : innerMouse.containsMouse
    property alias containsPress : innerMouse.containsPress
    property alias cursorShape : innerMouse.cursorShape
    property alias drag : innerMouse.drag
    property alias enabled : innerMouse.enabled
    property alias hoverEnabled : innerMouse.hoverEnabled
    property alias mouseX : innerMouse.mouseX
    property alias mouseY : innerMouse.mouseY
    property alias pressAndHoldInterval : innerMouse.pressAndHoldInterval
    readonly property alias pressed : innerMouse.pressed
    property alias pressedButtons : innerMouse.pressedButtons
    property alias preventStealing : innerMouse.preventStealing
    property alias propagateComposedEvents : innerMouse.propagateComposedEvents
    property alias scrollGestureEnabled : innerMouse.scrollGestureEnabled
    property bool isObject:true
    /**
      * @brief If the CMouseArea is used inside a delegate to process user's events
      *        There is a need to pass the container list to support all business logic 
      *        revolving arround the current item in set
      *        Some required actions such as highlight the current item, release the 
      *        current item when users stop interacting
      */
    property var listContainer: undefined

    /**
      * @brief In case the CMouseArea is used as the event handler in list
      *        the model.index should be assigned into this property to indicate
      *        which event handler is
      */
    property int indexInList: -1
    /**
      * @brief To indicate whether the user is currently interacting with this item
      */
    property bool isPressing: false
    /**
      * @brief When the Press And Hold event is desired
      */
    property bool isConsumePressAndHold: false
    /**
      * @brief In case disable the Mouse Event
      */
    property bool disableUserEvent: false
    /**
      * @brief In case The button is Toggle or Radio
      */
    property bool isToggleOrRadioButton: false

    property bool isEnableSound: true

    property bool isValidEvent: false

    property bool isDisablePressAndHoldEventWhenOutside: false

    property bool isOnlyLDD: false

    property var enableSoundPartialSections : []
    
    property bool isDisableState              : false

    property bool trackingMouseWhenDrivingControl : false

    property bool enableTrackingMouseForItemIsNotObject: false

    property bool disblePressAndHoldEventWhenDriving: false

    property bool disableOutsideRestraintAfterInternal: false

    QtObject{
        id: privateVal
        property int defaultPressAndHoldInterval  : 500
        property bool isOverPressAndHoldInterval  : false
        property int buttonTouchSound             : root.isToggleOrRadioButton ? VehicleGeneralState.Accept : VehicleGeneralState.Touch
    }


    Component.onCompleted: {
        // If the CMouseArea is used inside a list, put the release event to the management 
        // Of the container list
        if (listContainer !== undefined){
            if (listContainer.userEventsTracking !== undefined){
                listContainer.userEventsTracking[indexInList] = innerMouse.released
            }
        }
    }

    MouseArea{
        id                      : innerMouse
        anchors.fill            : parent
        pressAndHoldInterval    : privateVal.defaultPressAndHoldInterval
        onContainsMouseChanged  : {
            if (!innerMouse.containsMouse){
                let isInDisableState = false
                if (root.isConsumePressAndHold){
                    if (root.isDisablePressAndHoldEventWhenOutside){
                        if(root.disableOutsideRestraintAfterInternal ){
                            if (!privateVal.isOverPressAndHoldInterval) 
                            {
                                isInDisableState = true;
                            }
                        }else{
                            isInDisableState = true;
                        }
                    }
                    if (root.enableTrackingMouseForItemIsNotObject && VehicleGeneralState.isDriving){
                        isInDisableState = true;
                    }
                }else{
                    isInDisableState = true;
                }
                if (isInDisableState){
                    isValidEvent                         = false
                    root.trackingMouseWhenDrivingControl = false
                    root.releaseMouse(undefined)
                }
            }
        }
        onPressed: (mouse)=>{
                       // If the CMouseArea is used inside a list, The current item in list is set to this one
                    //    
                       if (isObject && VehicleGeneralState.isDriving || root.disableUserEvent) {
                            root.trackingMouseWhenDrivingControl = true
                            root.isDisableState = true
                       }
                       else root.isDisableState = false
                       if (!root.isDisableState){
                            if (isObject && VehicleGeneralState.isDriving) return
                            if (listContainer != undefined){
                                listContainer.currentPressedIndex = indexInList
								listContainer.currentPressedIndex1 = indexInList
                            } 
                            if (root.enableTrackingMouseForItemIsNotObject) root.trackingMouseWhenDrivingControl = true
                            root.isValidEvent = true
                            root.isPressing    = true
                            root.press(mouse)
                       }
                   }
        onReleased: (mouse)=> {
                        if (root.isDisableState){
                            if ((root.isValidEvent || root.trackingMouseWhenDrivingControl ) && mouse != undefined) {
                                VehicleGeneralState.playSound(VehicleGeneralState.Reject)
                                root.releaseWhenDisable(mouse)
                                if (isObject && VehicleGeneralState.isDriving){
                                    if (UIConstants._APP_ENGINE !== undefined)
                                    {
                                        UIConstants._APP_ENGINE.disableOperationWhileDriving();
                                    }
                                    else
                                    {
                                        APP_ENGINE.disableOperationWhileDriving();
                                    }
                                    
                                }
                            }
                            
                            return;
                        }
                        
                        root.isPressing = false
                        if (!root.isValidEvent || mouse == undefined) {
                            root.isValidEvent = false
                            root.releaseMouse(undefined)
                            return  
                        }
                        if (!privateVal.isOverPressAndHoldInterval && innerMouse.containsMouse && root.isEnableSound){
                            let valid = false
                            if (root.enableSoundPartialSections.length > 0){
                                for (let points of root.enableSoundPartialSections){
                                    if(points.length != 2){
                                        break
                                    }else{
                                        if ( mouse.x >= points[0].x && mouse.x <= points[1].x 
                                           && mouse.y >= points[0].y && mouse.y <= points[1].y ){
                                            valid = true
                                            break
                                        }
                                    }
                                }
                            }else if (!root.isOnlyLDD){
                                valid = true
                            }
                            if (valid){
                                VehicleGeneralState.playSound(privateVal.buttonTouchSound)
                            }
                        }
                        privateVal.isOverPressAndHoldInterval = false
                        // If the CMouseArea is used inside a list and the current item in list is this one
                        // Reset the current index of the container list
                        if (listContainer?.currentPressedIndex){
                            listContainer.currentPressedIndex = -1
							listContainer.currentPressedIndex1 = -1
                        } 
                        if ((!isObject || !VehicleGeneralState.isDriving) && mouse) {
                            root.released(mouse)
                            root.releaseMouse(mouse)
                        }
                    }
        onDoubleClicked: (mouse)=>{
                            if (root.isDisableState) return
                             if (!isObject || !VehicleGeneralState.isDriving) {
                                 root.doubleClicked(mouse)
                             }
                         }
        onEntered:{if (root.isDisableState) return; root.entered()}
        onExited: {if (root.isDisableState) return; root.exited()}
        onPositionChanged: (mouse)=>{
                                if (root.isDisableState) return
                                if (!isObject || !VehicleGeneralState.isDriving) {
                                    root.positionChanged(mouse)
                                }
                           }
        onPressAndHold: (mouse)=>{
                            if (root.isDisableState) return
                            if (root.isConsumePressAndHold && !root.isToggleOrRadioButton && root.isEnableSound && root.isValidEvent){
                                if (VehicleGeneralState.isDriving){
                                    if (isObject || root.disblePressAndHoldEventWhenDriving) return
                                }
                                privateVal.isOverPressAndHoldInterval = true
                                VehicleGeneralState.playSound(VehicleGeneralState.LongPush)
                            }
                            if (!isObject || !VehicleGeneralState.isDriving) {
                                if (isValidEvent) root.pressAndHold(mouse)
                            }
                        }
        onWheel: (mouse)=>{
                            if (root.isDisableState) return
                            if (!isObject || !VehicleGeneralState.isDriving) {
                                root.wheel(mouse)
                            }
                 }
        onClicked: (mouse)=>{
                            if (root.isDisableState || !root.isValidEvent) return
                            if (!isObject || !VehicleGeneralState.isDriving) {
                                root.clicked(mouse)
                            }
                   }
    }
}
