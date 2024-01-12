#include "UICommon.h"
#include <QtGlobal>
#include <common/Logger.h>
#include <common/LoggerDLTSink.h>
#include "UILogger.h"
#include <QFileInfo>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "SmartPhoneAgency.h"
#include "Proxy/DriverRecorder/DRCAgencyDefine.h"
#include "Proxy/VehicleGeneralState/VehicleGeneralStateInterface.h"
#include "Proxy/HMISystem/HMISystemModel.h"
#include "Proxy/ACP/ACPAgency.h"
#include "Proxy/AAP/AAPAgency.h"
#include "SysUI/SysUI.h"
#include <QFontDatabase>
#include <SettingComponent/SettingBattery.h>

extern int qInitResources_UICommon();
extern int qCleanupResources_UICommon();

static uint32_t gQtCppLogModuleId;
static int font_load_manual();

//Use LoggerConsole sink instead so remove it
#if 0
const char* logHightLightPatterns[6] = 
{
    "\e[0;34mDEBUG\e[0m",            // DEBUG  
    "\e[1;32mINFO\e[0m",             // INFO      ~ green
    "\e[1;33mWARN\e[0m",             // WARN      ~ yellow
    "\e[4;33mCRITICAL\e[0m",         // CRITICAL  
    "\e[1;31mFATAL\e[0m",            // FATAL     ~ red
    "\e[1;36mSYS\e[0m",              // SYS       ~ red
};

const char* logPattern = "[%s| \e[1;32m%s\e[0m ]  %-100s[\e[1;32m%s:%d\e[0m]\n";

void writeLog(const char* format,  ...){
    va_list args;
    va_start(args,format);
    vprintf(format,args);

    va_end(args);
};
#endif

static void qMessageHandler(QtMsgType msgType, const QMessageLogContext &ctx, const QString &content)
{
    UNUSED(ctx);
    srvwrp::logsrv::Logger _logger;
    const static srvwrp::logsrv::LogSeverity severityMap[] = {
            srvwrp::logsrv::LOG_DBG, //QtDebugMsg
            srvwrp::logsrv::LOG_WRN, //QtWarningMsg
            srvwrp::logsrv::LOG_ERR, //QtCriticalMsg
            srvwrp::logsrv::LOG_FTL, //QtFatalMsg
            srvwrp::logsrv::LOG_INF, //QtInfoMsg
            srvwrp::logsrv::LOG_FTL  //QtSystemMsg
    };
//Use LoggerConsole sink instead so remove it
#if 0     
    bool isValidLog = false;
    switch(msgType){
        case QtMsgType::QtDebugMsg:
        case QtMsgType::QtWarningMsg:
        case QtMsgType::QtFatalMsg:
        case QtMsgType::QtSystemMsg:{
            isValidLog = true;
            break;
        }
        default: break;
    }
    QString applicationName = QFileInfo(QCoreApplication::applicationFilePath()).fileName();

    const char* file = ctx.file ? ctx.file : "";
    QString extractFileName = file;
    int line = ctx.line;
    int pos = extractFileName.lastIndexOf("/");
    if (pos!=-1){
        extractFileName = extractFileName.sliced(pos+1);
    }
#endif   
//Use LoggerConsole sink instead so remove it
#if 0    
    if (isValidLog){
        writeLog(logPattern,
                   logHightLightPatterns[msgType],
                   applicationName.toStdString().c_str(),
                   content.toStdString().c_str(),
                   extractFileName.toStdString().c_str(),
                   line
                   );
    }
#endif    
    //QString msgContext = content + "[" + extractFileName + ":" + QString::number(line) + "]";
    // _logger.createRecord(severityMap[msgType],gQtCppLogModuleId).getStreamer() << msgContext.toStdString();
    _logger.createRecord(severityMap[msgType],gQtCppLogModuleId).getStreamer() << content.toStdString();
}


QDBusArgument& operator<<(QDBusArgument &argument, const QList<uicommon::SmartPhoneAgency::DeviceInfo>& listDevInfo)
{
    argument.beginArray(qMetaTypeId<uicommon::SmartPhoneAgency::DeviceInfo>());
// Fix klocwork START
    for(int i = 0; i < static_cast<int>(listDevInfo.size()); i++){
        const uicommon::SmartPhoneAgency::DeviceInfo& item = listDevInfo[i];
// Fix klocwork END
        argument << item;
    }
    argument.endArray();

    return argument;
}


const QDBusArgument& operator>>(QDBusArgument &argument, QList<uicommon::SmartPhoneAgency::DeviceInfo>& listDevInfo)
{    
    argument.beginArray(qMetaTypeId<uicommon::SmartPhoneAgency::DeviceInfo>());
    listDevInfo.clear();

    while (!argument.atEnd()) {
        uicommon::SmartPhoneAgency::DeviceInfo tmp;
        argument >> tmp;
        listDevInfo.emplace_back(tmp);
    }

    argument.endArray();

    return argument;
}



QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::SmartPhoneAgency::DeviceInfo& devInfo)
{
    argument.beginStructure();

    argument << devInfo.serialNum 
             << devInfo.btAddr 
             << devInfo.devName 
             << devInfo.supportFlg
             << static_cast<int>(devInfo.deviceType)
             << static_cast<int>(devInfo.connectionType)
             << static_cast<int>(devInfo.sessionType)
             << static_cast<int>(devInfo.sessionStatus)
             << devInfo.isHFPConnect
             << devInfo.isMAPConnect
             << devInfo.isAVPConnect
             << devInfo.isSPPConnect
             << devInfo.isHFPUsedConnect
             << devInfo.isMAPUsedConnect
             << devInfo.isAVPUsedConnect
             << devInfo.isSPPUsedConnect;

    argument.endStructure();

    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::SmartPhoneAgency::DeviceInfo& devInfo)
{
    int devType;
    int connType;
    int sessType;
    int sessSts;
    
    argument.beginStructure();

    argument >> devInfo.serialNum
             >> devInfo.btAddr
             >> devInfo.devName
             >> devInfo.supportFlg
             >> devType
             >> connType
             >> sessType
             >> sessSts
             >> devInfo.isHFPConnect
             >> devInfo.isMAPConnect
             >> devInfo.isAVPConnect
             >> devInfo.isSPPConnect
             >> devInfo.isHFPUsedConnect
             >> devInfo.isMAPUsedConnect
             >> devInfo.isAVPUsedConnect
             >> devInfo.isSPPUsedConnect;

    argument.endStructure();

    devInfo.deviceType = static_cast<uicommon::SmartPhoneAgency::DeviceType>(devType);
    devInfo.connectionType = static_cast<uicommon::SmartPhoneAgency::ConnectionType>(connType);
    devInfo.sessionType = static_cast<uicommon::SmartPhoneAgency::SessionType>(sessType);
    devInfo.sessionStatus = static_cast<uicommon::SmartPhoneAgency::SessionStatus>(sessSts);

    return argument;
}
QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::DRCAgencyRequest &req){
    argument.beginStructure();
    argument<<static_cast<int>(req);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::DRCAgencyRequest &req){
    int reqValue = -1;
    argument.beginStructure();
    argument >> reqValue;
    argument.endStructure();
    if (reqValue <= static_cast<int>(uicommon::DRCAgencyRequest::DRCAgencyRequest_MIN) || reqValue >= static_cast<int>(uicommon::DRCAgencyRequest::DRCAgencyRequest_MAX)){
        req = uicommon::DRCAgencyRequest::INVALID_REQUEST;
    }else{
        req = static_cast<uicommon::DRCAgencyRequest>(reqValue);
    }
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::HMIApplication &app){
    argument.beginStructure();
    argument<<static_cast<int>(app);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::HMIApplication &app){
    uint8_t appVal = static_cast<int>(uicommon::HMIApplication::HMIApplication_MAX);
    argument.beginStructure();
    argument >> appVal;
    argument.endStructure();
    app = static_cast<uicommon::HMIApplication>(appVal);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::HMIUserInteractiveStatus &userStatus){
    argument.beginStructure();
    argument<<static_cast<int>(userStatus);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::HMIUserInteractiveStatus &userStatus){
    uint8_t userStatusVal = static_cast<int>(uicommon::HMIUserInteractiveStatus::USER_STATUS_MAX);
    argument.beginStructure();
    argument >> userStatusVal;
    argument.endStructure();
    userStatus = static_cast<uicommon::HMIUserInteractiveStatus>(userStatusVal);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::DRCInvocationResult &res){
    argument.beginStructure();
    argument<<static_cast<int>(res);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::DRCInvocationResult &res){
    int resValue = -1;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    res = static_cast<uicommon::DRCInvocationResult>(resValue);
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::ACPAgency::SongInfo& songInfo)
{
    argument.beginStructure();

    argument << songInfo.songName
             << songInfo.artistName
             << songInfo.albumName
             << songInfo.trackNum;

    argument.endStructure();

    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::ACPAgency::SongInfo& songInfo)
{
    argument.beginStructure();

    argument >> songInfo.songName
        >> songInfo.artistName
        >> songInfo.albumName
        >> songInfo.trackNum;

    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::ACPAgency::ArtworkData& artworkData)
{
    argument.beginStructure();

    argument << artworkData.formatCode
             << artworkData.imageWidth
             << artworkData.imageHeight
             << artworkData.rowSize
             << artworkData.buf;

    argument.endStructure();

    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::ACPAgency::ArtworkData& artworkData)
{
    argument.beginStructure();

    argument >> artworkData.formatCode
        >> artworkData.imageWidth
        >> artworkData.imageHeight
        >> artworkData.rowSize
        >> artworkData.buf;

    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::AAPAgency::MediaMetaData& metaData)
{
    argument.beginStructure();

    argument << metaData.song
             << metaData.artist
             << metaData.album_art
             << metaData.albumName
             << metaData.durationSeconds;

    argument.endStructure();

    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::AAPAgency::MediaMetaData& metaData)
{
    argument.beginStructure();

    argument >> metaData.song
        >> metaData.artist
        >> metaData.album_art
        >> metaData.albumName
        >> metaData.durationSeconds;

    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::AAPAgency::MediaStatus& mediaStatus)
{
    argument.beginStructure();

    argument << mediaStatus.state
             << mediaStatus.shuffle
             << mediaStatus.repeat
             << mediaStatus.repeat_one
             << mediaStatus.playbackSeconds;

    argument.endStructure();

    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::AAPAgency::MediaStatus& mediaStatus)
{
    argument.beginStructure();

    argument >> mediaStatus.state
        >> mediaStatus.shuffle
        >> mediaStatus.repeat
        >> mediaStatus.repeat_one
        >> mediaStatus.playbackSeconds;

    argument.endStructure();
    return argument;
}


QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::LayoutDisplay &layout){
    argument.beginStructure();
    argument << static_cast<int>(layout);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::LayoutDisplay &layout){
    int layoutType = -1;
    argument.beginStructure();
    argument >> layoutType;
    argument.endStructure();
    if (layoutType == -1){
        layout = uicommon::LayoutDisplay::INVALID_LAYOUT_DISPLAY;
    }else{
        layout = static_cast<uicommon::LayoutDisplay>(layoutType);
    }
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::SysUI::TransitionType &transitionType)
{
    argument.beginStructure();
    argument << static_cast<int>(transitionType);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::SysUI::TransitionType &transitionType)
{
    int transitionTypeVal = -1;
    argument.beginStructure();
    argument >> transitionTypeVal;
    argument.endStructure();
    transitionType = static_cast<uicommon::SysUI::TransitionType>(transitionTypeVal);
    return argument;
}
QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::SysUI::TransitionRetCode &retCode)
{
    argument.beginStructure();
    argument << static_cast<int>(retCode);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::SysUI::TransitionRetCode &retCode)
{
    int code = -1;
    argument.beginStructure();
    argument >> code;
    argument.endStructure();
    retCode = static_cast<uicommon::SysUI::TransitionRetCode>(code);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::SysUI::ServiceAACP &serviceType){
    argument.beginStructure();
    argument << static_cast<int>(serviceType);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::SysUI::ServiceAACP &serviceType){
    int serviceVal = -1;
    argument.beginStructure();
    argument >> serviceVal;
    argument.endStructure();
    serviceType = static_cast<uicommon::SysUI::ServiceAACP>(serviceVal);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::RecordingStatus &status)
{
    argument.beginStructure();
    argument << static_cast<int>(status);
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::RecordingStatus &status)
{
    int statusVal = -1;
    argument.beginStructure();
    argument >> statusVal;
    argument.endStructure();
    if (statusVal == -1) status = uicommon::RecordingStatus::UNKNOWN;
    else status = static_cast<uicommon::RecordingStatus>(statusVal);
    return argument;
}

namespace uicommon {    
    int initialize() {
        qDBusRegisterMetaType<uicommon::SmartPhoneAgency::DeviceInfo>();
        qDBusRegisterMetaType<QList<uicommon::SmartPhoneAgency::DeviceInfo>>();
        qDBusRegisterMetaType<uicommon::DRCAgencyRequest>();
        qDBusRegisterMetaType<uicommon::DRCInvocationResult>();
        qDBusRegisterMetaType<uicommon::HMIApplication>();
        qDBusRegisterMetaType<uicommon::HMIUserInteractiveStatus>();
        qDBusRegisterMetaType<uicommon::ACPAgency::SongInfo>();
        qDBusRegisterMetaType<uicommon::ACPAgency::ArtworkData>();
        qDBusRegisterMetaType<uicommon::AAPAgency::MediaMetaData>();
        qDBusRegisterMetaType<uicommon::AAPAgency::MediaStatus>();
        qDBusRegisterMetaType<uicommon::LayoutDisplay>();
        qDBusRegisterMetaType<uicommon::SysUI::TransitionType>();
        qDBusRegisterMetaType<uicommon::SysUI::TransitionRetCode>();
        qDBusRegisterMetaType<uicommon::SysUI::ServiceAACP>();
        qDBusRegisterMetaType<uicommon::RecordingStatus>();
        font_load_manual();
        return qInitResources_UICommon();
    }

    int finialize() {
        return qCleanupResources_UICommon();
    }

    int setup_logger(const std::string& appName, 
                    const std::string& dltAppId,
                    const std::string& dltCtxId,
                    const std::string& dltDesc)
    {
        srvwrp::logsrv::LogCore& logCore = srvwrp::logsrv::LogCore::getInstance();

        logCore.setAppName(appName);

        logCore.addSink(new srvwrp::logsrv::DLTSink(
            dltAppId,
            dltCtxId,
            dltDesc
        ));

    #ifdef BUILD_BOARD
        logCore.addSink(new srvwrp::logsrv::ConsoleSink); //logcore will auto release sink on desconstruct
    #ifdef USE_FILE_LOG
        logCore.addSink(new srvwrp::logsrv::FileSink("/var/iauto/log.txt"));
    #endif //USE_FILE_LOG
    #else
        logCore.addSink(new srvwrp::logsrv::ConsoleSink); //logcore will auto release sink on desconstruct
    #endif
// Fix klocwork START
        (void)logCore.setupDeathLogging();
// Fix klocwork END

        gQtCppLogModuleId = logCore.registerModule("QTCpp",srvwrp::logsrv::LogSeverity::LOG_INF);
        qmlRegisterSingletonType<UILogger>("UICommon.Base",1,0,"Logger",&UILogger::create);
        //Fix klocwork START
        (void)qmlRegisterType<HMISystemModel>("UICommon.Base",1,0,"HMIGenaralState");
        //Fix klocwork END
        qmlRegisterSingletonType<HMISystemModel>("UICommon.Base",1,0,"HMI_SYS", &HMISystemModel::create);

        //Fix klocwork START
        (void)HMISystemModel::getInstance();
        (void)uicommon::VehicleGeneralStateModel::getInstance();
        (void)qmlRegisterType<uicommon::SysUI>("UICommon.SysUI",1,0,"SysUI");
        (void)qInstallMessageHandler(qMessageHandler);
        //Fix klocwork END

        (void)qmlRegisterType<SettingBattery>("SettingBattery", 1,0, "SettingBatteries");
        (void)qmlRegisterType<TitleModel>("UICommon.Models", 1,0, "TitleModel");
        return 0;
    }
}

static int font_load_manual() {
    QString fontDir = "/usr/share/fonts/";
    QStringList FontSource = {
        fontDir + "MXiangHeHeiTC-Light.ttf",
        fontDir + "MXiangHeHeiTC-Medium.ttf",
        fontDir + "MXiangHeHeiTC-Regular.ttf",
        fontDir + "MXiangHeHeiTC-Thin.ttf",
        fontDir + "Suzuki_IFNeueFrutigerWLD-Lt.ttf",
        fontDir + "Suzuki_IFNeueFrutigerWLD-Md.ttf",
        fontDir + "Suzuki_IFNeueFrutigerWLD-Th.ttf",
        fontDir + "Suzuki_IFNeueFrutigerWLD.ttf",
        fontDir + "Suzuki_IFNumericfont-Light.ttf",
        fontDir + "Suzuki_IFNumericfont-Thin.ttf",
        fontDir + "Suzuki_IFNumericfont.ttf",
        fontDir + "Suzuki_IFSvatantraDeva-Lt.ttf",
        fontDir + "Suzuki_IFSvatantraDeva-Md.ttf",
        fontDir + "Suzuki_IFSvatantraDeva-Th.ttf",
        fontDir + "Suzuki_IFSvatantraDeva.ttf",
        fontDir + "Suzuki_IFTazuganeInfo-Light.ttf",
        fontDir + "Suzuki_IFTazuganeInfo-Md.ttf",
        fontDir + "Suzuki_IFTazuganeInfo-Thin.ttf",
        fontDir + "Suzuki_IFTazuganeInfo.ttf"
    };

    for (const auto& font : FontSource) {
        int fontID = QFontDatabase::addApplicationFont(font);
        if(-1 != fontID){
            auto fontFamilies = QFontDatabase::applicationFontFamilies(fontID);
        }
    }
    return 0;
}
