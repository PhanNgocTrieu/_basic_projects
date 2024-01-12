import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import UICommon.Base
import UICommon.CItems

import "Components" as COMPONENTS

/*
    Guidance for using:
        This qml defines template popoups includes:
            Type 0: (784x500)
                ---------------------------
                -------- { Text } ---------
                ------- { Button } --------
                ---------------------------

            Type 1: (784x500)
                ---------------------------
                -------- { Text } ---------
                -- { Button } { Button } --     (Please note if using right button -> let turn on the right button by using variable is_using_button_right)
                ---------------------------

            Type 2: (784x216) -> Middle Screen
                ---------------------------
                -------- { Text } ---------
                -- { Button } { Button } --     (Please note if using right button -> let turn on the right button by using variable is_using_button_right)
                ---------------------------

            Type 3: (784x216) -> Bottom Screen
                ---------------------------
                ---------------------------
                -------- { Text } ---------
                -- { Button } { Button } --     (Please note if using right button -> let turn on the right button by using variable is_using_button_right)
                ---------------------------

            Type 4: (784x288) -> Bottom Screen
                ---------------------------
                ---------------------------
                -------- { Text } ---------
                ------- { Button } --------
                ---------------------------

            Type 5: (784x288) -> Bottom Screen
                ---------------------------
                ---------------------------
                -------- { Text } ---------
                ---  { Icon - Button } ---
                ---------------------------

            Type 6: (784x288) -> Bottom Screen
                ---------------------------
                ---------------------------
                -------- { Text } ---------
                --- { Button }{ Button } ---
                ---------------------------

            Type 7: (784x256) -> Bottom Screen
                -------- { Text } ---------
                -------- { Text } ---------
                -------- { Text } ---------
                --- { Button }{ Button }---
                ---------------------------
            Type 8: (784x288) -> Bottom Screen
                -------- { Text } ---------
                -------- { Text } ---------
                ------- { Button } --------
                ---------------------------
            Type 9: (784x216) -> Bottom Screen
                -------- { Text } ---------
                -------- { Text } ---------
                ---{ Button } { Button } --
                ---------------------------
            Type 10: (784x366) -> Bottom Screen
                --- { Seperated Text } ----
                ---------------------------
                -------- { Text } ---------
                -------- { Text } ---------
                -------- { Text } ---------
                ---{ Button } { Button } --
                ---------------------------
            Type 11: (784x500) -> Middle Screen
                -------- { Text } ---------
                -------- { Text } ---------
                -------- { Text } ---------
                ---{ Button } { Button } --
                ---------------------------
            Type 12: (784x500) -> Middle Screen
                -------- { Text } ---------
                -------- { Text } ---------
                ---{ Button } { Button } --
                ---------------------------
            Type 15: (784x312) -> Bottom Screen
                -------- { Text } ---------
                -------- { Text } ---------
                -------- { Text } ---------
                ---{ Button } { Button } --
                ---------------------------
            Type 17: (784x312) -> Bottom Screen
                -------- { Text } ---------
                -------- { Text } ---------
                -------- { Text } ---------
                ------- { Button } --------
                ---------------------------
            Type 18: (784x272) -> Bottom Screen
                -------- { Text } ---------
                -------- { Text } ---------
                ------- { Button } --------
                ---------------------------
            Type 20: (784x272) -> Middle Screen
                ---------------------------
                -------- { Text } ---------
                -------- { Text } ---------
                ---{ Button } { Button } --
                ---------------------------
            Type 21: (784x312) -> Middle Screen
                ---------------------------
                -------- { Text } ---------
                -------- { Text } ---------
                -------- { Text } ---------
                ------- { Button } --------
                ---------------------------
            Type 22: (784x272) -> Middle Screen
                ---------------------------
                -------- { Text } ---------
                -------- { Text } ---------
                ------- { Button } --------
                ---------------------------
        Note:
            With Text Message -> Currently, If your popup has 3 lines of message -> put 3 of them in one line and using '\n' to seperate it
            If your message text in seperate in mult-languages for each line -> using the number of lines you need

            When using the button with red background -> change the color of the background of the button (img_left_button variable)
*/

Item{
    id: root
    property int type_of_mode: 0
    property bool is_disable_background: false

    /* This flag for change the left button's background to red */
    property bool is_red_button: false

    /* This flag for using the sound when opening opup */
    property bool is_use_pop_sound: false

    /* This flag for aligning the message text to left */
    property bool is_msg_left_align: false

    /* This property for display message */
    property string message_line_seperated: "{Message text}"
    property string message_line_one: "{Message text}"
    property string message_line_two: "{Message text}"
    property string message_line_three: "{Message text}"
    property string message_line_fourth: "{Message text}"

    /* This property for display left button's label */
    property string message_left_button: "{Button text}"
    /* This property for display right button's label */
    property string message_right_button: "{Button text}"
    /* This property for using icon's image */
    property string source_button_icon: ""

    /* This property for wrapping text */
    property bool using_wrap_text: false

    property bool is_visible_two_button: true

    property bool isApplyTwoLineForThreeLine: false
    // signals
    signal clickedOnMask()
    signal leftBtnClicked()
    signal leftBtnPressed()
    signal leftBtnReleased()
    signal rightBtnClicked()
    signal rightBtnPressed()
    signal rightBtnReleased()

    signal clickedOnPopup()

    CItem {
        anchors.fill: parent
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
                onClicked:{ root.clickedOnMask(); }
            }
        }

        Component {
            id: popComp
            CItem {
                id: popCnt
                required property var model
                property bool isCenter: model.kind_of_popup !== 0 ? false : true
                property bool isAndroidAuto: model.isAndroidAuto !== undefined ? model.isAndroidAuto : false
                property string popup_src: model.popup_src !== undefined ? model.popup_src : UIConstants._POPUP_FRAME_784x500
                property int pos_y: model.pos_y !== undefined ? model.pos_y : UIConstants._POPUP_POSY_110
                
                property int msg_seperated_posy: model.msg_seperated_posy !== undefined ? model.msg_seperated_posy : 0
                property int msg_ctn_height: model.msg_ctn_height !== undefined ? model.msg_ctn_height : UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_posy: model.msg_ctn_posy !== undefined ? model.msg_ctn_posy : UIConstants._POPUP_MSG_CTN_POSY_96
                property bool is_use_seperated_message: model.is_use_seperated_message !== undefined ? model.is_use_seperated_message : false
                property bool is_use_seperated_message_2: model.is_use_seperated_message_2 !== undefined ? model.is_use_seperated_message_2 : false
                property bool is_use_first_message: model.is_use_first_message !== undefined ? model.is_use_first_message : true
                property bool is_use_second_message: model.is_use_second_message !== undefined ? model.is_use_second_message : false
                property bool is_use_third_message: model.is_use_third_message !== undefined ? model.is_use_third_message : false
                property bool is_use_fourth_message: model.is_use_fourth_message !== undefined ? model.is_use_fourth_message : false
                property bool msg_is_left_align: model.msg_is_left_align !== undefined ? model.msg_is_left_align : false

                property int btn_ctn_width: model.btn_ctn_width !== undefined ? model.btn_ctn_width : UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property int btn_ctn_btm_align: model.btn_ctn_btm_align !== undefined ? model.btn_ctn_btm_align : 0
                property string btn_left_src: root.is_red_button ? UIConstants.button_red_240x80 : UIConstants.button_normal_240x80
                property string icon_src: model.icon_src !== undefined ? model.icon_src : ""
                
                /* This flag for using icon beside button */
                property bool is_visible_button_icon: model.is_visible_button_icon !== undefined ? model.is_visible_button_icon : false
                property bool is_use_second_button: model.is_use_second_button !== undefined ? model.is_use_second_button : false
                
                width: UIConstants._POPUP_WIDTH
                height: model.height
                y: popCnt.pos_y
                anchors.horizontalCenter: parent.horizontalCenter
                
                onIsAndroidAutoChanged: {
                    root.source_button_icon = UIConstants.androidAuto
                }

                CImage {
                    id: popup_image
                    anchors.fill: parent
//                    source: type_of_mode ==7 ? UIConstants._POPUP_FRAME_784x256 : type_of_mode == 3 ? UIConstants._POPUP_FRAME_784x216 : type_of_mode <= 1 ? UIConstants._POPUP_FRAME_784x500 : UIConstants._POPUP_FRAME_784x288
                    source: popCnt.typePopup()
                }
                function typePopup() {
                    if(type_of_mode ==7){
                        return UIConstants._POPUP_FRAME_784x256
                    }
                    else if(type_of_mode == 3){
                        return UIConstants._POPUP_FRAME_784x216
                    }
                    else if(type_of_mode <= 1){
                        return UIConstants._POPUP_FRAME_784x500
                    }
                    else if(type_of_mode == 15)
                    {
                        return UIConstants._POPUP_FRAME_784x312
                    }
                    else if(type_of_mode == 16){
                        return UIConstants._POPUP_FRAME_784x500
                    }
                    else if(type_of_mode == 17)
                    {
                        return UIConstants._POPUP_FRAME_784x312
                    }
                    else if(type_of_mode == 18)
                    {
                        return UIConstants._POPUP_FRAME_784x272
                    }
                    else if(type_of_mode == 19)
                    {
                        return UIConstants._POPUP_FRAME_784x312
                    }
                    else {
                        return UIConstants._POPUP_FRAME_784x288
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: { root.clickedOnPopup() }
                }

                CItem {
                    id: seperated_msg
                    width: UIConstants._POPUP_MSG_WIDTH_720
                    height: is_use_seperated_message_2 ? UIConstants._POPUP_MSG_HEIGHT_120 : UIConstants._POPUP_MSG_HEIGHT_40
                    y: popCnt.msg_seperated_posy
                    anchors.horizontalCenter: parent.horizontalCenter
                    CText {
                        anchors.centerIn: parent
                        visible: popCnt.is_use_seperated_message ? true : (is_use_seperated_message_2 ? true : false)
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        width: UIConstants._POPUP_MSG_WIDTH
                        text: qsTrId(root.message_line_seperated)
                        _font: CFont._BODY
                        color: UIConstants._POPUP_COLOR_WHITE
                    }
                }

                //CRectangle {
                CItem {
                    id: ctn_msg
                    y: popCnt.msg_ctn_posy
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: UIConstants._POPUP_MSG_WIDTH
                    height: popCnt.msg_ctn_height
                    ColumnLayout {
//                        anchors.centerIn: parent
                        anchors.horizontalCenter: parent.horizontalCenter
                        spacing: 0
                        CText {
                            textID: root.message_line_one
                            Layout.alignment: Qt.AlignCenter
                            visible: popCnt.is_use_first_message
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            width: UIConstants._POPUP_MSG_WIDTH
                            text: qsTrId(root.message_line_one)
                            _font: CFont._BODY
                            color: UIConstants._POPUP_COLOR_WHITE
                        }
                        CText {
                            textID: (root.message_line_two)
                            Layout.alignment: Qt.AlignCenter
                            visible: popCnt.is_use_second_message
                            width: parent.width
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            text: qsTrId(root.message_line_two)
                            _font: CFont._BODY
                            color: UIConstants._POPUP_COLOR_WHITE
                        }
                        CText {
                            textID: root.message_line_three
                            Layout.alignment: Qt.AlignCenter
                            visible: popCnt.is_use_third_message
                            width: parent.width
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            text: qsTrId(root.message_line_three)
                            _font: CFont._BODY
                            color: UIConstants._POPUP_COLOR_WHITE
                        }
                        CText {
                            textID: root.message_line_three
                            Layout.alignment: Qt.AlignCenter
                            visible: popCnt.is_use_fourth_message
                            width: parent.width
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            text: qsTrId(root.message_line_three)
                            _font: CFont._BODY
                            color: UIConstants._POPUP_COLOR_WHITE
                        }
                    }
                }

                CRectangle {
                    id: buttonContainer
                    color: UIConstants._POPUP_COLOR_TRANSPARENT
                    width: popCnt.btn_ctn_width
                    height: UIConstants._POPUP_BTN_CTN_HEIGHT
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors {
                        bottom: parent.bottom
                        bottomMargin: popCnt.btn_ctn_btm_align
                    }
                    visible: is_visible_two_button
                    
                    CRowLayout{
                        spacing: UIConstants._POPUP_BTN_SPACE_16
                        anchors.centerIn: buttonContainer

                        ButtonWidget{

                        ButtonWidget{
                            id: button_one
                            width: UIConstants._POPUP_BTN_WIDTH
                            height: UIConstants._POPUP_BTN_HEIGHT
                            radius: UIConstants._POPUP_BTN_RADIUS
                            isObject: false
                            isFixSizeBackGround: true
                            normalSource: popCnt.btn_left_src
                            pressedSource: UIConstants.button_pressed_240x80
                            inActiveSource: UIConstants.button_inActive_240x80
                            extendTouchAreaFromHorizontalCenter: UIConstants._POPUP_BTN_EXTEND_TOUCH_AREA
                            onClicked: { root.leftBtnClicked(); }
                            onReleased: { root.leftBtnReleased(); }

                            CRowLayout {
                                anchors.centerIn: parent
                                spacing: UIConstants._POPUP_MSG_SPACE_4
                                Image {
                                    id: button_icon
                                    visible: popCnt.is_visible_button_icon
                                    width: UIConstants._POPUP_ICON_SIZE_40
                                    height: UIConstants._POPUP_ICON_SIZE_40
                                    source: root.source_button_icon
                                }
                                Item {
                                    id: msg_btn
                                    width: popCnt.is_visible_button_icon ? UIConstants._POPUP_BTN_TEXT_WIDTH_155 : UIConstants._POPUP_BTN_TEXT_WIDTH_216
                                    height: UIConstants._POPUP_BTN_TEXT_HEIGHT_36
                                    COMPONENTS.CText {
                                        id: button_one_text
                                        textID: root.message_left_button
                                        anchors.fill: parent
                                        verticalAlignment: Text.AlignVCenter
                                        horizontalAlignment: Text.AlignHCenter
                                        msg_text: qsTrId(root.message_left_button)
                                        is_button: true
                                    }
                                }
                            }
                        }

                        ButtonWidget{
                            id: button_two
                            width: UIConstants._POPUP_BTN_WIDTH
                            height: UIConstants._POPUP_BTN_HEIGHT
                            radius: UIConstants._POPUP_BTN_RADIUS
                            visible: popCnt.is_use_second_button
                            isObject: false
                            pressedSource: UIConstants.button_pressed_240x80
                            inActiveSource: UIConstants.button_inActive_240x80
                            normalSource: UIConstants.button_normal_240x80
                            extendTouchAreaFromHorizontalCenter: UIConstants._POPUP_BTN_EXTEND_TOUCH_AREA
                            onClicked: { root.rightBtnClicked(); }
                            onReleased: { root.rightBtnReleased(); }

                            COMPONENTS.CText {
                                id: button_two_text
                                textID: root.message_right_button
                                anchors.centerIn: parent
                                height: UIConstants._POPUP_BTN_TEXT_HEIGHT_36
                                width: UIConstants._POPUP_BTN_TEXT_WIDTH_216
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                msg_text: qsTrId(root.message_right_button)
                                is_button: true
                            }
                        }
                    }
                }
            }
        }

        Repeater {
            model: ctrlPriv._obj
            delegate: popComp
        }
    }

    QtObject {
        id: ctrlPriv
        property int kind_of_popup: root.type_of_mode
        property list<QtObject> obj_popup: [
            // Kind of Popup (0): Popup One (784x500) - One Message with One button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_500
                property int pos_y: UIConstants._POPUP_POSY_110
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_96
                property string popup_src: UIConstants._POPUP_FRAME_784x500
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_48
            },
            // Kind of Popup (1):  Popup One (784x500) - Two buttons at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_500
                property int pos_y: UIConstants._POPUP_POSY_110
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_96
                property string popup_src: UIConstants._POPUP_FRAME_784x500
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_48
                property bool is_use_second_button: true
            },
            // Kind of Popup (2):  Popup Two (784x216) - Two buttons at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_216
                property int pos_y: UIConstants._POPUP_POSY_252
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_80
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
                property bool is_use_second_button: true
            }, 
            // Kind of Popup (3):  Popup Two (784x232) - Two buttons at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_232
                property int pos_y: UIConstants._POPUP_POSY_472
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_40
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x232
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property bool is_use_second_button: true
            },
            // Kind of Popup (4):  Popup Two (784x288) - One button at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_288
                property int pos_y: UIConstants._POPUP_POSY_416
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_144
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
            },
            // Kind of Popup (5):  Popup Two (784x288) - One button and icon at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_288
                property int pos_y: UIConstants._POPUP_POSY_416
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_144
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
                property bool is_visible_button_icon: true
            },
            // Kind of Popup (6):  Popup Two (784x288) - Two button and icon at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_288
                property int pos_y: UIConstants._POPUP_POSY_416
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_144
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
                property bool is_use_second_button: true
            },
            // Kind of Popup (7):  Popup Two (784x256) - Two button and icon at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_256
                property int pos_y: UIConstants._POPUP_POSY_448
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x256
                property bool is_use_second_message: true
                property bool is_use_third_message: true
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (8):  Popup Two (784x288) - Two Message texts and one button at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_288
                property int pos_y: UIConstants._POPUP_POSY_416
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_144
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x288
                property bool is_use_second_message: true
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: false
            },
            // Kind of Popup (9):  Popup Two (784x216) - Two Message texts and two button at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_216
                property int pos_y: UIConstants._POPUP_POSY_488
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_80
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property bool is_use_second_message: true
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (10):  Popup Two (784x336) - One seperated Msg, Three Message texts and two button at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_336
                property int pos_y: UIConstants._POPUP_POSY_368
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_80
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_96
                property string popup_src: UIConstants._POPUP_FRAME_784x366
                property int msg_seperated_posy: UIConstants._POPUP_MSG_POSY_32
                property bool is_use_seperated_message: true
                property bool is_use_second_message: true
                property bool is_use_third_message: true
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_32
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (11):  Popup Two (784x500) - Three Message texts and two button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_500
                property int pos_y: UIConstants._POPUP_POSY_110
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_96
                property string popup_src: UIConstants._POPUP_FRAME_784x500
                property bool is_use_seperated_message: false
                property bool is_use_second_message: true
                property bool is_use_third_message: true
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_48
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (12):  Popup Two (784x500) - Two Message texts and two button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_500
                property int pos_y: UIConstants._POPUP_POSY_110
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_96
                property string popup_src: UIConstants._POPUP_FRAME_784x500
                property bool is_use_seperated_message: false
                property bool is_use_second_message: true
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_48
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (12):  Popup Two (784x500) - Two Message texts and two button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_500
                property int pos_y: UIConstants._POPUP_POSY_110
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_96
                property string popup_src: UIConstants._POPUP_FRAME_784x500
                property bool is_use_seperated_message: false
                property bool is_use_second_message: true
                property bool is_use_third_message: true
                property bool is_use_fourth_message: true
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_48
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (12):  Popup Two (784x288) - Android Auto Popup - at Bottom
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_288
                property int pos_y: UIConstants._POPUP_POSY_416
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_144
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_16
                property string popup_src: UIConstants._POPUP_FRAME_784x288
                property bool is_use_seperated_message: false
                property bool is_use_second_message: true
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_48
                property bool is_visible_button_icon: true
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (15): Popup Two(784x312) - Three Message texts and two buttons at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_312
                property int pos_y: UIConstants._POPUP_POSY_392
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x312
                property bool is_use_second_message: false
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (16)
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_500
                property int pos_y: UIConstants._POPUP_POSY_110
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_96
                property string popup_src: UIConstants._POPUP_FRAME_784x500
                property bool is_use_seperated_message: false
                property bool is_use_second_message: false
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_48
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: true
            },
            // Kind of Popup (17): Popup Two(784x312) - Three Message texts and one button at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_312
                property int pos_y: UIConstants._POPUP_POSY_392
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x312
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property bool is_use_second_button: false
            },
            // Kind of Popup (18): Popup Two(784x272) - Two Message texts and one button at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_272
                property int pos_y: UIConstants._POPUP_POSY_224
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_80
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x272
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property bool is_use_second_button: true
            },
            // Kind of Popup (21): Popup Two(784x312) - Three Message texts and one button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_312
                property int pos_y: UIConstants._POPUP_POSY_204
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x312
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property bool is_use_second_button: false
            },
            // Kind of Popup (22): Popup Two(784x272) - Two Message texts and one button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_272
                property int pos_y: UIConstants._POPUP_POSY_224
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_80
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x272
                property bool is_use_second_message: false
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: false
            },
            // Kind of Popup (19): Popup Two(784x312) - Two Message texts in three line text area and one button at Bottom Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_312
                property int pos_y: UIConstants._POPUP_POSY_392
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x312
                property int msg_seperated_posy: UIConstants._POPUP_MSG_POSY_48
                property bool is_use_first_message: false
                property bool is_use_second_message: false
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property bool is_use_seperated_message_2: true
                property bool is_use_seperated_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: false
            },
            // Kind of Popup (20): Popup Two(784x272) - Two Message texts in three line text area and one button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_272
                property int pos_y: UIConstants._POPUP_POSY_224
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_80
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x272
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property bool is_use_second_button: true
            },
            // Kind of Popup (21): Popup Two(784x312) - Three Message texts and one button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_312
                property int pos_y: UIConstants._POPUP_POSY_204
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x312
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property bool is_use_second_button: false
            },
            // Kind of Popup (22): Popup Two(784x272) - Two Message texts and one button at Middle Screen
            QtObject {
                property int height: UIConstants._POPUP_HEIGHT_272
                property int pos_y: UIConstants._POPUP_POSY_224
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_80
                property int msg_ctn_posy: UIConstants._POPUP_MSG_CTN_POSY_48
                property string popup_src: UIConstants._POPUP_FRAME_784x272
                property bool is_use_second_message: false
                property bool is_use_third_message: false
                property bool is_use_fourth_message: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property int btn_ctn_btm_align: UIConstants._POPUP_BTN_ALIGN_40
                property string icon_src: root.source_button_icon
                property bool is_use_second_button: false
            }
        ]
        property var _obj: ctrlPriv.obj_popup[ctrlPriv.kind_of_popup]
    }

    Component.onCompleted: {
        if (is_use_pop_sound) VehicleGeneralState.playSound(VehicleGeneralState.Popup)
        animationShow.start()
    }

    ParallelAnimation{
        id: animationShow
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

}