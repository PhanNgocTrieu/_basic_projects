import QtQuick
import QtQuick.Layouts
import UICommon.Base

CMouseArea {
    id: rootItem
    z: 0
    property string normalSource  : ""
    property string pressedSource : ""
    property string inActiveSource: ""

    property int widthImage       : 0
    property int heightImage      : 0

    property string normalTextColor: "#D2D2D2"
    property string pressedTextColor: "white"
    property string inActiveTextColor: "#464650"

    property bool tonedownItem: false

    property var contentFont: CFont._SUBBODY

    property var iconDelegate: undefined
    property string textButton: ""

    property double highLightX: 0
    property double highLightY: 0


    property bool visibleText: true

    // MultiLanguage
    property alias textID: indicator.textID
    property alias textWidth: indicator.textWidth
    property alias textHeight: indicator.textHeight
    property alias wrapMode: indicator.wrapMode
    property alias spacing: textSection.spacing

    property bool disableHighLightWhenPressed: false
    property bool disableUserEventWhenInActive: true

    readonly property bool pressedState: (!disableHighLightWhenPressed && rootItem.isValidEvent && rootItem.pressed && !inActiveState)
    readonly property bool inActiveState: (rootItem.tonedownItem || VehicleGeneralState.isDriving && rootItem.isObject)

    states:[
        State{
            name: "PressedState"
            when: rootItem.pressedState
            PropertyChanges{
                target           : rootItem
                disableUserEvent : false
            }
            PropertyChanges{
                target : highLight
                source  : rootItem.pressedSource
            }
            PropertyChanges{
                target : indicator
                color  : rootItem.pressedTextColor
            }
        },
        State{
            name: "InactiveState"
            when: rootItem.inActiveState
            PropertyChanges{
                target           : rootItem
                disableUserEvent : rootItem.disableUserEventWhenInActive
            }
            PropertyChanges{
                target : highLight
                source  : rootItem.inActiveSource
            }
            PropertyChanges{
                target : indicator
                color  : rootItem.inActiveTextColor
            }
        }
    ]

//    CImage {
//        id      : highLight
//        z       : -2
//        x       : rootItem.highLightX
//        y       : rootItem.highLightY
//        width   : rootItem.widthImage
//        height  : rootItem.heightImage
//        source  : rootItem.normalSource
//    }

    BorderImage
    {
        id      : highLight

        z       : -2
        x       : rootItem.highLightX
        y       : rootItem.highLightY
        source  : rootItem.normalSource
        visible : rootItem.visible
        width   : (rootItem.widthImage !== 0) ? rootItem.widthImage : highLight.sourceSize.width
        height  : (rootItem.heightImage !== 0) ? rootItem.heightImage : highLight.sourceSize.height
        horizontalTileMode  : BorderImage.Stretch
        verticalTileMode    : BorderImage.Stretch
        border { left: 6; top: 6; right: 6; bottom: 6 }
    }

    RowLayout{
        id: textSection
        anchors.centerIn: parent
        Loader{
            id: icon
            active: false
            sourceComponent: rootItem.iconDelegate
            Layout.alignment: Qt.AlignVCenter
        }
        CText{
            id: indicator
            text: qsTrId(rootItem.textButton)
            textID: rootItem.textButton
            textWidth: 216
            textHeight: 36
            _font: rootItem.contentFont
            color  : rootItem.normalTextColor
            Layout.alignment: Qt.AlignVCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            visible: rootItem.visibleText
        }
    }
    Component.onCompleted: {
        if (iconDelegate != undefined && typeof iconDelegate == "object"){
            icon.active = true
        }
    }
}
