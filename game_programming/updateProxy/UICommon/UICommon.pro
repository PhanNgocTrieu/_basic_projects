QT = core dbus qml gui quick appman_launcher-private quick-private

TEMPLATE = lib
DEFINES += UICOMMON_LIBRARY

CONFIG += c++17 dbus
CONFIG += qtquickcompiler

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include(HMIFramework/HMIFramework.pri)

SOURCES += \
    Proxy/HMISystem/HMISystemServiceAdaptor.cpp \
    Proxy/HMISystem/HMISystemServiceProxy.cpp \
    LanguageManagement.cpp \
    HMIHeaderServiceAdaptor.cpp \
    HMIHeaderServiceProxy.cpp   \
    Proxy/ACP/ACPAgencyAdaptor.cpp \
    Proxy/ACP/ACPAgencyProxy.cpp \
    Proxy/AAP/AAPAgencyAdaptor.cpp \
    Proxy/AAP/AAPAgencyProxy.cpp \
    Proxy/Navigation/NaviboxInfoAdaptor.cpp \
    Proxy/Navigation/NaviboxInfoProxy.cpp \
    Proxy/Navigation/NaviboxUIAdaptor.cpp \
    Proxy/Navigation/NaviboxUIProxy.cpp \
    Proxy/Navigation/NavigationServiceAdaptor.cpp \
    Proxy/Navigation/NavigationServiceProxy.cpp \
    Proxy/Navigation/TouchServiceAdaptor.cpp \
    Proxy/Navigation/TouchServiceProxy.cpp \
    Proxy/Navigation/VirtualAssistantAdaptor.cpp \
    Proxy/Navigation/VirtualAssistantProxy.cpp \
    Proxy/Navigation/naviboxinfoservice.cpp \
    Proxy/Navigation/naviboxui.cpp \
    Proxy/Navigation/navigationservice.cpp \
    Proxy/Navigation/touchservice.cpp \
    Proxy/Navigation/virtualassistantservice.cpp \
    SettingComponent/SettingBattery.cpp \
    SmartPhoneAgencyAdaptor.cpp \
    SmartPhoneAgencyProxy.cpp \
    UILogger.cpp \
    UICommon.cpp \
    UISetting.cpp \
    UIScreenContext.cpp \
    Proxy/ServiceBus/ServiceBus.cpp \
    Proxy/ServiceBus/ServiceBusAgencyAdaptor.cpp \
    Proxy/ServiceBus/ServiceBusAgencyProxy.cpp \
    Proxy/DriverRecorder/DRCAgencyAdaptor.cpp \
    Proxy/DriverRecorder/DRCAgencyInterface.cpp \
    Proxy/Media/MediaAgencyInterface.cpp \
    Proxy/Media/MediaAgencyAdaptor.cpp \
    Proxy/Bluetooth/BluetoothAdapterAgencyAdaptor.cpp \
    Proxy/Bluetooth/BluetoothAdapterAgencyProxy.cpp \
    Proxy/Wifi/WifiAdapterAgencyAdaptor.cpp \
    Proxy/Wifi/WifiAdapterAgencyProxy.cpp \
    Proxy/VehicleGeneralState/VehicleGeneralStateAdaptor.cpp \
    Proxy/VehicleGeneralState/VehicleGeneralStateInterface.cpp \
    Proxy/VehicleGeneralState/VehicleGeneralStateModel.cpp \
    Proxy/HMISystem/HMISystemModel.cpp \
    Proxy/CS/ConnectedServiceAdaptor.cpp \
    Proxy/CS/ConnectedServiceProxy.cpp \
    ImagePoolProvider.cpp \
    SysUI/SysUI.cpp \
    SysUI/SysUIAdapter.cpp \
    SysUI/naviboxtilemanager.cpp \
    SysUI/SysUIInterface.cpp \
    Models/TitleModel.cpp \
    AbstractApplication/IDSApp.cpp \
    AbstractApplication/IDSAppDef.cpp \
    IDSWindowTemplate/IDSWindow.cpp
    

HEADERS += \
    Proxy/HMISystem/HMISystemService.h \
    Proxy/HMISystem/HMISystemServiceAdaptor.h \
    Proxy/HMISystem/HMISystemServiceProxy.h \
    LanguageManagement.h \
    Proxy/Navigation/NaviboxInfoAdaptor.h \
    Proxy/Navigation/NaviboxInfoProxy.h \
    Proxy/Navigation/NaviboxUIAdaptor.h \
    Proxy/Navigation/NaviboxUIProxy.h \
    Proxy/Navigation/NavigationServiceAdaptor.h \
    Proxy/Navigation/NavigationServiceProxy.h \
    Proxy/Navigation/TouchServiceAdaptor.h \
    Proxy/Navigation/TouchServiceProxy.h \
    Proxy/Navigation/VirtualAssistantAdaptor.h \
    Proxy/Navigation/VirtualAssistantProxy.h \
    Proxy/Navigation/naviboxinfoservice.h \
    Proxy/Navigation/naviboxui.h \
    Proxy/Navigation/navigationservice.h \
    Proxy/Navigation/touchservice.h \
    Proxy/Navigation/virtualassistantservice.h \
    SettingComponent/SettingBattery.h \
    UILogger.h \
    Proxy/ACP/ACPAgency.h \
    Proxy/ACP/ACPAgencyProxy.h \
    Proxy/ACP/ACPAgencyAdaptor.h \
    Proxy/AAP/AAPAgency.h \
    Proxy/AAP/AAPAgencyProxy.h \
    Proxy/AAP/AAPAgencyAdaptor.h \
    SmartPhoneAgency.h \
    SmartPhoneAgencyAdaptor.h \
    SmartPhoneAgencyProxy.h \
    UICommon.h \
    UISetting.h \
    UIScreenContext.h \
    HMIHeaderServiceAdaptor.h  \
    HMIHeaderService.h  \
    HMIHeaderServiceProxy.h \
    UIKeyboard.h \
    UICommon_global.h \
    Proxy/ServiceBus/ServiceBus.h \
    Proxy/ServiceBus/ServiceBusAgency.h \
    Proxy/ServiceBus/ServiceBusAgencyAdaptor.h \
    Proxy/ServiceBus/ServiceBusAgencyProxy.h \
    Proxy/DriverRecorder/DRCAgencyAdaptor.h \
    Proxy/DriverRecorder/DRCAgencyInterface.h \
    Proxy/DriverRecorder/DRCAgency.h \
    Proxy/DriverRecorder/DRCAgencyDefine.h \
    Proxy/Media/MediaDef.h \
    Proxy/Media/MediaAgency.h \
    Proxy/Media/MediaAgencyInterface.h \
    Proxy/Media/MediaAgencyAdaptor.h \
    Proxy/Bluetooth/BluetoothAdapterAgency.h \
    Proxy/Bluetooth/BluetoothAdapterAgencyAdaptor.h \
    Proxy/Bluetooth/BluetoothAdapterAgencyProxy.h \
    Proxy/Wifi/WifiAdapterAgency.h \
    Proxy/Wifi/WifiAdapterAgencyAdaptor.h \
    Proxy/Wifi/WifiAdapterAgencyProxy.h \
    Proxy/VehicleGeneralState/VehicleGeneralStateAdaptor.h \
    Proxy/VehicleGeneralState/VehicleGeneralStateInterface.h \
    Proxy/VehicleGeneralState/VehicleGeneralStateAgency.h \
    Proxy/VehicleGeneralState/VehicleGeneralStateModel.h \
    Proxy/HMISystem/HMISystemServiceDefines.h \
    Proxy/HMISystem/HMISystemModel.h \
    Proxy/CS/ConnectedServiceAgency.h \
    Proxy/CS/ConnectedServiceAdaptor.h \
    Proxy/CS/ConnectedServiceProxy.h \
    ImagePoolProvider.h \
    WrapPro.h \
    SysUI/SysUI.h \
    SysUI/SysUIAdapter.h \
    SysUI/naviboxtilemanager.h \
    SysUI/SysUIInterface.h \
    Models/TitleModel.h \
    AbstractApplication/IDSApp.h \
    AbstractApplication/IDSAppDef.h \
    IDSWindowTemplate/IDSWindow.h

    

RESOURCES += UICommon.qrc
DESTDIR = $$OUT_PWD/../../apps/libraries

QML_IMPORT_PATH += \
    $$PWD/imports

INCLUDEPATH += $$PWD/../ServiceWrapper/ServiceWrapper 

LIBS += -L$$OUT_PWD/../../apps/libraries \
        -lServiceWrapper  

build_pc {
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
        LIBS += -L$$(SDKTARGETSYSROOT)/usr/lib/ -lvehicle-customizeservice -ldiagfa -lsmm_ui -lsmm -lvasetting -lemcomm -livids -ltag -lcamera_service  -lreprouiservice   -ldrive-recorder  -ldlt -ldl -lradio-station-info -lgui_communication -ldisptime -ldisptimeset -lconnectedservice -lscreen-capture -lva-lib -lcafw -lvafw -luserdatamngclient -ltddiag
        LIBS += -L$$(SDKTARGETSYSROOT)/system/usr/lib/ -lncmediasmartphone_api -lncmediatuner_api -lncmediards_api -lservicecommon_api -lncmediatrafficinfo_api -lncmediadrm_api -lncbtconnect_api -lncbthandsfree_api -lncwifi_api -lncbtphonebook_api -lncmediaaudiosetting_api  -lncsystemsetting_api -lncmediaipod_api -lncmediausb_api -lncmediabtaudio_api -lncmediaaap_api -lncmediacarplaycontrol_api -lncmediadab_api -lncmediadabinterrupt_api -lncsystemcontentresolver_api  -lncdiag_api \
                -lncmediardsalarm_api -lncmediadabalarm_api -lncmediasoundplayer_api -lrfbt_api -lrfwifi_api
    } else {
        INCLUDEPATH += $$OUT_PWD/../../../recipe-sysroot/usr/include  \
                       $$OUT_PWD/../../../recipe-sysroot/system/usr/include
        QMAKE_LFLAGS += "-Wl,-rpath-link,$$OUT_PWD/../../../recipe-sysroot/usr/lib/:$$OUT_PWD/../../../recipe-sysroot/system/usr/lib/"
        LIBS += -L$$OUT_PWD/../../../recipe-sysroot/usr/lib/ -lvehicle-customizeservice -ldiagfa -lsmm_ui -lsmm -lvasetting  -lServiceVehicle  -lemcomm -livids -ltag -lcamera_service  -lreprouiservice   -ldrive-recorder  -ldlt -ldl -lradio-station-info -lgui_communication -ldisptime -ldisptimeset -lconnectedservice -lscreen-capture -lva-lib -lcafw -lvafw -luserdatamngclient -ltddiag
        LIBS += -L$$OUT_PWD/../../../recipe-sysroot/system/usr/lib/ -lncmediasmartphone_api -lncmediatuner_api -lncmediards_api -lservicecommon_api -lncmediatrafficinfo_api -lncmediadrm_api -lncbtconnect_api -lncbthandsfree_api -lncwifi_api -lncbtphonebook_api -lncmediaaudiosetting_api  -lncsystemsetting_api -lncmediaipod_api -lncmediausb_api -lncmediabtaudio_api -lncmediaaap_api -lncmediacarplaycontrol_api -lncmediadab_api -lncmediadabinterrupt_api -lncsystemcontentresolver_api  -lncdiag_api \
                -lncmediardsalarm_api -lncmediadabalarm_api -lncmediasoundplayer_api -lrfbt_api -lrfwifi_api  
    }
}

debug_gdb {
    QMAKE_CXXFLAGS += -O0 -g -ggdb
    QMAKE_LFLAGS -= -s
}

DISTFILES += \
    Proxy/Navigation/navigationservice.xml \
    Proxy/ServiceBus/ServiceBusAgency.xml \
    Proxy/CS/ConnectedServiceInf.xml \
    hmisysif.xml \
    hmiheaderif.xml \
    ACPAgency.xml

