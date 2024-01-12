import QtQuick 2.15
import QtQuick.Controls 2.15
import HMIEVENTS 1.0
import UICommon.Animation
import UICommon.Base
import UICommon.CItems
import UICommon.Effects

CItem {
    id: rootItem

    // The value to set the mouse scope can press
    property int mouseScopeWidth: 0
    property int mouseScopeHeight: 0

    width: rootItem.mouseScopeWidth
    height: rootItem.mouseScopeHeight

    // The value to width and height of text content
    property int textWidth: rootItem.mouseScopeWidth
    property int textHeight: rootItem.mouseScopeHeight

    // The text to display above the button
    property string textButton: ""

    // Set font to text
    property var fontText: CFont._BODY

    property bool disableUserEvent: false
    property bool inActiveState: false

    // The color when mouse normal
    property string textNormalColor: "#D2D2D2"

    // The color when mouse pressed
    property string textPressedColor: "white"
    property string inActiveTextColor: "#464650"

    // The property to set the text will shrink when pressed
    property bool isShrinkWhenPress: false

    readonly property bool isValidEvent: mouseTextBtn.isValidEvent

    property bool isObject: true

    property alias isDisablePressAndHoldEventWhenOutside: mouseTextBtn.isDisablePressAndHoldEventWhenOutside

    property bool isSpecialButton: true
    property bool isAnchorsLeftButton: true

    property int bottomMarginPos: 0
    property int leftMarginPos: 0
    property int rightMarginPos: 0
    property int topMarginPos: 0

    // Properties to set the size of item when shrinking
    property int shrinkTextWidthSize: 4
    property int shrinkTextHeightSize: 4

    property bool isTextButtonCenter: false
    property bool isEnableMouse: true


    signal clicked()
    signal pressed()
    signal released()
    signal pressedAndHold()
    signal doubleClicked()
    signal pressedAndHoldEvent()
    signal releasedWhenDisable()

    property real contentWidthText: 0

    CLoader {
        id: loaderButton
        sourceComponent: rootItem.isSpecialButton ? specialBtn : normalBtn
        active: true
        anchors {
            bottom: rootItem.isSpecialButton ? parent.bottom : undefined
            bottomMargin: rootItem.bottomMarginPos
            left: rootItem.isAnchorsLeftButton ? parent.left : undefined
            leftMargin: rootItem.isAnchorsLeftButton ? rootItem.leftMarginPos : undefined
            right: rootItem.isAnchorsLeftButton ? undefined : parent.right
            rightMargin: rootItem.isAnchorsLeftButton ? undefined : rootItem.rightMarginPos
            centerIn: rootItem.isTextButtonCenter ? parent : undefined
        }
    }

    Component {
        id: specialBtn
        CItem {
            width: rootItem.textWidth
            height: rootItem.textHeight
            CText {
                id: textBtn
                width: parent.width
                visible: !mouseTextBtn.isValidEvent
                text: qsTrId(rootItem.textButton)
                _font: rootItem.fontText
                wrapMode: Text.Wrap
                onContentWidthChanged: rootItem.contentWidthText = textBtn.contentWidth
                anchors.bottom: parent.bottom
                normalTextColor: rootItem.textNormalColor
                pressedState: mouseTextBtn.isValidEvent
                inActiveState: rootItem.inActiveState || VehicleGeneralState.isDriving
                inActiveTextColor: rootItem.inActiveTextColor
                verticalAlignment: rootItem.isTextButtonCenter ? Text.AlignVCenter : Text.AlignBottom
                horizontalAlignment: rootItem.isTextButtonCenter ? Text.AlignHCenter : (rootItem.isAnchorsLeftButton ? Text.AlignLeft : Text.AlignRight)

            }
            BlurShadow {
                id: textShadow
                source: textBtn
                anchors.bottom: parent.bottom
                color: rootItem.textPressedColor
                visible: mouseTextBtn.isValidEvent
                width: rootItem.isShrinkWhenPress ? parent.width - rootItem.shrinkTextWidthSize : parent.width
                height: rootItem.isShrinkWhenPress ? textBtn.contentHeight - rootItem.shrinkTextHeightSize : textBtn.contentHeight
            }
        }
    }

    Component {
        id: normalBtn
        CItem {
            anchors.fill: parent

            CText {
                id: textBtn
                width: rootItem.textWidth
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                    topMargin: rootItem.topMarginPos
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                visible: !mouseTextBtn.isValidEvent
                text: qsTrId(rootItem.textButton)
                _font: rootItem.fontText
                wrapMode: Text.Wrap
                inActiveState: rootItem.inActiveState || VehicleGeneralState.isDriving
                inActiveTextColor: rootItem.inActiveTextColor
                pressedState: mouseTextBtn.isValidEvent
                normalTextColor: rootItem.textNormalColor
            }
            BlurShadow {
                id: textShadow
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                    topMargin: rootItem.topMarginPos
                }
                visible: mouseTextBtn.isValidEvent
                width: rootItem.isShrinkWhenPress ? textBtn.width-rootItem.shrinkTextWidthSize : textBtn.width
                height: rootItem.isShrinkWhenPress ? textBtn.contentHeight - rootItem.shrinkTextHeightSize : textBtn.contentHeight
                source: textBtn
                color: rootItem.textPressedColor
                anchors.centerIn: rootItem.xTextPos == 0 && rootItem.yTextPos == 0 ? parent : undefined
            }
        }
    }

    CMouseArea {
        id: mouseTextBtn
        anchors.fill: parent
        enabled: rootItem.isEnableMouse
        isObject: rootItem.isObject
        disableUserEvent: rootItem.disableUserEvent
        onPress: rootItem.pressed()
        onReleased: rootItem.released()
        onReleaseWhenDisable: rootItem.releasedWhenDisable()
        onClicked: rootItem.clicked()
        onPressAndHold: rootItem.pressedAndHoldEvent()
    }
}
