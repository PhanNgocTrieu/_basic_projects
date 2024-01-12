pragma Singleton
import QtQuick 2.15
import UICommon.Base

QtObject {
    property int demo: 1
    readonly property int hmi_width: 1280
    readonly property int hmi_height: 720
    readonly property int app_13_width: 368
    readonly property int app_13_height: 624
    readonly property int app_23_width: 752
    readonly property int app_23_height: 624
    readonly property int app_33_width: 1008
    readonly property int app_33_height: 624

    /************************************ Constant Declerations ********************************/
    // Resources




    readonly property string    _BUTTON_240x50_NORMAL_BACKGROUND   : "qrc:/qt-project.org/imports/UICommon/Popups/Button_240x50_normal.png"
    readonly property string    _BUTTON_240x50_PRESSED_BACKGROUND  : "qrc:/qt-project.org/imports/UICommon/Popups/Button_240x50_pressed.png"
    readonly property string    _BUTTON_240x50_INACTIVE_BACKGROUND : "qrc:/qt-project.org/imports/UICommon/Popups/Button_240x50_inactive.png"
    readonly property string    _FADER: "qrc:/qt-project.org/imports/UICommon/Popups/Gradiant_Fade.png"
    readonly property string    _FADER_TOP: "qrc:/qt-project.org/imports/UICommon/Popups/Fade_Top.png"
    readonly property string    _FADER_MID: "qrc:/qt-project.org/imports/UICommon/Popups/Fade_Mid.png"
    readonly property string    _FADER_BOTTOM: "qrc:/qt-project.org/imports/UICommon/Popups/Fade_Bottom.png"
    readonly property string    _POPUP_FRAME_784x500: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x500.png"
    readonly property string    _POPUP_FRAME_784x366: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x288.png"
    readonly property string    _POPUP_FRAME_784x344: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x344.png"
    readonly property string    _POPUP_FRAME_784x304: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x304.png"
    readonly property string    _POPUP_FRAME_784x296: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x296.png"
    readonly property string    _POPUP_FRAME_784x288: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x288.png"
    readonly property string    _POPUP_FRAME_784x256: "qrc:/qt-project.org/imports/UICommon/Popups/imports/UICommon/Resources/bgrd_popup_784x256.png"
    readonly property string    _POPUP_FRAME_784x216: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x216.png"
    readonly property string    _POPUP_FRAME_784x312: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x312.png"
    readonly property string    _POPUP_FRAME_784x272: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x272.png"
    readonly property string    _POPUP_FRAME_784x232: "qrc:/qt-project.org/imports/UICommon/Popups/bgrd_popup_784x232.png"
    readonly property string    _POPUP_BTN_BGRD_NORMAL: "qrc:/qt-project.org/imports/UICommon/Popups/button_normal.png"
    readonly property string    _POPUP_BTN_BGRD_NORMAL_SECOND_VER: "qrc:/qt-project.org/imports/UICommon/Popups/button_normal_2.png"
    readonly property string    _POPUP_BTN_BGRD_RED_NORMAL: "qrc:/qt-project.org/imports/UICommon/Resources/button_red.png"
    readonly property string    _POPUP_BTN_BGRD_PRESSDED: "qrc:/qt-project.org/imports/UICommon/Popups/button_pressed.png"
    readonly property string    _POPUP_BACKGROUND_IMAGE: "qrc:/qt-project.org/imports/UICommon/Popups/MaskPopup.png"
    readonly property string    _POPUP_HIGHTLIGHT_IMG: "qrc:/qt-project.org/imports/UICommon/Popups/highlight_slider.png"
    readonly property string    _POPUP_SLIDER_BACKGROUND: "qrc:/qt-project.org/imports/UICommon/Popups/bg_slider.png"
    readonly property string    _POPUP_CIRCLE_LOADING_IMG: "qrc:/qt-project.org/imports/UICommon/Popups/circle_loading.png"

    // Variables
    readonly property int       _POPUP_BACKGROUND_WIDTH: 1280
    readonly property int       _POPUP_BACKGROUND_HEIGHT: 720
    readonly property double    _POPUP_BACKGROUND_OPACITY : 0.2
    readonly property int       _POPUP_WIDTH: 784
    readonly property int       _POPUP_HEIGHT_500: 500
    readonly property int       _POPUP_HEIGHT_296: 296
    readonly property int       _POPUP_HEIGHT_336: 336
    readonly property int       _POPUP_HEIGHT_312: 312
    readonly property int       _POPUP_HEIGHT_288: 288
    readonly property int       _POPUP_HEIGHT_272: 272
    readonly property int       _POPUP_HEIGHT_256: 256
    readonly property int       _POPUP_HEIGHT_216: 216
    readonly property int       _POPUP_HEIGHT_232: 232
    readonly property int       _POPUP_POSY_110: 110
    readonly property int       _POPUP_POSY_212: 212
    readonly property int       _POPUP_POSY_80: 80
    readonly property int       _POPUP_POSY_252: 252
    readonly property int       _POPUP_POSY_368: 368
    readonly property int       _POPUP_POSY_416: 416
    readonly property int       _POPUP_POSY_448: 448
    readonly property int       _POPUP_POSY_488: 488
    readonly property int       _POPUP_POSY_472: 472
    readonly property int       _POPUP_POSY_392: 392
    readonly property int       _POPUP_POSY_432: 432

    readonly property int       _POPUP_POSY_204: 204
    readonly property int       _POPUP_POSY_224: 224
    
    // ----------------------------- MSG ---------------------------------
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_0: 0
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_60: 60
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_80: 80
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_152: 152
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_190: 190
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_220: 220
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_232: 232
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_240: 240
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_250: 250
    readonly property int       _POPUP_MSG_CTN_TOPMARGIN_280: 280
    readonly property int       _POPUP_MSG_CTN_LEFTMARGIN_49: 49
    readonly property int       _POPUP_MSG_CTN_HEIGHT_200: 200
    readonly property int       _POPUP_MSG_CTN_HEIGHT_184: 184
    readonly property int       _POPUP_MSG_CTN_HEIGHT_160: 160
    readonly property int       _POPUP_MSG_CTN_HEIGHT_144: 144
    readonly property int       _POPUP_MSG_CTN_HEIGHT_120: 120
    readonly property int       _POPUP_MSG_CTN_HEIGHT_80: 80
    readonly property int       _POPUP_MSG_CTN_HEIGHT_40: 40
    readonly property int       _POPUP_MSG_CTN_POSY_96: 96
    readonly property int       _POPUP_MSG_CTN_POSY_16: 16
    readonly property int       _POPUP_MSG_CTN_POSY_48: 48
    readonly property int       _POPUP_MSG_SPACE_4: 4
    readonly property int       _POPUP_MSG_SPACE_10: 10
    readonly property int       _POPUP_MSG_HEIGHT_36: 36
    readonly property int       _POPUP_MSG_HEIGHT_40: 40
    readonly property int       _POPUP_MSG_HEIGHT_120: 120
    readonly property int       _POPUP_MSG_WIDTH: 688
    readonly property int       _POPUP_MSG_WIDTH_720: 720
    readonly property int       _POPUP_MSG_WEIGHT_275: 275
    readonly property int       _POPUP_MSG_POSY_32: 32
    readonly property int       _POPUP_MSG_POSY_48: 48
    readonly property int       _POPUP_MSG_LINE_HEIGHT_40: 40
    readonly property int       _POPUP_MSG_LINE_HEIGHT_36: 36
    readonly property int       _POPUP_MSG_HOLDER_POS_Y_144: 144
    readonly property int       _POPUP_MSG_HOLDER_POS_Y_16: 16
    readonly property int       _POPUP_MSG_TOPMARGIN_168: 168
    readonly property int       _POPUP_MSG_TOPMARGIN_16: 16

    // ----------------------------- BUTTON ---------------------------------
    readonly property int       _POPUP_BTN_CTN_HEIGHT: 80
    readonly property int       _POPUP_BTN_HEIGHT: 80
    readonly property int       _POPUP_BTN_WIDTH: 240
    readonly property int       _POPUP_BTN_RADIUS: 6
    readonly property int       _POPUP_BTN_ALIGN_48: 48
    readonly property int       _POPUP_BTN_ALIGN_32: 32
    readonly property int       _POPUP_BTN_ALIGN_40: 40
    readonly property int       _POPUP_BTN_SPACE_16: 16
    readonly property int       _POPUP_BTN_CTN_ONE_WIDTH: 240
    readonly property int       _POPUP_BTN_CTN_TWO_WIDTH: 496
    readonly property int       _POPUP_BTN_CTN_POS_Y_372: 372
    readonly property int       _POPUP_BTN_CTN_POS_Y_176: 176
    readonly property int       _POPUP_BTN_CTN_POS_Y_104: 104
    readonly property int       _POPUP_ICON_SIZE_28: 28
    readonly property int       _POPUP_ICON_SIZE_40: 40
    readonly property int       _POPUP_BTN_TEXT_WIDTH_155: 155
    readonly property int       _POPUP_BTN_TEXT_HEIGHT_36: 36
    readonly property int       _POPUP_BTN_TEXT_WIDTH_216: 36
    readonly property int       _POPUP_BTN_BOTTOMMARGIN_48: 48
    readonly property int       _POPUP_BTN_EXTEND_TOUCH_AREA: 30

    // ----------------------------- ICON ---------------------------------
    readonly property int       _POPUP_ICON_SIZE_120: 120
    readonly property int       _POPUP_ICON_POSY_120: 120
    readonly property int       _POPUP_ICON_POSY_90: 90
    readonly property int       _POPUP_ICON_POSY_32: 32
    readonly property int       _POPUP_ICON_CIRCLE_SIZE_80: 80
    readonly property int       _POPUP_ICON_CIRCLE_LOAD_FROM_0: 0
    readonly property int       _POPUP_ICON_CIRCLE_LOAD_TO_360: 360
    readonly property int       _POPUP_ICON_CIRCLE_POSY_220: 220
    readonly property int       _POPUP_ICON_CIRCLE_POSY_250: 250
    readonly property int       _POPUP_ICON_CIRCLE_POSY_96: 96
    readonly property int       _POPUP_ICON_CIRCLE_POSY_160: 160
    readonly property int       _POPUP_ICON_TITLE_TOPMARGIN_32: 32
    readonly property int       _POPUP_ICON_TITLE_TOPMARGIN_90: 90
    readonly property int       _POPUP_ICON_TITLE_TOPMARGIN_120: 120
    readonly property int       _POPUP_ICON_TITLE_LEFTMARGIN_333: 333
    readonly property int       _POPUP_ICON_TITLE_LEFTMARGIN_332: 332

    // ----------------------------- FONT ---------------------------------
    readonly property string    _FONT_FAMILY_SUZUKI: "Suzuki_IF TazuganeInfo"
    readonly property string    _FONT_FAMILY_ROBOTO: "Roboto"
    readonly property int       _FONT_WEIGHT: 275
    readonly property int       _FONT_SIZE_26: 26
    readonly property int       _FONT_SIZE_28: 28

    // ----------------------------- COLOR ---------------------------------
    readonly property string    _POPUP_COLOR_TRANSPARENT: "transparent"
    readonly property string    _POPUP_SLIDER_BACKGROUND_COLOR: "#41414B"
    readonly property string    _POPUP_COLOR_WHITE: "#FFFFFF"
    readonly property string    _POPUP_COLOR_GRAY: "#D2D2D2"

    // ----------------------------- Slider ---------------------------------
    readonly property int    _POPUP_SLIDER_WIDTH_640: 640
    readonly property int    _POPUP_SLIDER_WIDTH_564: 564
    readonly property int    _POPUP_SLIDER_HEIGHT_80: 80
    readonly property int    _POPUP_SLIDER_HEIGHT_4: 4
    readonly property int    _POPUP_SLIDER_PROGRESS_VALUE_WIDTH_640: 640
    readonly property int    _POPUP_SLIDER_PROGRESS_VALUE_HEIGHT_30: 30
    readonly property int    _POPUP_SLIDER_PROGRESS_VALUE_POSY_318: 30

    readonly property int popup_msg_ctn_bot_posY: 488
    readonly property int popup_msg_ctn_mid_posY: 252

    // Popup Type Three
    readonly property int popup_title_text_height: 40
    readonly property int popup_title_text_posY: 60

    readonly property int popup_msg_posY_1: 240
    readonly property int popup_msg_posY_2: 220
    readonly property int popup_msg_posY_3: 175
    readonly property int popup_three_btn_ctn_posY: 372


    // Popup Type Fourth
    readonly property int popup_fourth_btn_ctn_large_posY: 372
    readonly property int popup_fourth_btn_ctn_medium_posY: 176
    readonly property int popup_msg_medium_height: 80
    readonly property int popup_fourth_medium_posY: 416

    readonly property int popup_msg_fourth_posY_1: 90
    readonly property int popup_msg_fourth_posY_2: 130
    readonly property int popup_msg_fourth_posY_3: 16
    readonly property int popup_msg_fourth_posY_4: 48

    // Resources
    readonly property string reflection: "qrc:/qt-project.org/imports/UICommon/Resources/reflection.png"
    readonly property string reflectionBase: "qrc:/qt-project.org/imports/UICommon/Resources/reflectionBase.png"
    readonly property string androidAuto: "qrc:/qt-project.org/imports/UICommon/Resources/Android_Auto.png"
    // Icon for tab buttons
    readonly property string tab_active_layer_mask:    "qrc:/qt-project.org/imports/UICommon/Resources/tab_active_layer_mask.png"
    readonly property string tab_droppable_layer_mask: "qrc:/qt-project.org/imports/UICommon/Resources/tab_droppable_layer_mask.png"
    readonly property string tab_base_bg:              "qrc:/qt-project.org/imports/UICommon/Resources/tab_bg_base.png"
    // Icon for right bar tab
    readonly property string tab_active_right_bar_layer_mask:    "qrc:/qt-project.org/imports/UICommon/Resources/tab_active_right_bar_layer_mask.png"
    readonly property string tab_droppable_right_bar_layer_mask: "qrc:/qt-project.org/imports/UICommon/Resources/tab_droppable_right_bar_layer_mask.png"
    readonly property string tab_bg_right_bar_base:              "qrc:/qt-project.org/imports/UICommon/Resources/tab_bg_right_bar_base.png"
    // Icon for double height right bar tab
    readonly property string tab_active_right_bar_layer_mask_double:    "qrc:/qt-project.org/imports/UICommon/Resources/tab_active_right_bar_layer_mask_double.png"
    readonly property string tab_droppable_right_bar_layer_mask_double: "qrc:/qt-project.org/imports/UICommon/Resources/tab_droppable_right_bar_layer_mask_double.png"
    readonly property string tab_bg_right_bar_base_double:              "qrc:/qt-project.org/imports/UICommon/Resources/tab_bg_right_bar_base_double.png"

    readonly property string default_vehicle_battery:   "qrc:/qt-project.org/imports/UICommon/Resources/Vehicle_Image_Battery.png"
    readonly property string calculator_80x80:   "qrc:/qt-project.org/imports/UICommon/Resources/Calculator_80x80.png"

    readonly property string radio_indicator_state_active_toggle_false_48x48  : "qrc:/qt-project.org/imports/UICommon/Resources/Radio_Indicators_State_Active_Toggle_False_48x48.png"
    readonly property string radio_indicator_state_active_toggle_true_48x48   : "qrc:/qt-project.org/imports/UICommon/Resources/Radio_Indicators_State_Active_Toggle_True_48x48.png"
    readonly property string radio_indicator_state_inactive_toggle_false_48x48: "qrc:/qt-project.org/imports/UICommon/Resources/Radio_Indicators_State_InActive_Toggle_False_48x48.png"
    readonly property string radio_indicator_state_inactive_toggle_true_48x48 : "qrc:/qt-project.org/imports/UICommon/Resources/Radio_Indicators_State_InActive_Toggle_True_48x48.png"

    readonly property string button_inActive_240x80: "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_240x80.png"
    readonly property string button_normal_240x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_240x80.png"
    readonly property string button_pressed_240x80 : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_240x80.png"
    readonly property string button_red_240x80     : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Red_240x80.png"

    readonly property string button_inActive_480x80: "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_480x80.png"
    readonly property string button_normal_480x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_480x80.png"
    readonly property string button_pressed_480x80 : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_480x80.png"

    readonly property string button_inActive_80x80: "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_80x80.png"
    readonly property string button_normal_80x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_80x80.png"
    readonly property string button_pressed_80x80 : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_80x80.png"

    readonly property string button_inActive_132x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_132x80.png"
    readonly property string button_normal_132x80     : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_132x80.png"
    readonly property string button_pressed_132x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_132x80.png"
    readonly property string button_selected_132x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Selected_132x80.png"

    readonly property string button_inActive_134x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_134x80.png"
    readonly property string button_normal_134x80     : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_134x80.png"
    readonly property string button_pressed_134x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_134x80.png"
    readonly property string button_selected_134x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Selected_134x80.png"

    readonly property string button_inActive_320x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Text_Button_InActive_320x80.png"
    readonly property string button_normal_320x80     : "qrc:/qt-project.org/imports/UICommon/Resources/Text_Button_Normal_320x80.png"
    readonly property string button_pressed_320x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Text_Button_Pressed_320x80.png"


    readonly property string button_inActive_200x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_200x80.png"
    readonly property string button_selection_200x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Selection_200x80.png"
    readonly property string button_pressed_200x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_200x80.png"


    readonly property string button_inActive_112x88   : "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_112x88.png"
    readonly property string button_nomal_112x88     : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Nomal_112x88.png"
    readonly property string button_pressed_112x88    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Press_112x88.png"

    readonly property string button_backGround_184x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_backGround_184x80.png"
    readonly property string button_popupList_pressed_184x80    : "qrc:/qt-project.org/imports/UICommon/Resources/button_popupList_pressed_184x80.png"

    readonly property string button_InActive_184x80    : "qrc:/qt-project.org/imports/UICommon/Resources/button_InActive_184x80.png"
    readonly property string button_normal_184x80    : "qrc:/qt-project.org/imports/UICommon/Resources/button_normal_184x80.png"
    readonly property string button_pressed_184x80    : "qrc:/qt-project.org/imports/UICommon/Resources/button_pressed_184x80.png"
    readonly property string button_inActive_320x80_ver2   : "qrc:/qt-project.org/imports/UICommon/Resources/Button_InActive_320x80.png"
    readonly property string button_normal_320x80_ver2     : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_320x80.png"
    readonly property string button_pressed_320x80_ver2    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_320x80.png"

    readonly property string button_adjust_inActive_80x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_inActive_80x80.png"
    readonly property string button_adjust_normal_80x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_normal_80x80.png"
    readonly property string button_adjust_pressed_80x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_pressed_80x80.png"

    readonly property string button_adjust_decre_inActive_80x80     : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_decre_inactive_80x80.png"
    readonly property string button_adjust_decre_normal_80x80       : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_decre_normal_80x80.png"
    readonly property string button_adjust_decre_pressed_80x80      : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_decre_pressed_80x80.png"

    readonly property string button_adjust_incre_inActive_80x80     : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_incre_inactive_80x80.png"
    readonly property string button_adjust_incre_normal_80x80       : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_incre_normal_80x80.png"
    readonly property string button_adjust_incre_pressed_80x80      : "qrc:/qt-project.org/imports/UICommon/Resources/Button_adjust_incre_pressed_80x80.png"

    readonly property string button_blue_200x50             : "qrc:/qt-project.org/imports/UICommon/Resources/button_blue_200x50.png"
    readonly property string button_inactive_200x50         : "qrc:/qt-project.org/imports/UICommon/Resources/button_inactive_200x50.png"
    readonly property string button_press_200x50            : "qrc:/qt-project.org/imports/UICommon/Resources/button_press_200x50.png"

    readonly property string button_normal_96x80            : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_96x80.png"
    readonly property string button_inactive_96x80          : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Inactive_96x80.png"
    readonly property string button_press_96x80             : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_96x80.png"

    readonly property string button_normal_195x80            : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Normal_195x80.png"
    readonly property string button_normal_blue_195x80       : "qrc:/qt-project.org/imports/UICommon/Resources/button_normal_blue_195x80.png"
    readonly property string button_inactive_195x80          : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Inactive_195x80.png"
    readonly property string button_press_195x80             : "qrc:/qt-project.org/imports/UICommon/Resources/Button_Pressed_195x80.png"

    readonly property string button_normal_blue_987x80       : "qrc:/qt-project.org/imports/UICommon/Resources/button_normal_blue_987x80.png"
    readonly property string button_press_987x80             : "qrc:/qt-project.org/imports/UICommon/Resources/button_press_987x80.png"

    // background popup

    readonly property var  popup_background_text: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1.png",
                                                   "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2.png",
                                                   "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3.png",
                                                   "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4.png",
                                                   "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5.png",
                                                   "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text6.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text7.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text8.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text9.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text10.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text11.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text12.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text13.png",
                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text14.png"
                                                 ]

    readonly property var  popup_background_text_button: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text6_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text7_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text8_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text9_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text10_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text11_Button.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text12_Button.png"
                                                        ]

    readonly property var  popup_background_text_button_calculator: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Button_Calculator_784x344.png",
                                                                     "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Button_Calculator_784x384.png",
                                                                     "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Button_Calculator_784x424.png",
                                                                     "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Button_Calculator.png",
                                                                   ]

    readonly property var  popup_background_text_calculator: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Calculator_784x248.png",
                                                              "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Calculator_784x288.png",
                                                              "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Calculator_784x328.png",
                                                              "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Calculator_784x368.png",
                                                              "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Calculator.png",
                                                              "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text6_Calculator.png",
                                                            ]


    readonly property var  popup_background_text_icon : ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Icon.png",
                                                         "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Icon.png",
                                                         "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Icon.png",
                                                         "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Icon.png",
                                                         "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Icon.png",
                                                         "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text6_Icon.png",
                                                           ]

    readonly property var  popup_background_text_button_icon : ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Button_Icon.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Button_Icon.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Button_Icon.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Button_Icon.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Button_Icon.png",
                                                                ]

    readonly property var  popup_background_text_title : ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Title.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Title.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Title.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Title.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Title.png",
                                                          "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text6_Title.png",
                                                            ]

    readonly property var  popup_background_text_title_button: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Title_Button.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Title_Button.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Title_Button.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Title_Button.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Title_Button.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text6_Title_Button.png",
                                                              ]

    readonly property var  popup_background_text_title_button_calculator: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Title_Button_Calculator.png",
                                                                           "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Title_Button_Calculator.png",
                                                                           "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Title_Button_Calculator.png",
                                                                           "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Title_Button_Calculator.png",
                                                                         ]
    readonly property var  popup_background_text_process: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Process.png",
                                                           "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text2_Process.png",
                                                           "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text3_Process.png",
                                                           "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Process.png",
                                                           "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Process.png",
    ]

    readonly property var  popup_background_text_button_Check: ["qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text1_Button_Check.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/backgroundPopup784x416.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/backgroundPopup784x416.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text4_Button_Check.png",
                                                                "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_Text5_Button_Check.png",
                                                              ]

    readonly property string background_minus_normal_80x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Minus_Normal_80x80.png"
    readonly property string background_minus_pressed_80x80 : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Minus_Pressed_80x80.png"
    readonly property string background_minus_inactive_80x80: "qrc:/qt-project.org/imports/UICommon/Resources/Background_Minus_InActive_80x80.png"
    readonly property string background_plus_normal_80x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Plus_Normal_80x80.png"
    readonly property string background_plus_pressed_80x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Plus_Pressed_80x80.png"
    readonly property string background_plus_inactive_80x80 : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Plus_InActive_80x80.png"

    readonly property string divider_normal: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal.png"
    readonly property string divider_pressed: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Pressed.png"
    
    readonly property string toggle_divider_normal: "qrc:/qt-project.org/imports/UICommon/Resources/Toggle_Divider.png"
    readonly property string toggle_divider_pressed: "qrc:/qt-project.org/imports/UICommon/Resources/Toggle_PressedDivider.png"

    readonly property string divider_normal_ver_2: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal_ver_2.png"
    readonly property string divider_pressed_ver_2: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Pressed_ver_2.png"

    readonly property string divider_normal_456x2: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal_456x2.png"
    readonly property string divider_pressed_456x_2: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Pressed_456x2.png"
    readonly property string divider_line: "qrc:/qt-project.org/imports/UICommon/Resources/DividerLine.png"
    readonly property string divider_normal_880x2: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal_880x2.png"
    readonly property string divider_pressed_912x2: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Pressed_912x2.png"
    readonly property string divider_special_pressed_912x2: "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Special_Pressed_912x2.png"

    readonly property var divider_normal_container: [
                                                            // size: normal
                                                            {"normal" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal.png"},
                                                            {"":""},
                                                            {"":""},
                                                            {"normal" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal_852x2.png"},
                                                            {"normal" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal.png"},
                                                            {"normal" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal_672.png"},
                                                            {"normal" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal_768.png"},
                                                            {"normal" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Normal_424.png"},
    ]

    readonly property var divider_pressed_container: [
                                                            // size: normal
                                                            {"pressed" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Pressed.png"},
                                                            {"":""},
                                                            {"":""},
                                                            {"pressed" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Pressed_852x2.png"},
                                                            {"pressed" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Pressed.png"},
                                                            {"pressed" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Press_704.png"},
                                                            {"pressed" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Press_800.png"},
                                                            {"pressed" : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Press_456.png"},
    ]

    readonly property string background_item_pressed_944x74 : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_944x74.png"
    readonly property string background_item_pressed_944x80 : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_944x80.png"
    readonly property string background_item_pressed_944x88 : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_944x88.png"

    //NOTICE: When you declare an image source in this array below, please make sure that you will declare in these following arrays :
    //        "highlightHolderSize", "divider_normal_container", "divider_pressed_container" with mapping elements'index order (also known as "highlightBackgroundType" variable)  of these arrays together
    readonly property var background_item_pressed_container: [
                                                                    // background_item_pressed_944x74
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_944x74.png",
                                                                    // background_item_pressed_944x80
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_944x80.png",
                                                                    //background_item_pressed_944x88
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_944x88.png",
                                                                    //background_item_pressed_852x74
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_852x74.png",
                                                                    // background_item_pressed_944x86
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_944x86.png",
                                                                    //background_item_pressed_704x74
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_704x74.png",
                                                                    //background_item_pressed_800x70
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_800x70.png",
                                                                    //background_item_pressed_456x62
                                                                    "qrc:/qt-project.org/imports/UICommon/Resources/Background_Item_Pressed_456x62.png"
    ]

    readonly property var highlightHolderSize: [
                                                    // background_item_pressed_944x74
                                                    {"width" : 944, "height" : 80},
                                                    // background_item_pressed_944x80
                                                    {"width" : 944, "height" : 86},
                                                    //background_item_pressed_944x88
                                                    {"width" : 944, "height" : 94},
                                                    //background_item_pressed_852x74
                                                    {"width" : 852, "height" : 80},
                                                    // background_item_pressed_944x86
                                                    {"width" : 852, "height" : 96},
                                                    //background_item_pressed_704x80
                                                    {"width" : 704, "height" : 80},
                                                    //background_item_pressed_800x80
                                                    {"width" : 800, "height" : 80},
                                                    //background_item_pressed_456x72
                                                    {"width" : 456, "height" : 72},
    ]

    readonly property var checkbox_Selection: [
                                                "qrc:/qt-project.org/imports/UICommon/Resources/checkBoxGround_1Line.png",
                                                "qrc:/qt-project.org/imports/UICommon/Resources/checkBoxGround_2Line.png",
                                                ]

    readonly property string background_popupList_pressed_456x542 : "qrc:/qt-project.org/imports/UICommon/Resources/Background_PopupList_Pressed_456x542.png"

    readonly property string background_popup_list_488x128    : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_List_488x128.png"
    readonly property string background_popup_list_488x192    : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_List_488x192.png"
    readonly property string background_popup_list_488x528    : "qrc:/qt-project.org/imports/UICommon/Resources/Background_Popup_List_488x528.png"
    readonly property string divider_popup_list_rormal_424x2  : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Popup_List_Normal_424x2.png"
    readonly property string divider_popup_list_pressed_456x2 : "qrc:/qt-project.org/imports/UICommon/Resources/Divider_Popup_List_Pressed_456x2.png"

    readonly property string arrow_right_inactive     : "qrc:/qt-project.org/imports/UICommon/Resources/Arrow_Right_InActive.png"
    readonly property string arrow_right_normal       : "qrc:/qt-project.org/imports/UICommon/Resources/Arrow_Right_Normal.png"
    readonly property string arrow_right_pressed      : "qrc:/qt-project.org/imports/UICommon/Resources/Arrow_Right_Pressed.png"
    readonly property string arrow_down_inactive_80x80: "qrc:/qt-project.org/imports/UICommon/Resources/Icon_Arrow_Down_InActive_80x80.png"
    readonly property string arrow_down_Normal_80x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Icon_Arrow_Down_Normal_80x80.png"
    readonly property string arrow_down_Pressed_80x80 : "qrc:/qt-project.org/imports/UICommon/Resources/Icon_Arrow_Down_Pressed_80x80.png"
    readonly property string arrow_up_inactive_80x80  : "qrc:/qt-project.org/imports/UICommon/Resources/Icon_Arrow_Up_InActive_80x80.png"
    readonly property string arrow_up_normal_80x80    : "qrc:/qt-project.org/imports/UICommon/Resources/Icon_Arrow_Up_Normal_80x80.png"
    readonly property string arrow_up_pressed_80x80   : "qrc:/qt-project.org/imports/UICommon/Resources/Icon_Arrow_Up_Pressed_80x80.png"


    readonly property int _NORMAL_STATE:  0
    readonly property int _CLICKED_STATE: 1
    readonly property int _PRESSED_STATE: 2
    readonly property int _DISABLE_STATE: 3
    readonly property int _SELECTED_STATE: 4

    readonly property int _DISABLE_HIGHLIGHT    : 0
    readonly property int _ENABLE_HIGHLIGHT     : 1
    readonly property int _NORMAL_HIGHLIGHT     : 2
    readonly property int _HOLDING_HIGHLIGHT    : 3
    readonly property int _FLARE_LEFT           : 0
    readonly property int _FLARE_RIGHT          : 1

    property var _APP_ENGINE                    : undefined


    property var _SCREEN_STATE:{
        "0": 0
    }

    readonly property real _DPI: VehicleGeneralState.DPI

    function convertToPointSize(size){
        return size * 72 / _DPI
    }
}
