import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import UICommon.Base
import UICommon.CItems

import "Components" as COMPONENTS

/*
    Guidance for using:
        This qml defines template popoups includes:

            Type 0: (size: 784x500)
                -------- {Message Text} ---------

            Type 1: (size: 784x216 - Top)
                ---------------------------------
                -------- {Message Text} ---------
                ---------------------------------
                ---------------------------------

            Type 2: (size: 784x216 - Mid)
                ---------------------------------
                ---------------------------------
                -------- {Message Text} ---------
                ---------------------------------
                ---------------------------------
            
            Type 3: (size: 784x216 - Bottom)
                ---------------------------------
                ---------------------------------
                ---------------------------------
                -------- {Message Text} ---------
                ---------------------------------

            Type 4: (size: 784x296) Middle Screen
                -------- {Message Text} ---------
                -------- {Message Text} ---------
                -------- {Message Text} ---------
                -------- {Message Text} ---------
                -------- {Message Text} ---------
        Each type of popup here was selected by variable type_of_mode, note that if type_of_mode is out of range, 0 will be set default value
        Note:
            With Text Message -> Currently, If your popup has 3 lines of message -> put 3 of them in one line and using '\n' to seperate it
            If your message text is seperately in mult-languages for each line -> using the number of lines of you need (annouce me for changing format)
*/

Item{
    id: root
    /* This property for dertermine which type of popup would be used */
    property int type_of_mode: 0

    /* This property for using display message */
    property string message_line_one: "Message Text 1"

    /* This property would handle using background of popup or not */
    property bool isDisableBackground: false

    /* This property would handle the sound of opening popup */
    property bool is_use_pop_sound: false

    property bool is_msg_left_align: false

    /* This property for wrapping text */
    property bool using_wrap_text: false

    /* This signal was sent when handling with click on mask of popup */
    signal clickedOnMask()

    CItem {
        id: ctn_item
        anchors.fill: parent

        CRectangle {
            id: backgroundImg
            width: UIConstants._POPUP_BACKGROUND_WIDTH
            height: UIConstants._POPUP_BACKGROUND_HEIGHT
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            CImage {
                id: bgrd_img
                opacity: UIConstants._POPUP_BACKGROUND_OPACITY
                source: !root.isDisableBackground ? UIConstants._POPUP_BACKGROUND_IMAGE : ""
            }

            MouseArea{
                anchors.fill:parent
                onClicked:{ root.clickedOnMask(); }
            }
        }

        // Popup content
        Component {
            id: popComp
            CRectangle {
                id: popCnt
                required property var model
                property bool isCenter: model.kind_of_popup !== 0 ? false : true
                property int msg_ctn_height: model.msg_ctn_height
                property string pop_src: model.popup_src !== undefined ? model.popup_src : ""
                property string msg_text: model.msg_text
                width: model.width
                height: model.height
                anchors.horizontalCenter: parent.horizontalCenter
                y: model.pos_y
                color: UIConstants._POPUP_COLOR_TRANSPARENT
                CImage {
                    id: popup_image
                    anchors.fill: parent
                    source: popCnt.pop_src
                }

                CRectangle {
                    id: containerMsg
                    width: UIConstants._POPUP_MSG_WIDTH
                    height: popCnt.msg_ctn_height
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: model.msg_holder_pos_y
                    color: UIConstants._POPUP_COLOR_TRANSPARENT
                    COMPONENTS.CText {
                        id: msg_text_1
                        textID: popCnt.msg_text
                        anchors.centerIn : !is_msg_left_align ? parent : undefined
                        anchors.left: is_msg_left_align ? parent.left : undefined
                        is_self_align: is_msg_left_align ? false : true
                        msg_text: qsTrId(popCnt.msg_text)
                        is_wrap_text: root.using_wrap_text
                    }
                }

                MouseArea {
                    id: mouse_prevent
                    anchors.fill: parent
                    onClicked: {}
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
            // Popup One (784x500) - center
            QtObject {
                property int width: UIConstants._POPUP_WIDTH
                property int height: UIConstants._POPUP_HEIGHT_500
                property int pos_y: UIConstants._POPUP_POSY_110
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property string popup_src: UIConstants._POPUP_FRAME_784x500
                property string msg_text: root.message_line_one
                property int msg_holder_pos_y: UIConstants._POPUP_MSG_HOLDER_POS_Y_144
            },
            // Popup Two (784x216) - Top
            QtObject {
                property int width: UIConstants._POPUP_WIDTH
                property int height: UIConstants._POPUP_HEIGHT_216
                property int pos_y: UIConstants._POPUP_POSY_80
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_184
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property string msg_text: root.message_line_one
                property int msg_holder_pos_y: UIConstants._POPUP_MSG_HOLDER_POS_Y_16
            }, 
            // Popup Two (784x216) - Mid
            QtObject {
                property int width: UIConstants._POPUP_WIDTH
                property int height: UIConstants._POPUP_HEIGHT_216
                property int pos_y: UIConstants._POPUP_POSY_252
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_184
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property string msg_text: root.message_line_one
                property int msg_holder_pos_y: UIConstants._POPUP_MSG_HOLDER_POS_Y_16
            },
            // Popup Two (784x216) - Bottom
            QtObject {
                property int width: UIConstants._POPUP_WIDTH
                property int height: UIConstants._POPUP_HEIGHT_216
                property int pos_y: UIConstants._POPUP_POSY_488
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_184
                property string popup_src: UIConstants._POPUP_FRAME_784x216
                property string msg_text: root.message_line_one
                property int msg_holder_pos_y: UIConstants._POPUP_MSG_HOLDER_POS_Y_16
            },
            // Popup Four (784x296) - center
            QtObject {
                property int width: UIConstants._POPUP_WIDTH
                property int height: UIConstants._POPUP_HEIGHT_296
                property int pos_y: UIConstants._POPUP_POSY_212
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property string popup_src: UIConstants._POPUP_FRAME_784x296
                property string msg_text: root.message_line_one
                property int msg_holder_pos_y: UIConstants._POPUP_MSG_CTN_POSY_48
            }
        ]
        property var _obj: ctrlPriv.obj_popup[ctrlPriv.kind_of_popup]
    }

    Component.onCompleted: {
        if (is_use_pop_sound) VehicleGeneralState.playSound(VehicleGeneralState.Popup)
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

