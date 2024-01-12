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
*/
Item {
    id: root
    property int type_of_mode: 0
    property string message_line_one: "Message Text"
    property int slider_current_value: 20
    property int slider_min: 0
    property int slider_max: 100
    property string message_button: "Button Text"
    property string img_button: UIConstants._POPUP_BTN_BGRD_NORMAL
    property string img_button_pressed: UIConstants._POPUP_BTN_BGRD_PRESSDED
    property bool isDisableBackground: false
    /**
    * @brief model for listview
    */
    property var model
    signal clicked()
    signal released()
    signal pressed()

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
        height: UIConstants._POPUP_HEIGHT_500
        anchors.centerIn: parent
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
            id: title_rec
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            width: 720
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 34   
            COMPONENTS.CText {
                id: title_lbl
                anchors.fill: parent
                msg_text: "Title_text"
                msg_size: 26
            }
        }

        CRectangle {
            id: scroll_bar_ctn
            width: 688 + 31 + 2
            height: 320
            color: UIConstants._POPUP_COLOR_TRANSPARENT
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 80
            }

            // ListView {
            //     anchors.fill: parent
            //     model: model_list
            //     delegate: Rectangle {
            //         width: parent.width
            //         height: 30
            //         color: UIConstants._POPUP_COLOR_TRANSPARENT
            //         COMPONENTS.CText {
            //             anchors.fill: parent
            //             msg_text: "msg_text"
            //             msg_size: 26
            //         }
            //     }
            //     focus: true
            // }

            ListModel {
                id: model_list
            }
        }

        CRectangle {
            id: btn_ctn
            width: UIConstants._POPUP_BTN_WIDTH
            height: UIConstants._POPUP_BTN_HEIGHT
            anchors {
                horizontalCenter: parent.horizontalCenter
                bottom: parent.bottom
                bottomMargin: 31
            }
            color: UIConstants._POPUP_COLOR_TRANSPARENT

            CImage {
                id: background_color
                anchors.fill: parent
                source: btn_mouse.pressed ? _POPUP_BTN_BGRD_PRESSDED : img_button
            }

            COMPONENTS.CText {
                id: btn_lbl
                anchors.fill: parent
                msg_text: "Button_text"
                msg_size: 26
            }

            CMouseArea {
                id: btn_mouse
                anchors.fill: parent
                onPress: {
                    console.log("onPress")
                    root.pressed()
                }
                onReleased: {
                    console.log("onReleased")
                    root.released()
                }
                onClicked: {
                    console.log("onClicked")
                    root.clicked()
                }
            }
        }
    }
}
