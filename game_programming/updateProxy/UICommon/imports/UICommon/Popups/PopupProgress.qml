import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import UICommon.Base
import UICommon.CItems
import "Components" as COMPONENTS

/*
    Guidance:
        This is template for popup which has progress of loading, we can use it with setting value of type_of_mode and some variables of progress:
            type_of_mode == 0 - size: 784x500
                ------------------------------------
                ----------{Message Text}------------
                ---------{Progress Slider}----------
                ---------{Progress Value}-----------
                ----------{Button Text}-------------
                ------------------------------------

            type_of_mode == 1  - size: 784x500
                ------------------------------------
                ----------{Message Text}------------
                ---------{Progress Slider}----------
                ------------------------------------
                ----------{Button Text}-------------
                ------------------------------------

            type_of_mode == 2 - size: 784x288
                ------------------------------------
                ----------{Message Text}------------
                ---------{Progress Slider}----------
                ----------{Button Text}-------------
*/
Item {
    id: root
    property int type_of_mode: 0
    property string message_line_one: "Message Text"
    property int slider_current_value: 20
    property int slider_min: 0
    property int slider_max: 100
    property string message_button: "Button Text"
    property string img_left_button: UIConstants._POPUP_BTN_BGRD_NORMAL
    property string img_left_button_pressed: UIConstants._POPUP_BTN_BGRD_PRESSDED

    property var popup_height: [ 500, 500, 288 ]
    property var popup_posy: [ 110, 110, 416 ]
    property var height_msg_ctn: [ 200, 200, 80 ]
    property var posY_msg_ctn: [ 60, 60, 16 ]
    property var posY_slider_ctn: [ 260, 260, 16 ]
    property var posY_btn_ctn: [ 372, 372, 176 ]

    function getPosYOfPopup(mode) { return popup_posy[mode] }
    function getHeightOfPopup(mode) { return popup_height[mode] }
    function getHeightOfMsgCtn(mode) { return height_msg_ctn[mode] }
    function getPosYOfMsgCtn(mode) { return posY_msg_ctn[mode] }
    function getPosYOfSliderCtn(mode) { return posY_slider_ctn[mode] }
    function getPosYBtnCtn(mode) { return posY_btn_ctn[mode] }

    signal clicked()
    signal released()
    signal pressed()
    signal clickedOnMask()

    CRectangle{
        id: backgroundImg
        width: UIConstants._POPUP_BACKGROUND_WIDTH
        height: UIConstants._POPUP_BACKGROUND_HEIGHT
        color: UIConstants._POPUP_COLOR_TRANSPARENT
        CImage {
            id: bgrd_img
            opacity: 0.7
            source: !isDisableBackground ? UIConstants._POPUP_BACKGROUND_IMAGE : ""
        }
        MouseArea{
            anchors.fill:parent
            onClicked:{
                root.clickedOnMask()
            }
        }
    }

    CRectangle {
        id: popup_content
        width: UIConstants._POPUP_WIDTH
        height: getHeightOfPopup(type_of_mode)
        anchors.horizontalCenter: parent.horizontalCenter
        y: root.getPosYOfPopup(type_of_mode)
        color: UIConstants._POPUP_COLOR_TRANSPARENT

        MouseArea {
            anchors.fill: parent
        }

        CImage {
            id: popup_img
            anchors.fill: parent
            source: type_of_mode < 1 ? UIConstants._POPUP_FRAME_784x500 : UIConstants._POPUP_FRAME_784x216
        }

        CRectangle {
            id: ctnMsg
            width: UIConstants._POPUP_MSG_WIDTH
            height: getHeightOfMsgCtn(type_of_mode)
            anchors.horizontalCenter: parent.horizontalCenter
            y: getPosYOfMsgCtn(type_of_mode)
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            COMPONENTS.CText {
                id: msg_txt
                anchors.centerIn: parent
                msg_text: message_line_one
            }
        }

        CRectangle {
            id: sliderBarCtn
            width: UIConstants._POPUP_SLIDER_WIDTH_640
            height: UIConstants._POPUP_SLIDER_HEIGHT_80
            anchors.horizontalCenter: parent.horizontalCenter
            y: getPosYOfSliderCtn(type_of_mode)
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            Slider {
                id: progress_process
                anchors.centerIn: parent
                width: UIConstants._POPUP_SLIDER_WIDTH_564
                height: UIConstants._POPUP_SLIDER_HEIGHT_4
                implicitHeight: UIConstants._POPUP_SLIDER_HEIGHT_4
                implicitWidth: UIConstants._POPUP_SLIDER_WIDTH_564
                snapMode: Slider.NoSnap
                clip: true
                value: slider_current_value
                from: slider_min
                to: slider_max
                enabled: false

                background: CRectangle {
                    id: controllerWrapper
                    anchors.centerIn: parent
                    implicitWidth: UIConstants._POPUP_SLIDER_WIDTH_564
                    implicitHeight: UIConstants._POPUP_SLIDER_HEIGHT_4
                    width: UIConstants._POPUP_SLIDER_WIDTH_564
                    height: UIConstants._POPUP_SLIDER_HEIGHT_4
                    color: UIConstants._POPUP_SLIDER_BACKGROUND_COLOR
                    Image{
                        anchors.verticalCenter: parent.verticalCenter
                        source: UIConstants.popup_slider_bgrd
                        width: progress_process.visualPosition * parent.width
                        height: parent.height
                    }
                }

                handle: CRectangle {
                }
            }
        }

        CRectangle {
            id: ctnProgressVal
            width: UIConstants._POPUP_SLIDER_PROGRESS_VALUE_WIDTH
            height: UIConstants._POPUP_SLIDER_PROGRESS_VALUE_HEIGHT
            anchors.horizontalCenter: parent.horizontalCenter
            y: UIConstants._POPUP_SLIDER_PROGRESS_VALUE_POSY_318
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            visible: type_of_mode === 0
            COMPONENTS.CText {
                id: progress_value
                anchors.centerIn: parent
                msg_text: String(progress_process.value)
            }
        }

        CRectangle {
            id: ctnBtn
            width: UIConstants._POPUP_BTN_WIDTH
            height: UIConstants._POPUP_BTN_HEIGHT
            anchors.horizontalCenter: parent.horizontalCenter
            y: getPosYBtnCtn(type_of_mode)
            color: UIConstants._POPUP_COLOR_TRANSPARENT

            CImage {
                id: background_color
                anchors.fill: parent
                source: button_mouse.pressed ? img_left_button_pressed : img_left_button
            }

            COMPONENTS.CText {
                id: btnTxt
                anchors.centerIn: parent
                msg_text: message_button
            }

            MouseArea {
                id: button_mouse
                anchors.fill: parent
                onClicked: {
                    root.clicked()
                }
                onReleased: {
                    root.released()
                }
                onPressed: {
                    root.pressed()
                }
            }
        }
    }
}
