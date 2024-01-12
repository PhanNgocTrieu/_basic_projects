#include "csengine.h"
#include <UICommon.h>

#ifdef HMI_SHOW_TEST_APP
#include <stubengine.h>
#endif
//Klocwork-Fix rule MISRA.DEFINE.BADEXP.CPP, MISRA.USE.DEFINE-START
//#define ENGINE_NAME "CSEngine"
static const char* ENGINE_NAME = "CSEngine";
//Klocwork-Fix rule MISRA.DEFINE.BADEXP.CPP, MISRA.USE.DEFINE-END

CsApp::CSEngine::CSEngine(QObject *_parent)
    : QObject{_parent}
    , m_csProvider(CsApp::ConnectedServiceProvider::getInstance())
{
    (void)uicommon::initialize();
    (void)qmlRegisterSingletonType<uicommon::VehicleGeneralStateModel>("UICommon.Base",1,0,"VehicleGeneralState",&uicommon::VehicleGeneralStateModel::create);
    (void)uicommon::setup_logger("CSApp","UICS","SRVW","Logging for CSApp");
    serv::LoggerCore::getInstance().initialize([this](const std::string& srvName)->uint32_t {
        return srvwrp::logsrv::LogCore::getInstance().registerModule(srvName,srvwrp::logsrv::LogSeverity::LOG_INF);
    });
    serv::LoggerCore::getInstance().setLoggingConsumerHandle([this](uint32_t logId, uint32_t severity, const std::string& content) {
        srvwrp::logsrv::Logger _logger;
        _logger.createRecord(static_cast<srvwrp::logsrv::LogSeverity>(severity),logId).getStreamer() << content;
    });
    m_SysIF = &hmi::service::sysifapps::getInstance();
    // m_csModel = new CsApp::CSModel(this);
    m_csProvider->initialize();
    // Register model
    registerGlobalContextEvent();
    WLOG_INFO(ENGINE_NAME << "initialized completed");
    m_SysIF->isReady("13_CS_App");
}

CsApp::CSEngine::~CSEngine()
{
    if (m_App != nullptr) {
        delete m_App;
        m_App = nullptr;
    }
    // delete m_csModel;
}

/*!
 * \brief CSEngine::getInstance to get only one object of CSEngine because this is where we get and process data
 * \return
 */
CsApp::CSEngine *CsApp::CSEngine::getInstance()
{
    static CSEngine instance;
    return &instance;
}

/*!
 * \brief Registering context property for CS app
 */
void CsApp::CSEngine::registerContextProperty() {

}

/*!
 * \brief CSEngine::exec run executable in QGuiApplication object
 * \return
 */
int CsApp::CSEngine::exec()
{
    int retVal{0};
    if (m_App != nullptr)
    {
        retVal = m_App->exec();
    }else{
        //do nothing
    }
    return retVal;
}

/*!
 * \brief CSEngine::setApplication to set the initial QGuiApplication object
 * \param app
 */
void CsApp::CSEngine::setApplication(QGuiApplication *app)
{
    if (app != nullptr){
        m_App = app;
    }
}

/*!
 * \brief CSEngine::connectSignals to connect signals with signals, slots or functions to get needed data
 */
void CsApp::CSEngine::connectSignals()
{
    QObject::connect(m_SysIF, &hmi::service::sysifapps::sendDataThroughSys, this, [this](const QString& pro, const QDBusVariant& val){
    });
    QObject::connect(m_SysIF, &hmi::service::sysifapps::signallingDataThroughSys, this, &CsApp::CSEngine::receiveDataFromSys);
//    QObject::connect(csCommon, &CSCommon::sendDataThroughSystem, m_SysIF, &hmi::service::sysifapps::sendDataThroughSys);
#ifdef HMI_SHOW_TEST_APP
    QObject::connect(m_SysIF, &hmi::service::sysifapps::signalErrorCodeForTest, this, &CsApp::CSEngine::receiveErrorCodeFromAppTest);
#endif

    // QObject::connect(m_csModel, &CsApp::CSModel::needCompletedStatus, this, [this](){
    //     m_SysIF->sendDataThroughSys("isCompleted",QDBusVariant(QVariant("")));
    // });
}

/*!
 * \brief CSEngine::receiveErrorCodeFromAppTest to receive data sent from apptest (Only run when build pc)
 * \param appID
 * \param errorCode
 */
#ifdef HMI_SHOW_TEST_APP
void CsApp::CSEngine::receiveErrorCodeFromAppTest(QString appID, QString errorCode)
{
    //Process received data from apptest here
    if (appID.contains("aisinlbs"))
    {
        auto parts = errorCode.split("|");
        if (parts.size() == 2)
        {
            qDebug() << "receiver"<<parts[0] << " message:" << parts[1];
            StubEngine::instance()->sendMessage(parts[0].toStdString(), parts[1].toStdString());
        }
    }
    else if (appID.contains("ACC_OFF")) {
        // m_csModel->StartWriting();
    }else if(appID.contains("CONNECTED_SERVICE")){
//        if(errorCode == "4") m_csModel->setIsDisplayWithIdScreen("CS_04");
//        else if(errorCode == "5") m_csModel->setIsDisplayWithIdScreen("CS_05");
//        else if(errorCode == "6") m_csModel->setIsDisplayWithIdScreen("CS_06");
    }
    else if (appID.contains("RESET_CS_INI")) {
        // m_csModel->cleanIniFile();
    }
}

#endif

/*!
 * \brief CSEngine::receiveDataFromSys to receive data sent from systemIF
 * \param pro
 * \param var
 */
void CsApp::CSEngine::receiveDataFromSys(const QString &pro, const QDBusVariant &var)
{
    WLOG_INFO(ENGINE_NAME << " receiveDataFromSys pro: " << pro.toStdString() << " - var: " << var.variant().toString().toStdString());
    static std::map<QString, std::function<void(const QDBusVariant &)>> handles {
    //     {"CSRequestNetwork", [this](const QDBusVariant &var) { m_csModel->requestNetworkConnectionReset(); }},
    //     {"GET_CURRENT_SCREEN", [this](const QDBusVariant &var) {
    //         if(var.variant().toString() == "HOME_APP") {m_csModel->setIsHome(true);}
    //         else { m_csModel->setIsHome(false); }}},
    //     {"INIT_FINISED", [this](const QDBusVariant &var) { // This one would be use for checking whether CSModel was initialized before HomeApp
    //         // WLOG_INFO(ENGINE_NAME << "Received Data Bus INIT_FINISED - variant (bool): " << var.variant().toBool());
    //         // m_csModel->startOpening(); 
    //         // if (var.variant().toBool()) {
    //             // m_csModel->setSuzukiInitCompleted(true);
    //         // }
    //         // WLOG_INFO(ENGINE_NAME << "Call Start Open Completed");
    //     }},
    //     {"SHOW_NEXT_POPUP", [this](const QDBusVariant &var) { 
    //         WLOG_INFO(ENGINE_NAME << "SHOW_NEXT_POPUP Call");
    //         m_csModel->setIsCanOpen(true); 
    //     }},
    //     {"CSRequestStartCall", [this](const QDBusVariant &var) { m_csModel->requestStartCall(); }},
    //     {"CS_READ", [this](const QDBusVariant &var) { m_csModel->receivePopupInfoFromSetting(var.variant().toString()); }},
    //     {"CSItemDelete", [this](const QDBusVariant &var) { m_csModel->deleteConnectedInformation(var.variant().toString()); }},
    //     {"CSItemGetOEM", [this](const QDBusVariant &var) { m_csModel->requestOEMStatus(); }},
    //     {"SET_REMINDER_OFF", [this](const QDBusVariant &var){m_csModel->setConnectedInfomationRemindexOff(var.variant().toString());}},
        {"RESPONSE_POPUP_STATE", [this](const QDBusVariant &var){ // This one would be use for checking whether CSModel was initialized after HomeApp
            WLOG_INFO(ENGINE_NAME << " is Popup Ready: " << var.variant().toInt());
            if (var.variant().toString().toStdString() == "true") {
                // m_csModel->setPopupStateReady(true);
                m_csProvider->popupIsReady();
            }
        }},
        {"RESPONSE_HOME_STATE", [this](const QDBusVariant &var){
            WLOG_INFO(ENGINE_NAME << " is Home Ready: " << var.variant().toInt());
            if (var.variant().toString().toStdString() == "true") {
                // m_csModel->setSuzukiInitCompleted(true);
                m_csProvider->homeIsReady();
            }
        }},
    //     {"GetCurrentPathVA",[this](const QDBusVariant &var){
    //          QString app = var.variant().toString();
    //          if (app == "13_CS_App") {
    //              QString path = uicommon::HMIViewer::getInstance()->getCurrentScreenPath();
    //              m_SysIF->sendDataThroughSys("VA_CS_APP", QDBusVariant(QVariant(path)));
    //          }
    //      }},
    };

    auto handle = handles.find(pro);
    if(handle != handles.end())
    {
        handle->second(var);
    }
}
