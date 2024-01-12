import QtQuick 2.15
import UICommon.Base

Text {
    id: root
    property string textID: ""
    property real textWidth: root.width
    property real textHeight: root.height

    property bool pressedState: false
    property bool inActiveState: false
    property string normalTextColor: "#D2D2D2"
    property string pressedTextColor: "white"
    property string inActiveTextColor: "#64646E"

    property var _font: QtObject{
        property int lineHeight: 1
        property int lineHeightMode: Text.ProportionalHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF TazuganeInfo",
                weight: 275 ,
                pixelSize: 26
            }
        )
    }

    color: root.normalTextColor

    states:[
        State{
            when: root.pressedState
            PropertyChanges{
                target : root
                color  : root.pressedTextColor
            }
        },
        State{
            when: root.inActiveState
            PropertyChanges{
                target : root
                color  : root.inActiveTextColor
            }
        }
    ]


    on_FontChanged: {
        if (HMI_SYS.isPrintOverFlowTextLog) {
            if (root.contentWidth > textWidth || root.contentHeight > textHeight) {
                Logger.logInf("[MultiLanguage] - on_FontChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            } else {
                Logger.logInf("[MultiLanguage] - on_FontChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Not overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            }
        }
    }

    onTextHeightChanged: {
        if (HMI_SYS.isPrintOverFlowTextLog) {
            if (root.contentWidth > textWidth || root.contentHeight > textHeight) {
                Logger.logInf("[MultiLanguage] - onTextHeightChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            } else {
                Logger.logInf("[MultiLanguage] - onTextHeightChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Not overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            }
        }
    }

    onTextWidthChanged: {
        if (HMI_SYS.isPrintOverFlowTextLog) {
            if (root.contentWidth > textWidth || root.contentHeight > textHeight) {
                Logger.logInf("[MultiLanguage] - onTextWidthChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            } else {
                Logger.logInf("[MultiLanguage] - onTextWidthChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Not overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            }
        }
    }

    onTextChanged: {
        if (HMI_SYS.isPrintOverFlowTextLog) {
            if (root.contentWidth > textWidth || root.contentHeight > textHeight) {
                Logger.logInf("[MultiLanguage] - onTextChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            } else {
                Logger.logInf("[MultiLanguage] - onTextChanged , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Not overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            }
        }
    }

    Component.onCompleted: {
        this.lineHeight     = _font.lineHeight
        this.lineHeightMode = _font.lineHeightMode
        this.font           = _font._Font

        if (HMI_SYS.isPrintOverFlowTextLog) {
            if (root.contentWidth > textWidth || root.contentHeight > textHeight) {
                Logger.logInf("[MultiLanguage] - onCompleted , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + ", text: " + root.text + ", end.");
            } else {
                Logger.logInf("[MultiLanguage] - onCompleted , language: " + HMI_SYS.currentLanguage + ", textId: " + textID
                              + " , Result: Not overflow , contentWidth: " + Math.trunc(root.contentWidth)
                              + " , contentHeight: " + Math.trunc(root.contentHeight)
                              + " , textWidth: "     + Math.trunc(textWidth)
                              + " , textHeight: "    + Math.trunc(textHeight)
                              + " , text: " + root.text + ", end.");
            }
        }
    }
}
