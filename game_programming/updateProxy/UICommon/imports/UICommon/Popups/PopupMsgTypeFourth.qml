import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import UICommon.Base
import UICommon.CItems
import "Components" as COMPONENTS

/*
    Guidance for using:
        This qml defines template popoups includes: (chosing mode from setting type_of_mode variable (0 as default))
            Type 1: -> 0 (size: 784x500)
                --------     {Title}    ---------
                -------- {Message Text} ---------
                ------- {Circle Loading} ---------
                -------- {Button Text} ---------

            Type 2: -> 1 (size: 784x500)
                -------- {Message Text} ---------
                ------- {Circle Loading} --------


            Type 3: -> 2 (size: 784x288) - bottom
                -------- {Message Text} ---------
                ------- {Circle Loading} --------
                -------- {Button Text} ---------

            Type 4: -> 3 (size: 784x288) - bottom
                -------- {Message Text} ---------
                ------- {Circle Loading} ---------

        Note:
            With Text Message -> Currently, If your popup has 3 lines of message -> put 3 of them in one line and using '\n' to seperate it
            If your message text in seperate in mult-languages for each line -> using the number of lines of you need
*/

Item{
    id: root
    property int type_of_mode: 0
    property bool is_disable_background: false
        /* This flag for aligning the message text to left */
    property bool is_msg_left_align: false

    property string message_title: "Title"

    property bool is_use_msg_2: false
    property string message_line_one: "Message Text 1"
    property string message_line_two: "Message Text 2"

    property string img_left_button: UIConstants._POPUP_BTN_BGRD_NORMAL
    property string img_left_button_pressed: UIConstants._POPUP_BTN_BGRD_PRESSDED
    property string message_left_button: "Button Text"

    property bool is_using_button_right: false
    property string img_right_button: UIConstants._POPUP_BTN_BGRD_NORMAL
    property string img_right_button_pressed: UIConstants._POPUP_BTN_BGRD_PRESSDED
    property string message_right_button: "Button Text"

    /* This property for wrapping text */
    property bool using_wrap_text: false

    property int duration_timer: 2000

    // signals
    signal clickedOnMask()
    signal leftClicked()
    signal leftPressed()
    signal leftReleased()
    signal rightClicked()
    signal rightPressed()
    signal rightReleased()

    property var popup_height: [
        UIConstants._POPUP_HEIGHT_500,
        UIConstants._POPUP_HEIGHT_500,
        UIConstants._POPUP_HEIGHT_288,
        UIConstants._POPUP_HEIGHT_288
    ]

    property var btn_ctn_posY: [
        UIConstants._POPUP_BTN_CTN_POS_Y_372,
        UIConstants._POPUP_BTN_CTN_POS_Y_176,
        UIConstants._POPUP_BTN_CTN_POS_Y_104
    ]

    property var msg_ctn_posY_type_1: [
        UIConstants.popup_msg_fourth_posY_1,
        UIConstants.popup_msg_fourth_posY_2,
        UIConstants.popup_msg_fourth_posY_3,
        UIConstants.popup_msg_fourth_posY_4
    ]

    property var circle_load_img_posY: [
        UIConstants._POPUP_ICON_CIRCLE_POSY_220,
        UIConstants._POPUP_ICON_CIRCLE_POSY_250,
        UIConstants._POPUP_ICON_CIRCLE_POSY_96,
        UIConstants._POPUP_ICON_CIRCLE_POSY_160
    ]

    property var button_container_posY: [
        UIConstants.popup_fourth_btn_ctn_large_posY,
        UIConstants.popup_fourth_btn_ctn_large_posY,
        UIConstants.popup_fourth_btn_ctn_medium_posY,
        UIConstants.popup_fourth_btn_ctn_medium_posY
    ]

    function isOutRange(mode) {
        if (mode < 0 || mode >= 4) return true
        return false
    }

    function getPosYOfMsgCtn(mode) {
        if (isOutRange(mode)) mode = 0
        return msg_ctn_posY_type_1[mode]
    }

    function getTypeOfLoadingImg(mode) {
        if (isOutRange(mode)) mode = 0
        return circle_load_img_posY[mode]
    }

    function getPopupHeight(mode) {
        if (isOutRange(mode)) mode = 0
        return popup_height[mode]
    }

    function getBtnCtnPosY(mode) {
        if (isOutRange(mode)) mode = 0
        return button_container_posY[mode]
    }

    CRectangle{
        id: backgroundImg
        width: UIConstants._POPUP_BACKGROUND_WIDTH
        height: UIConstants._POPUP_BACKGROUND_HEIGHT
        color: UIConstants._POPUP_COLOR_TRANSPARENT
        CImage {
            id: bgrd_img
            opacity: UIConstants._POPUP_BACKGROUND_OPACITY
            source: !is_disable_background ? UIConstants._POPUP_BACKGROUND_IMAGE : ""
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
        height: getPopupHeight(type_of_mode)
        anchors {
            centerIn: (type_of_mode === 0 || type_of_mode === 1) ? parent : undefined
            horizontalCenter: parent.horizontalCenter
        }
        color: UIConstants._POPUP_COLOR_TRANSPARENT
        y: UIConstants.popup_fourth_medium_posY
        CImage {
            id: popup_image
            anchors.fill: parent
            source: type_of_mode < 1 ? UIConstants._POPUP_FRAME_784x500 : UIConstants._POPUP_FRAME_784x288
        }

        MouseArea {
            anchors.fill: parent
        }

        CRectangle {
            id: title_text
            width: UIConstants._POPUP_MSG_WIDTH
            height: UIConstants._POPUP_MSG_HEIGHT_40
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            anchors.horizontalCenter: parent.horizontalCenter
            y: UIConstants.popup_title_text_posY
            visible: type_of_mode === 0

            COMPONENTS.CText {
                id: msg_title
                msg_text: message_title
            }
        }

        CRectangle {
            id: containerMsg
            width: UIConstants._POPUP_MSG_WIDTH
            height: (type_of_mode === 2 || type_of_mode === 3) ? UIConstants.popup_msg_medium_height : UIConstants.popup_msg_ctn_height
            anchors.horizontalCenter: parent.horizontalCenter
            y: getPosYOfMsgCtn(type_of_mode)
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            COMPONENTS.CText {
                id: msg_text_1
                anchors.centerIn : !is_msg_left_align ? parent : undefined
                anchors.left: is_msg_left_align ? parent.left : undefined
                is_self_align: is_msg_left_align ? false : true
                msg_text: message_line_one
                is_wrap_text: root.using_wrap_text
            }
        }

        CRectangle {
            id: loading_img_ctn
            width: UIConstants._POPUP_ICON_CIRCLE_SIZE_80
            height: UIConstants._POPUP_ICON_CIRCLE_SIZE_80
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            anchors.horizontalCenter: parent.horizontalCenter
            y: root.getTypeOfLoadingImg(type_of_mode)
            Image {
                id: loading
                anchors.fill: parent
                source: UIConstants._POPUP_CIRCLE_LOADING_IMG
                RotationAnimator {
                    target: loading
                    from: UIConstants._POPUP_ICON_CIRCLE_LOAD_FROM_0
                    to: UIConstants._POPUP_ICON_CIRCLE_LOAD_TO_360
                    duration: duration_timer
                    running: true
                    loops: Animation.Infinite
                }
            }
        }


        CRectangle {
            id: buttonContainer
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            width: is_using_button_right ? UIConstants._POPUP_BTN_CTN_TWO_WIDTH : UIConstants._POPUP_BTN_CTN_ONE_WIDTH 
            height: UIConstants._POPUP_BTN_CTN_HEIGHT
            anchors.horizontalCenter: parent.horizontalCenter
            y: root.getBtnCtnPosY(type_of_mode)
            visible: type_of_mode === 0 || type_of_mode === 2
            RowLayout{
                spacing: UIConstants._POPUP_BTN_SPACE_16
                anchors.centerIn: parent

                ButtonWidget{
                    id: button_one
                    width: UIConstants._POPUP_BTN_WIDTH
                    height: UIConstants._POPUP_BTN_HEIGHT
                    isObject: false
                    isFixSizeBackGround: true
                    normalSource: root.img_left_button
                    pressedSource: UIConstants._POPUP_BTN_BGRD_PRESSDED
                    extendTouchAreaFromHorizontalCenter: UIConstants._POPUP_BTN_EXTEND_TOUCH_AREA
                    onClicked: {
                        root.leftClicked()
                    }
                    onPressed: {
                        background_color.source = img_left_button_pressed
                        root.leftPressed()
                    }
                    onReleased: {
                        background_color.source = img_left_button
                        root.leftReleased()
                    }


                    COMPONENTS.CText {
                        id: msg_btn_1
                        anchors.centerIn: parent
                        msg_text: message_left_button
                        is_button: true
                    }
                }

                ButtonWidget{
                    id: button_two
                    width: UIConstants._POPUP_BTN_WIDTH
                    height: UIConstants._POPUP_BTN_HEIGHT
                    visible: is_using_button_right
                    isObject: false
                    isFixSizeBackGround: true
                    normalSource: root.img_left_button
                    pressedSource: UIConstants._POPUP_BTN_BGRD_PRESSDED
                    extendTouchAreaFromHorizontalCenter: UIConstants._POPUP_BTN_EXTEND_TOUCH_AREA
                    onClicked: {
                        root.rightClicked()
                    }
                    onPressed: {
                        background_color_.source = img_right_button_pressed
                        root.rightPressed()
                    }
                    onReleased: {
                        background_color_.source = img_right_button
                        root.rightReleased()
                    }


                    COMPONENTS.CText {
                        id: msg_btn_
                        anchors.centerIn: parent
                        msg_text: message_right_button
                        is_button: true
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        animation.start()
    }

    ParallelAnimation{
        id: animation
        NumberAnimation{
            target      : root
            property    :"opacity"
            from        : 0
            to          : 1
            duration    : 200
            easing.type : Easing.InCubic
        }
        NumberAnimation{
            target      : root
            property    :"scale"
            from        : 0.9
            to          : 1
            duration    : 200
            easing.type : Easing.InCubic
        }
    }
}

