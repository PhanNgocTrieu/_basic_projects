import QtQuick.Controls
import QtQuick
import UICommon.Base
Switch {
    id: control
    /*!
       \property toneDownCondition
       This property is used to tonedown the Switch when condition is met
    !*/
    property bool toneDownCondition
    property bool enableDrivingRestriction: true
    /*!
       \signal clicked
        The signal is used to propagate and process the click event
    !*/
    signal clicked(var mouse)

    /*!
       \signal released
        The signal is used to propagate and process the release event
    !*/
    signal released(var mouse)
    /*!
        \signal pressed
        The signal is used to propagate and process thes press event

    !*/
    signal press(var mouse)
    checkable : false
    height: 44
    checked:false
    opacity: control.toneDownCondition ||  VehicleGeneralState.isDriving && enableDrivingRestriction ? 0.5 : 1

    property int indicatorWidth  : 80
    property int indicatorHeight : 44
    property int sizeIndicator   : 38
    property int indicatorRadius : 38 / 2
    property bool isToggle       : true
    property bool enableAnimation: true
    property string pathImage: "qrc:/qt-project.org/imports/UICommon/Resources/imports/UICommon/Resources/"
    property bool isEnableSound: true
    property bool isDisableToneDown: false
    function enableAnimationOnSwitch(){
        privateSwitch.activeAnimation = true
    }

    onVisibleChanged:{
        // When the item is invisible, we disable the animation for next appearence
        if (!visible)
        {
            privateSwitch.isAnimationHappenedDuringInvisible  = false;
            privateSwitch.activeAnimation                   = false;
            return;
        } 
        
        if ((privateSwitch.isAnimationHappenedDuringInvisible === false) && (visible === true))
        {
            //If no animation has happened during the switch is invisible, activate animation on to avoid bug.
            privateSwitch.activeAnimation                   = true;
        }
    }

    Component.onCompleted:{
        if (!visible)
        {
            privateSwitch.activeAnimation                   = false;
        }
    }
    QtObject{
        id: privateSwitch
        property bool activeAnimation  : false
        property bool isAnimationHappenedDuringInvisible : false
        // This property is defined to synchronize the state between color changes and indicator position changes
        property int checkStatus: control.checked

        function modifyActiveAnimationStatus(){
            if (enableAnimation) activeAnimation = true
        }
        property list<State> switchState: [
            State{
                name : "checked"
                when: control.checked
//                PropertyChanges{
//                    target  : begin
//                    //color   : "#628BFF"
//                }
//                PropertyChanges{
//                    target  : end
//                    //color   : "#3755A5"
//                }
            },
            State{
                name : "normal"
                when: !control.checked
//                PropertyChanges{
//                    target  : begin
//                    //color   : "#696973"
//                }
//                PropertyChanges{
//                    target  : end
//                    //color   : "#4B4B55"
//                }
            }
            // State{
            //     name: "invisible"
            //     when: !control.visible
            // }
        ]
        property list<Transition> stateTransition: [
            Transition{
                to: "checked"
                SequentialAnimation{
                    ParallelAnimation{
                        ScriptAction{
                            script:{
                                privateSwitch.isAnimationHappenedDuringInvisible  = true;
                                privateSwitch.checkStatus                       = true;
                            }
                        }
                        ColorAnimation{
                            //targets: [begin,end]
                            duration: privateSwitch.activeAnimation ? 200 : 0
                            easing.type: Easing.OutCubic
                        }
                    }

                    ScriptAction{
                        script: {
                            privateSwitch.modifyActiveAnimationStatus()
                        }
                    }
                }
            },
            Transition{
                to: "normal"
                SequentialAnimation{
                    ParallelAnimation{
                        ScriptAction{
                            script:{
                                privateSwitch.isAnimationHappenedDuringInvisible   = true;
                                privateSwitch.checkStatus                       = false;
                            }
                        }
                        ColorAnimation{
                            //targets: [begin,end]
                            duration: privateSwitch.activeAnimation ? 200 : 0
                            easing.type: Easing.OutCubic
                        }
                    }

                    ScriptAction{
                        script: {
                            privateSwitch.modifyActiveAnimationStatus()
                        }
                    }
                }

            }
        ]
    }
    indicator: CImage {
        id : circleIndicator
        width:   control.indicatorWidth
        height:  control.indicatorHeight
        x: control.leftPadding
        y: parent.height / 2 - height / 2
        //radius      : 25
        states      : privateSwitch.switchState
        transitions : privateSwitch.stateTransition
//        gradient    : Gradient {
//            orientation: Gradient.Horizontal
//            GradientStop { id:begin ;position: 0}
//            GradientStop { id:end   ;position: control.checked ? 0.47 : 1}
//        }

        source: control.checked ? pathImage + "Background_Toggle_ON_Normal.png" : pathImage + "Background_Toggle_OFF_Normal.png"
        CImage{
            id: rects
            x: privateSwitch.checkStatus ? parent.width - width +1 : -1
            y: 3
            width : 46
            height: 46
            source: control.toneDownCondition ||  VehicleGeneralState.isDriving && enableDrivingRestriction? pathImage + "Circle_Tonedown.png" :  pathImage +"Circle_Normal.png"
            Behavior on x {
                NumberAnimation {
                    duration: privateSwitch.activeAnimation ? 300 : 0
                    easing.type: Easing.InCubic
                }
            }
        }
    }
    CMouseArea{
        //anchors.fill: control
        width: 88
        height: 80
        anchors.centerIn: control
        disableUserEvent: control.toneDownCondition
        isToggleOrRadioButton: control.isToggle
        isEnableSound: control.isEnableSound
        isObject: !isDisableToneDown
        onReleased: (mouse) => {
            control.released(mouse)
        }
        onPress: (mouse) => {
            control.press(mouse)
        }
    }
}
