QT += core qml gui quick widgets dbus appman_launcher-private
CONFIG += c++20 link_pkgconfig
CONFIG += qtquickcompiler
QMAKE_LRELEASE_FLAGS=-idbased

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# To used the 3rd debuger such as dlt
DEFINES += USE_3RD_DEBUG

# To used the 3rd debuger such as dlt
DEFINES += USE_3RD_DEBUG


include(Views/Views.pri)


INCLUDEPATH += $$PWD/../ServiceWrapper/ServiceWrapper   \
               $$PWD/../1_SETTING_App/Views/inc/Common \
               $$PWD/../2_AC_App/Views/inc/Common \
               $$PWD/../3_EV_App/Views/inc/Common \
               $$PWD/../4_PHONE_App/Views/inc/Common \
               $$PWD/../8_MEDIA_App/Views/inc/Common \
               $$PWD/../UI_apps/5_CARPLAY_App/Views/inc/Common \
               $$PWD/../UI_apps/7_NAVI_App/Views/inc/Common \
               $$PWD/../UI_apps/9_PICTURE_App/Views/inc/Common \
               $$PWD/../10_ANDR_App/Views/inc/Common \
               $$PWD/../FACTORY_App/Views/inc/Common \
               $$PWD/../SystemPopupAndControl/SystemPopupManager/Views/inc/Common \
               $$PWD/../UICommon \
               $$PWD/../UICommon/HMIFramework/HMICommon \
               $$PWD/../UICommon/HMIFramework/HMIViewer \
               $$PWD/../UICommon/HMIFramework/HMIViewer/ScreenManager \
               $$PWD/../UICommon/HMIFramework/HMIViewer/PopupManager \
               $$PWD/../UICommon/HMIFramework/HMIViewer/Common

DESTDIR = $$OUT_PWD/../../apps/13_CS_App
LIBS += -L$$OUT_PWD/../../apps/libraries \
        -lUICommon \
        -lServiceWrapper 

PKGCONFIG += glib-2.0

build_pc {
    CONFIG += debug
    QMAKE_LFLAGS += -s
    INCLUDEPATH += $$PWD/../ServiceWrapper/ServiceStub/include \
                    $$PWD/../ServiceVehicle
    DEFINES += HMI_SHOW_TEST_APP
    LIBS += -L$$OUT_PWD/../../apps/libraries -lServiceVehicle -livids -lServiceStub
    INCLUDEPATH += $$PWD/../ServiceWrapper/Libraries/ivi-data-service/include

} else {
    DEFINES += BUILD_BOARD
    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"

    build_board {
        INCLUDEPATH += $$(SDKTARGETSYSROOT)/usr/include  \
                       $$(SDKTARGETSYSROOT)/system/usr/include \
                      $$PWD/../ServiceVehicle

        QMAKE_LFLAGS += "-Wl,-rpath-link,$$(SDKTARGETSYSROOT)/usr/lib/:$$(SDKTARGETSYSROOT)/system/usr/lib/"
        QMAKE_LFLAGS += -s
        LIBS += -L$$OUT_PWD/../../apps/libraries -lServiceVehicle
        LIBS += -L$$(SDKTARGETSYSROOT)/usr/lib/ -lvehicle-customizeservice -ldiagfa -lsmm_ui -lsmm -lvasetting -lemcomm -livids -ltag -lcamera_service  -lreprouiservice   -ldrive-recorder  -ldlt -ldl -lradio-station-info -lgui_communication -lnssif -ldisptime -ldisptimeset -lconnectedservice -lscreen-capture -lva-lib -lcafw -lvafw -luserdatamngclient -ltddiag
        LIBS += -L$$(SDKTARGETSYSROOT)/system/usr/lib/ -lncmediasmartphone_api -lncmediatuner_api -lncmediards_api -lservicecommon_api -lncmediatrafficinfo_api -lncmediadrm_api -lncbtconnect_api -lncbthandsfree_api -lncwifi_api -lncbtphonebook_api -lncmediaaudiosetting_api  -lncsystemsetting_api -lncmediaipod_api -lncmediausb_api -lncmediabtaudio_api -lncmediaaap_api -lncmediacarplaycontrol_api -lncmediadab_api -lncmediadabinterrupt_api -lncsystemcontentresolver_api  -lncdiag_api \
                -lncmediardsalarm_api -lncmediadabalarm_api -lncmediasoundplayer_api -lrfbt_api -lrfwifi_api
    } else {
        INCLUDEPATH += $$OUT_PWD/../../../recipe-sysroot/usr/include  \
                       $$OUT_PWD/../../../recipe-sysroot/system/usr/include
        QMAKE_LFLAGS += "-Wl,-rpath-link,$$OUT_PWD/../../../recipe-sysroot/usr/lib/:$$OUT_PWD/../../../recipe-sysroot/system/usr/lib/"
        LIBS += -L$$OUT_PWD/../../../recipe-sysroot/usr/lib/ -lvehicle-customizeservice -ldiagfa -lsmm_ui -lsmm -lvasetting  -lServiceVehicle  -lemcomm -livids -ltag -lcamera_service  -lreprouiservice   -ldrive-recorder  -ldlt -ldl -lradio-station-info -lgui_communication -lnssif -ldisptime -ldisptimeset -lconnectedservice -lscreen-capture -lva-lib -lcafw -lvafw -luserdatamngclient -ltddiag
        LIBS += -L$$OUT_PWD/../../../recipe-sysroot/system/usr/lib/ -lncmediasmartphone_api -lncmediatuner_api -lncmediards_api -lservicecommon_api -lncmediatrafficinfo_api -lncmediadrm_api -lncbtconnect_api -lncbthandsfree_api -lncwifi_api -lncbtphonebook_api -lncmediaaudiosetting_api  -lncsystemsetting_api -lncmediaipod_api -lncmediausb_api -lncmediabtaudio_api -lncmediaaap_api -lncmediacarplaycontrol_api -lncmediadab_api -lncmediadabinterrupt_api -lncsystemcontentresolver_api  -lncdiag_api \
                -lncmediardsalarm_api -lncmediadabalarm_api -lncmediasoundplayer_api -lrfbt_api -lrfwifi_api 
    }
}
SOURCES += \
        Models/CSModel.cpp \
        UICommunication/UICommunication.cpp \
        Models/ConnectedProvider.cpp \
        Models/ConnectedProviderPretty.cpp \
        main.cpp \
        csengine.cpp

HEADERS += \
        Common/util.h \
        Models/CSModel.h \
        Models/ConnectedProvider.h \
        UICommunication/UICommunication.h \
        csengine.h 
