import QtQuick
import QtQuick.Layouts
import UICommon.Base
CItem{
    id:rootItem
    width: 48
    height:48
    property list<GradientStop> gradientStops

    property list<GradientStop> pressedGradientStops

    property list<GradientStop> inActiveGradientStops

    property list<GradientStop> clickedGradientStops

    property int gradientOrientation: Gradient.Vertical
    // Choose the type of Button (How many states do buttons have: normal, pressed, clicked)
    // The enum is got from import BUTTONENUM 1.0
    property int typeOfButton: 1

    property string normalColor: "#2D2D37"
    // This is the source Image of Pressed State
    property string pressedColor: "#A0A0AA"
    // This is the source Image of Selected State
    property string selectedColor:"transparent"

    property string normalTextColor: "#D2D2D2"
    // This is the source Image of Pressed State
    property string pressedTextColor: "white"
    // This is the source Image of Selected State
    property string selectedTextColor:"transparent"

    property string inActiveTextColor : "#464650"

    property string inActiveColor     : "#191923"

    property bool inActiveState: false

    property alias spacing: textSection.spacing

    // Set the font for the inner text
    property var contentFont: CFont._SUBBODY

    property int touchButtonTop: 0
    property int touchButtonBottom: 0

    states:[
        State{
            when: rootItem.inActiveState || (VehicleGeneralState.isDriving && rootItem.isObject)
            name: "InactiveState"
            PropertyChanges{
                target           : rootItem
                disableUserEvent : true

            }
            PropertyChanges{
                target : hightLighter
                color  : rootItem.inActiveColor
            }
            PropertyChanges{
                target : indicator
                color  : rootItem.inActiveTextColor
            }
        }
    ]

    Rectangle{
        id     : hightLighter
        x      : offSetColor_left
        y      : offSetColor_top + touchButtonTop
        z      : rootItem.mouseAreaZ - 2
        width  : rootItem.width - offSetColor_left - offSetColor_right
        height : rootItem.height - offSetColor_bottom - offSetColor_top - touchButtonBottom - touchButtonTop
        color  : normalColor
        gradient: Gradient{
            id: gradient
            stops: rootItem.gradientStops
            orientation: rootItem.gradientOrientation
        }
    }
    property double offSetColor_left: 0
    property double offSetColor_right: 0
    property double offSetColor_bottom: 0
    property double offSetColor_top: 0
    // Whether or not the button has the event when keeping pressing on Button
    // it is associated with signal PressedAndHoldEvent(), pressedAndHoldTimer
    property bool hasPressedAndHoldEvent:false
    // To determine if the buttons have event when double click
    property bool hasUsageOfDoubleClick:false
    // To notify whenever the double click is active
    property bool isDoubleClick:false
    // To specify the default duration of pressedAndHold event (Maybe changing values, ...)
    property int pressedAndHoldEventDuration:300
    // To specify whether the button uses the default effect (When pressing it will change the Imag
    // Releasing it will recover to the inital state) or it will choose other ways to determine the images of button
    // If this property is set to true, we have to manually indicate the ways images change
    property bool customedWaysOfBehaviour:false
    // The inital image source of a button
    // To check whether or not mouse button is pressed
    property alias mousePressed:mouseArea.pressed
    // The value to store the on off state of the button
    property bool onOffState: false 


    property alias isValidEvent: mouseArea.isValidEvent
    property alias isEnableSound: mouseArea.isEnableSound
    property alias isDisablePressAndHoldEventWhenOutside: mouseArea.isDisablePressAndHoldEventWhenOutside
    // The default event when the button is clicked
    signal clicked()
    // The default event when the button is pressed
    signal pressed()
    // The default event when the button is released
    signal released()
    // The default event when the button is pressedAndHold
    signal pressedAndHold()
    // The default event when the button is doubleClicked
    signal doubleClicked()
    // The event when the button accepts the action that users keep pressing
    signal pressedAndHoldEvent()
    // The event to differentiate the click and doubleclick
    signal triggerDifferentiateTimer()

    property alias radius: hightLighter.radius

    // The timer is dedicated to keep pressing button
    Timer{
        id:pressedAndHoldTimer
        interval:rootItem.pressedAndHoldEventDuration
        running: false
        repeat: true
        onTriggered:rootItem.pressedAndHoldEvent()
    }
    // The Timer is dedicate to distinguish double click and click
    Timer{
        id:timerToDifferentiateClickAndDoubleClick
        interval: 390
        running:false
        onTriggered:rootItem.triggerDifferentiateTimer()
    }
    property alias timerIsRunning:pressedAndHoldTimer.running
    // The array of default button states and related infor
    property var buttonState:{
        'normal':{
            "status":false,
            "buttonColor":rootItem.normalColor,
            "textColor"  :rootItem.normalTextColor,
            "gradient"   :rootItem. gradientStops,
        }
        ,
        'pressed':{
            "status"     :false,
            "buttonColor":rootItem.pressedColor,
            "textColor"  :rootItem.pressedTextColor,
            "gradient"   :rootItem.pressedGradientStops,
        },
        'clicked':{
            "status":false,
            "buttonColor": rootItem.selectedColor,
            "textColor"  : rootItem.selectedTextColor,
            "gradient"   : rootItem.clickedGradientStops,
        },
    }
    // This function is used to get the appropriate Image source based on the given State
    function checkState(stateButton){
        if (rootItem.inActiveState || (VehicleGeneralState.isDriving && rootItem.isObject)) return
        if (buttonState[stateButton]["status"]){

            hightLighter.color     = rootItem.buttonState[stateButton]["buttonColor"]
            indicator.color        = rootItem.buttonState[stateButton]["textColor"]
            gradient.stops  = rootItem.buttonState[stateButton]["gradient"]
            if (stateButton === "normal" && onOffState){
                if (buttonState['clicked']["status"]){
                    hightLighter.color     = rootItem.buttonState["clicked"]["buttonColor"]
                    indicator.color        = rootItem.buttonState["clicked"]["textColor"]
                    gradient.stops         = rootItem.buttonState["clicked"]["gradient"]
                }
            }
        }
    }

    /**
      * @brief If the ButtonWidget is used inside a delegate to process user's events
      *        There is a need to pass the container list to support all business logic
      *        revolving arround the current item in set
      *        Some required actions such as highlight the current item, release the
      *        current item when users stop interacting
      */
    property var listContainer: undefined

    onListContainerChanged:{
        privateController.appendReleaseHandlerEvent()
    }
    /**
      * @brief In case the ButtonWidget is used as the event handler in list
      *        the model.index should be assigned into this property to indicate
      *        which event handler is
      */
    property int indexInList: -1
    /**
      * @brief To indicate whether the user is currently interacting with this item
      */
    property bool isPressing: false
    // When the component is fully loaded, it will determine the state of button based on given info

    property alias isConsumePressAndHold     : mouseArea.isConsumePressAndHold
    property alias disableUserEvent          : mouseArea.disableUserEvent
    property alias isToggleOrRadioButton     : mouseArea.isToggleOrRadioButton
    property alias isObject                  : mouseArea.isObject
    property alias mouseAreaZ                : mouseArea.z
    /**
      *@brief This function is used for outter to emit releaseMouseEvent
      *
      */

    property var releaseMouse: function(mouse)
    {
        mouseArea.releaseMouse(mouse);
    }
    /**
      * @brief This signal is used to emit the state when mouse is forced to release
      *
      */
    signal releaseInvalidMouse()

    QtObject{
        id: privateController
        function appendReleaseHandlerEvent(){
            if (rootItem.listContainer !== undefined){
				if (rootItem.listContainer.userEventsTracking1 !== undefined){
					rootItem.listContainer.userEventsTracking1[rootItem.indexInList] = mouseArea.releaseMouse
                }
            }
        }
    }
    function markSelectedItemInList()
    {
        if (rootItem.listContainer != undefined ){
			rootItem.listContainer.currentPressedIndex1 = rootItem.indexInList
        }
    }

    Component.onCompleted: {
        switch(typeOfButton){
        case 0:
        {
            buttonState['normal']['status'] = true
            break
        }
        case 1:
        {
            buttonState['normal']['status'] = true
            buttonState['pressed']['status'] = true
            break
        }
        case 2:
        {
            buttonState['normal']['status'] = true
            buttonState['clicked']['status'] = true
            buttonState['pressed']['status'] = true
            break
        }
        }
        // If the ButtonWidget is used inside a list, put the release event to the management
        // Of the container list
        privateController.appendReleaseHandlerEvent()
        if (iconDelegate != undefined && typeof iconDelegate == "object")
        {
            icon.active = true
        }

    }
    // Mouse Area to simulate the button effect
    property string indicator
    property double sizeIndicator

    // MultiLanguage
    property alias textID: indicator.textID
    property alias textWidth: indicator.textWidth
    property alias textHeight: indicator.textHeight

    property var iconDelegate: undefined
    RowLayout{
        id: textSection
        anchors.centerIn: parent
        Loader{
            id: icon
            active: false
            sourceComponent: iconDelegate
            Layout.alignment: Qt.AlignVCenter
        }
        CText{
            id: indicator
            text: qsTrId(rootItem.indicator)
            textID: rootItem.indicator
            textWidth: 216
            textHeight: 36
            _font: rootItem.contentFont
            color  : rootItem.normalTextColor
            Layout.alignment: Qt.AlignVCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
    CMouseArea{
        id:mouseArea
        anchors.fill:parent
        isObject: rootItem.isObject
        onPress: {
            if (mouseArea.isDisableState) return
            if (!rootItem.customedWaysOfBehaviour) rootItem.checkState("pressed")
            // If the CMouseArea is used inside a list, The current item in list is set to this one
            markSelectedItemInList();
            rootItem.isPressing = true
            rootItem.pressed()
        }
        onPressAndHold:
        {
            if (rootItem.hasPressedAndHoldEvent) pressedAndHoldTimer.start()
            rootItem.pressedAndHold()
        }
        onReleaseMouse: (mouseEvent) => {
            rootItem.isPressing = false
			if (rootItem.listContainer?.currentPressedIndex1){
				rootItem.listContainer.currentPressedIndex1 = -1
            }
            //Only change the state of this button if the release event is within the button area
            if (!rootItem.customedWaysOfBehaviour){
                rootItem.checkState('normal')
                if (rootItem.hasPressedAndHoldEvent) pressedAndHoldTimer.stop()
            }
            if (mouseArea.containsMouse  && mouseEvent) {
                onOffState = !onOffState
                rootItem.released()
            }else{
                rootItem.releaseInvalidMouse();
            }
        }
        onClicked:{
            if (hasUsageOfDoubleClick) timerToDifferentiateClickAndDoubleClick.start()
            rootItem.clicked()
        }
        onDoubleClicked:rootItem.doubleClicked()
    }
}
