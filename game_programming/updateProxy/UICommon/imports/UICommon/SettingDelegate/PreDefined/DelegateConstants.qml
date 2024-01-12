pragma Singleton
import QtQuick 2.15
import QtQuick.Layouts
import UICommon.CItems

QtObject{
    id: delegateConstant
    property var delegateInstance:[
        Qt.createComponent("ConfirmPopupDelegate.qml"),
        Qt.createComponent("NavigateDelegate.qml"),
        Qt.createComponent("ToggleDelegate.qml"),
        Qt.createComponent("SelectionPopupDelegate.qml"),
        Qt.createComponent("AdjustDelegate.qml"),
        Qt.createComponent("InformationDelegate.qml"),
    ]
    Component.onCompleted:
      {
          _ROOT_ITEM = APP_ENGINE.rootContentItem
      }
    readonly property int _POPUP_CONFIRM_DELEGATE   : 0
    readonly property int _NAVI_DELEGATE            : 1
    readonly property int _TOGGLE_DELEGATE          : 2
    readonly property int _SELECTION_DELEGATE       : 3
    readonly property int _ADJUST_DELEGATE          : 4
    readonly property int _INFORMATION_DELEGATE     : 5
    readonly property int _UNSELECT_INDEX           : -1
    property var _ROOT_ITEM
    property var _UI_COMMUNICATION: UICommunication
    property Component naviDLGPro: Component{
        QtObject{
            property string title
            property int settingType
            property int eventID
            property var processor
            property bool visible: true
            property bool enabled: true
            property bool tonedownItem: false
            property bool isArrowVisible: true
        }
    }

    property Component toggleDLGPro: Component{
        QtObject{
            property string title
            property int settingType
            property int status
            property var processor
            property bool visible: true
            property bool enabled: true
            property bool tonedownItem: false
        }
    }

    property Component selectionDLGPro: Component{
        QtObject{
            property string title
            property int settingType
            property int currentIndex
            property ListModel selectionList
            property var processor
            property bool visible: true
            property bool enabled: true
            property bool tonedownItem: false
        }
    }

    property Component adjustDLGPro: Component{
        QtObject{
            property string title
            property int settingType
            property int currentValue
            property int lowerThreshold
            property int upperThreshold
            property var processor: undefined
            property bool tonedownItem: false

        }
    }

    property Component infoDelegatePro: Component{
        QtObject{
            property string title
            property int settingType
            property var processor
            property bool visible           : true
            property bool enabled           : true
            property bool isSubInfoVisible  : true
            property bool tonedownItem      : false
            property string subInfoText     : ""
            property bool isArrowVisible    : true
        }
    }


    readonly property int _DELEGATE_HEGIHT      : 80
    readonly property int _LIST_SETTING_WIDTH   : 964
    readonly property int _LIST_SETTING_HEIGHT  : 542
    readonly property int _OFFSET_LISTSETTING_X : 32
    readonly property int _OFFSET_LISTSETTING_Y : 80
    readonly property string _INVALID_TITLE     : ""

    readonly property Component _ACCEPT_BUTTON_DELEGATE: Component{
        ButtonWidget{
            signal accept()
            indicator : "決定"
            buttonOnlyIcon  : false
            width:  160
            height: 50
            radius:8
            onReleased:{
                accept();
            }
        }
    }
    readonly property Component _ACCEPT_CANCEL_BUTTON_DELEGATE: Component{
        Item{
            width: 488
            height: 50
            signal accept()
            signal reject()
            ButtonWidget{
                indicator : qsTrId(QT_TRID_NOOP("SCO_13-8"))
                buttonOnlyIcon  : false
                width:  160
                height: 50
                radius:8
                inActiveColor: "#191923"
                inActiveTextColor: "#464650"
                x: 50
                extendTouchAreaFromHorizontalCenter: 30
                onReleased:{
                    accept();
                }

                textID: QT_TRID_NOOP("SCO_13-8")
                textWidth: 160
                textHeight: 50
            }
            ButtonWidget{
                indicator : qsTrId(QT_TRID_NOOP("SCO_13-7"))
                buttonOnlyIcon  : false
                width:  160
                height: 50
                radius:8
                inActiveColor: "#191923"
                inActiveTextColor: "#464650"
                x: 276
                extendTouchAreaFromHorizontalCenter: 30
                onReleased:{
                    console.warn("Call reject")
                    reject();
                }

                textID: QT_TRID_NOOP("SCO_13-7")
                textWidth: 160
                textHeight: 50
            }
        }
    }


    readonly property QtObject _ONE_selectionTitleProperty: QtObject
    {
        property int x: 56
    }
    readonly property QtObject _MULTIPLE_selectionTitleProperty: QtObject
    {
        property int x: 6
    }


    // property Component


    readonly property Component selectBoxIndicatorDelegate: Component
    {
        RadioIndicator{
            id: indicator
            y: indicatorY
            property int  indicatorY: 0
        }
    }
    readonly property Component toggleSelectionIndicatorDelegate: Component
    {
        CSwitch{
            id : control
            checked: model.status
            indicatorWidth: 80
            indicatorHeight:44
            sizeIndicator:  38
            indicatorRadius:25
            isToggle: true
            x: 340
            anchors.verticalCenter: parent.verticalCenter
            enableAnimation: false
            Timer { // Fix me: to turn off animation until the toggle is completed
                id: timer
                interval: 500; running: false; repeat: false
                onTriggered: control.enableAnimationOnSwitch()
            }
            Component.onCompleted: {
                if(!control.enableAnimation){
                    timer.start()
                }
            }
        }
    }
}
