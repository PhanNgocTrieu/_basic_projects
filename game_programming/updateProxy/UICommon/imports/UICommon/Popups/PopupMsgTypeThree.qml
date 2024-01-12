import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import UICommon.Base
import UICommon.CItems
import "Components" as COMPONENTS
/*
    Guidance for using:
        This qml defines template popoups includes: (chosing mode from setting type_of_mode variable (0 as default))
            type_of_mode == 0 (size: 784x500)
                --------     {Title}    ---------
                --------     {Icon}     ---------
                -------- {Message Text} ---------           // Using message_frist_line
                -------- {Button  Text} ---------

            type_of_mode == 1 (size: 784x500)
                --------     {Icon}     ---------    
                -------- {Message Text} ---------           // Using message_frist_line
                -------- {Button  Text} ---------

            type_of_mode == 2 (size: 784x500)
                --------     {Icon}     ---------    
                -------- {Message Text} ---------           // Using message_frist_line
                - {Button  Text} {Button  Text} -

            type_of_mode == 3 (size: 784x500)
                --------     {Icon}     ---------    
                --- {Seperated Message Text} ----           // Using message_seperated_line
                ---------------------------------
                -------- {Message Text} ---------           // Using message_first_line
                -------- {Message Text} ---------           // Using message_second_line
                -------- {Message Text} ---------           // Using message_third_line
                - {Button  Text} {Button  Text} -
            
            type_of_mode == 4 (size: 784x500)
                --------     {Icon}     ---------    
                -------- {Message Text} ---------           // Using message_first_line

        Note:
            With Text Message -> Currently, If your popup has 3 lines of message -> put 3 of them in one line and using '\n' to seperate it
            If your message text in seperate in mult-languages for each line -> using the number of lines you need
*/

Item{
    id: root
    // ==========> Mode of Popup Variable List <=================
    property int type_of_mode: 0
    property bool is_disable_background: false
    property bool is_msg_left_align: false

    // ==========> Title Icon Variable List <=================
    property string title_icon_source: ""
    property string message_title: "{Title}"
    property string message_line_one: "{Message Text}"

    // ==========> Message Variable List <=================
    property string message_seperated_line: "{Seperated text}"
    property string message_first_line: "{Message text}"
    property string message_second_line: "{Message text}"
    property string message_third_line: "{Message text}"

    // ==========> Title Butoon Variable List <=================
    // property string img_left_button_normal: UIConstants._POPUP_BTN_BGRD_NORMAL
    property string message_left_button: "Button text"
    property string message_right_button: "Button text"

    /* This property for wrapping text */
    property bool using_wrap_text: false

    // signals
    signal clickedOnMask()
    signal leftClicked()
    signal leftPressed()
    signal leftReleased()
    signal rightClicked()
    signal rightPressed()
    signal rightReleased()

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
                property bool title_visible: model.title_visible !== undefined ? model.title_visible : false
                property int icon_posy: model.icon_posy !== undefined ? icon_posy : 0
                property int icon_posx: model.icon_posx !== undefined ? icon_posx : 0
                property int icon_top_margin: model.icon_top_margin !== undefined ? model.model.icon_top_margin : undefined
                property int icon_left_margin: model.icon_left_margin !== undefined ? model.model.icon_left_margin : undefined
                
                property int msg_ctn_top_margin: model.msg_ctn_top_margin !== undefined ? model.msg_ctn_top_margin : undefined
                property int msg_ctn_height: model.msg_ctn_height !== undefined ? model.msg_ctn_height : UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property int msg_ctn_left_margin: model.msg_ctn_left_margin !== undefined ? model.msg_ctn_left_margin : -1
                property bool msg_seperated_line_visible: model.msg_seperated_line_visible !== undefined ? model.msg_seperated_line_visible : false
                property bool msg_first_line_visible: model.msg_first_line_visible !== undefined ? model.msg_first_line_visible : true
                property bool msg_second_line_visible: model.msg_second_line_visible ? model.msg_second_line_visible : false
                property bool msg_third_line_visible: model.msg_third_line_visible ? model.msg_third_line_visible : false
                
                property int btn_visible: model.btn_visible ? model.btn_visible : false
                property int btn_right_visible: model.btn_right_visible ? model.btn_right_visible : false
                property int btn_ctn_width: model.btn_ctn_width !== undefined ? model.btn_ctn_width : UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                
                width: UIConstants._POPUP_WIDTH
                height: UIConstants._POPUP_HEIGHT_500
                y: UIConstants._POPUP_POSY_110
                anchors.horizontalCenter: parent.horizontalCenter

                MouseArea {
                    anchors.fill: parent
                }

                CImage {
                    id: popup_image
                    anchors.fill: parent
                    source: UIConstants._POPUP_FRAME_784x500
                    MouseArea {
                        anchors.fill: parent
                    }
                }

                CRectangle {
                    id: title_txt
                    visible: popCnt.title_visible
                    width: UIConstants._POPUP_MSG_WIDTH
                    height: UIConstants._POPUP_MSG_HEIGHT_40
                    color: UIConstants._POPUP_COLOR_TRANSPARENT
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        top: parent.top
                        topMargin: UIConstants._POPUP_MSG_CTN_TOPMARGIN_60
                    }
                    COMPONENTS.CText {
                        anchors.centerIn: parent
                        msg_text: message_title
                    }
                }

                // Seperated Text
                CRectangle {
                    id: seperated_txt
                    width: UIConstants._POPUP_MSG_WIDTH_720
                    height: UIConstants._POPUP_MSG_HEIGHT_40
                    visible: popCnt.msg_seperated_line_visible
                    color: UIConstants._POPUP_COLOR_TRANSPARENT
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        top: parent.top
                        topMargin: UIConstants._POPUP_MSG_TOPMARGIN_168
                    }
                    COMPONENTS.CText {
                        anchors.centerIn: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        msg_text: qsTrId(root.message_seperated_line)
                    }
                }
                


                CRectangle {
                    id: icon_ctn
                    width: UIConstants._POPUP_ICON_SIZE_120
                    height: UIConstants._POPUP_ICON_SIZE_120
                    color: UIConstants._POPUP_COLOR_TRANSPARENT
                    anchors {
                        top: parent.top
                        topMargin: popCnt.icon_top_margin
                        left: parent.left
                        leftMargin: popCnt.icon_left_margin
                    }
                    CImage {
                        id: icon_img
                        anchors.fill: parent
                        source: root.title_icon_source
                    }
                }
                // Container of Message
                CRectangle {
                    id: ctn_msg
                    anchors {
                        horizontalCenter: msg_ctn_left_margin != -1 ?  undefined : popCnt.horizontalCenter
                        top: icon_ctn.bottom
                        topMargin: popCnt.msg_ctn_top_margin
                        left: popCnt.msg_ctn_left_margin != -1 ? popCnt.left : undefined
                        leftMargin: popCnt.msg_ctn_left_margin != -1 ? popCnt.msg_ctn_left_margin : undefined
                    }
                    width: UIConstants._POPUP_MSG_WIDTH
                    height: popCnt.msg_ctn_height
                    color: UIConstants._POPUP_COLOR_TRANSPARENT
                    ColumnLayout {
                        anchors.centerIn: parent
                        spacing: 0
                        CText {
                            textID: (root.message_first_line)
                            Layout.alignment: Qt.AlignCenter
                            visible: popCnt.msg_first_line_visible
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            width: UIConstants._POPUP_MSG_WIDTH
                            text: qsTrId(root.message_first_line)
                            _font: CFont._BODY
                            color: UIConstants._POPUP_COLOR_WHITE
                        }
                        CText {
                            textID: (root.message_second_line)
                            Layout.alignment: Qt.AlignCenter
                            visible: popCnt.msg_second_line_visible
                            width: parent.width
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            text: qsTrId(root.message_second_line)
                            _font: CFont._BODY
                            color: UIConstants._POPUP_COLOR_WHITE
                        }
                        CText {
                            textID: (root.message_third_line)
                            Layout.alignment: Qt.AlignCenter
                            visible: popCnt.msg_third_line_visible
                            width: parent.width
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            text: qsTrId(root.message_third_line)
                            _font: CFont._BODY
                            color: UIConstants._POPUP_COLOR_WHITE
                        }
                    }
                }
                

                CRectangle {
                    id: btn_ctn
                    visible: popCnt.btn_visible
                    width: popCnt.btn_ctn_width
                    height: UIConstants._POPUP_BTN_CTN_HEIGHT
                    color: UIConstants._POPUP_COLOR_TRANSPARENT
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        bottom: parent.bottom
                        bottomMargin: UIConstants._POPUP_BTN_BOTTOMMARGIN_48
                    }
                    CRowLayout {
                        spacing: UIConstants._POPUP_BTN_SPACE_16
                        anchors.centerIn: parent

                        ButtonWidget{
                            id: button_one
                            width: UIConstants._POPUP_BTN_WIDTH
                            height: UIConstants._POPUP_BTN_HEIGHT
                            radius: UIConstants._POPUP_BTN_RADIUS
                            isObject: false
                            isFixSizeBackGround: true
                            normalSource: UIConstants._POPUP_BTN_BGRD_NORMAL
                            pressedSource: UIConstants._POPUP_BTN_BGRD_PRESSDED
                            extendTouchAreaFromHorizontalCenter: UIConstants._POPUP_BTN_EXTEND_TOUCH_AREA
                            onClicked: { root.leftClicked() }
                            onPressed: { root.leftPressed() }
                            onReleased: { root.leftReleased() }

                            COMPONENTS.CText {
                                textID: root.message_left_button
                                height: UIConstants._POPUP_BTN_TEXT_HEIGHT_36
                                width: UIConstants._POPUP_BTN_TEXT_WIDTH_216
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                anchors.centerIn: parent
                                is_button: true
                                msg_text: qsTrId(root.message_left_button)
                            }
                        }

                        ButtonWidget{
                            id: button_two
                            width: UIConstants._POPUP_BTN_WIDTH
                            height: UIConstants._POPUP_BTN_HEIGHT
                            visible: popCnt.btn_right_visible
                            isObject: false
                            isFixSizeBackGround: true
                            normalSource: UIConstants._POPUP_BTN_BGRD_NORMAL
                            pressedSource: UIConstants._POPUP_BTN_BGRD_PRESSDED
                            extendTouchAreaFromHorizontalCenter: UIConstants._POPUP_BTN_EXTEND_TOUCH_AREA
                            onClicked: { root.rightClicked() }
                            onPressed: { root.rightPressed() }
                            onReleased: { root.rightReleased() }

                            COMPONENTS.CText {
                                textID: root.message_right_button
                                anchors.centerIn: parent
                                height: UIConstants._POPUP_BTN_TEXT_HEIGHT_36
                                width: UIConstants._POPUP_BTN_TEXT_WIDTH_216
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                is_button: true
                                msg_text: root.message_right_button
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
            // Kind of Popup (0) : Popup One (784x500) - Tile, Icon, One Line of Message and One button
            QtObject {
                property bool title_visible: true
                property int icon_top_margin: UIConstants._POPUP_ICON_TITLE_TOPMARGIN_120
                property int icon_left_margin: UIConstants._POPUP_ICON_TITLE_LEFTMARGIN_333
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_left_margin:  UIConstants._POPUP_MSG_CTN_LEFTMARGIN_49
                property bool msg_seperated_line_visible: false
                property bool msg_first_line_visible: true
                property bool msg_second_line_visible: false
                property bool msg_third_line_visible: false
                property int msg_ctn_top_margin: UIConstants._POPUP_MSG_CTN_TOPMARGIN_0
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property bool btn_visible: true
                property bool btn_right_visible: false
            },
            // Kind of Popup (1) :  Popup Two (784x500) - Icon, One Line of Message and One Button
            QtObject {
                property bool title_visible: false
                property int icon_top_margin: UIConstants._POPUP_ICON_TITLE_TOPMARGIN_90
                property int icon_left_margin: UIConstants._POPUP_ICON_TITLE_LEFTMARGIN_333
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_left_margin:  UIConstants._POPUP_MSG_CTN_LEFTMARGIN_49
                property bool msg_seperated_line_visible: false
                property bool msg_first_line_visible: true
                property bool msg_second_line_visible: false
                property bool msg_third_line_visible: false
                property int msg_ctn_top_margin: UIConstants._POPUP_MSG_CTN_TOPMARGIN_0
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_ONE_WIDTH
                property bool btn_visible: true
                property bool btn_right_visible: false
            },
            // Kind of Popup (2) :  Popup Three (784x500) - Icon, One line of message and Two Buttons
            QtObject {
                property bool title_visible: false
                property int icon_top_margin:UIConstants._POPUP_ICON_TITLE_TOPMARGIN_32
                property int icon_left_margin:UIConstants._POPUP_ICON_TITLE_LEFTMARGIN_332
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_200
                property bool msg_seperated_line_visible: false
                property bool msg_first_line_visible: true
                property bool msg_second_line_visible: false
                property bool msg_third_line_visible: false
                property int msg_ctn_top_margin: UIConstants._POPUP_MSG_CTN_TOPMARGIN_0
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property bool btn_visible: true
                property bool btn_right_visible: true
            },
             // Kind of Popup (3) :  Popup Fourth (784x500) - Icon, Seperated Message, Three lines of message and Two Buttons
            QtObject { 
                property bool title_visible: false
                property int icon_top_margin: UIConstants._POPUP_ICON_TITLE_TOPMARGIN_32
                property int icon_left_margin: UIConstants._POPUP_ICON_TITLE_LEFTMARGIN_332
                property int msg_ctn_top_margin: UIConstants._POPUP_MSG_CTN_TOPMARGIN_80
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property bool msg_seperated_line_visible: true
                property bool msg_first_line_visible: true
                property bool msg_second_line_visible: true
                property bool msg_third_line_visible: true
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property bool btn_visible: true
                property bool btn_right_visible: true
            },
             // Kind of Popup (4) :  Popup Fourth (784x500) - Icon and One lines of message
            QtObject { 
                property bool title_visible: false
                property int icon_top_margin: UIConstants._POPUP_ICON_TITLE_TOPMARGIN_120
                property int icon_left_margin: UIConstants._POPUP_ICON_TITLE_LEFTMARGIN_333
                property int msg_ctn_top_margin: UIConstants._POPUP_MSG_CTN_TOPMARGIN_0
                property int msg_ctn_height: UIConstants._POPUP_MSG_CTN_HEIGHT_120
                property int msg_ctn_left_margin: UIConstants._POPUP_MSG_CTN_LEFTMARGIN_49
                property bool msg_seperated_line_visible: false
                property bool msg_first_line_visible: true
                property bool msg_second_line_visible: false
                property bool msg_third_line_visible: false
                property int btn_ctn_width: UIConstants._POPUP_BTN_CTN_TWO_WIDTH
                property bool btn_visible: false
                property bool btn_right_visible: false
            }
        ]
        property var _obj: ctrlPriv.obj_popup[ctrlPriv.kind_of_popup]
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

