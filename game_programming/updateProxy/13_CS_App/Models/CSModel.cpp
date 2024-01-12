#include "CSModel.h"
#include <QDebug>

#undef WLOG_DEBUG
#define WLOG_DEBUG WLOG_INFO 

#ifdef BUILD_BOARD
    //Klocwork-Fix rule MISRA.USE.DEFINE-START
    inline const char* CSService_SETTING_PATH = "/var/iauto/CSServiceSetting.ini";
#else
    inline const char* CSService_SETTING_PATH = "../../system-ui/CSServiceSetting.ini";
    //Klocwork-Fix rule MISRA.USE.DEFINE-END
#endif
//Klocwork-Fix rule MISRA.USE.DEFINE-START
inline const int EXPIRED_POPUP_TIMER 	= 8000;
inline const char* MODEL_NAME 			= "CSModel";
//Klocwork-Fix rule MISRA.USE.DEFINE-END
std::unordered_map<QString, POPUPENUM::E::EVT_STATE_ID_ROOT> CsApp::CSModel::m_displayScreenID = {
    {"CS_03", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_03},
    {"CS_04", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_04},
    {"CS_05", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_05},
    {"CS_06", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_06},
    {"CS_07", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_07},
    {"CS_08", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_08},
    {"CS_12", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_12},
    {"CS_13", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_13},
    {"CS_16", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_16},
    {"CS_17", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_17},
    {"CS_18", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_18},
    {"CS_19", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_19},
    {"CS_20", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_20},
    {"CS_21", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_21},
    {"CS_22", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_22},
    {"CS_23", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_23}
};
//Klocwork-Fix rule MISRA.LINKAGE.EXTERN-START
std::string CsApp::CSModel::_pretty(const srvwrp::ConnectedServiceWrapper::ConnectedInformationKind& _kind)
{
    std::string ret;
    switch (_kind) {
        case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Recall:
		    ret = "Recall";
			break;
        case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::VehicleInspection:
		    ret = "VehicleInspection";
			break;
        case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::PeriodicInspection:
		    ret = "PeriodicInspection";
			break;
        case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Inspection:
		    ret = "Inspection";
			break;
        case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Failure:
		    ret = "Failure";
			break;
        default:
		    ret = "Default";
			break;
    }
	return ret;
}
//Klocwork-Fix rule MISRA.LINKAGE.EXTERN-END

/*!
 * \brief CSModel::CSModel
 * \param parent
 */
CsApp::CSModel::CSModel(QObject *_parent)
    : QObject{_parent},
      m_connectedSrvWrap(srvwrp::ConnectedServiceWrapper::instance()),
      m_variantService(aisinlbssdk::VariantService::getInstance()),
      m_variantVehicleSvwrp(srvwrp::VehicleServiceWrapper::instance()),
      headerIF(uicommon::HMIHeaderServiceProxy::getInstance()),
      m_setting(uicommon::UISetting::ConstructTuple("connectedService", CSService_SETTING_PATH, [this]() {
        QMetaObject::invokeMethod(this,"onConnectedSrvUpdated" , Qt::QueuedConnection);
      })),
      m_UIComCtrl(CsApp::UICommunication::getInstance())
{
    WLOG_INFO("Init CSModel");
    // m_UIComCtrl.sendDataThroughSys("isCompleted", QDBusVariant(QVariant("")));
    this->initialize();
}

/*!
 * \brief CSModel::~CSModel
 */
CsApp::CSModel::~CSModel() {
    this->handleToWriting();
    CsApp::SafeDEL(m_SysIF);
    CsApp::SafeDEL(m_timer);
}

/*!
 * \brief CSModel::initialize
 */
void CsApp::CSModel::initialize() {
    m_SysIF = &hmi::service::sysifapps::getInstance();    
    m_timer = new QTimer(this);

    auto insert_func = [this](const QString& name, bool isDisp, bool isReminder) {
        m_displayScreen[name].isDisplay = isDisp;
        m_displayScreen[name].isReminder = isReminder;
    };
    insert_func("CS_03", false, false);
    insert_func("CS_04", false, false);
    insert_func("CS_05", false, false);
    insert_func("CS_06", false, false);
    insert_func("CS_07", false, false);
    insert_func("CS_08", false, false);
    // insert_func("CS_18", false, false);
    // insert_func("CS_19", false, false);
    // insert_func("CS_20", false, false);
    // insert_func("CS_21", false, false);
    // insert_func("CS_22", false, false);
    // insert_func("CS_23", false, false);
    WLOG_INFO("Init initialize");
    m_curPopup = m_displayScreen.begin();
    
    m_variantSvID = m_variantVehicleSvwrp->init();
    m_connectedSrvConnections = m_connectedSrvWrap->registerCallback(srvwrp::ConnectedServiceWrapper::Event::MAX, std::bind(&CsApp::CSModel::connectedServiceInforCb, this, std::placeholders::_1, std::placeholders::_2));
    m_variantVehicleSvwrp->registerVehicleServiceInfo(m_variantSvID, std::bind(&CsApp::CSModel::onCarSpeedChanged, this, std::placeholders::_1));
    m_variantService->onDealerOEMChanged.regEventFunc(std::bind(&CsApp::CSModel::requestOEMStatus, this));

    //Fix klocwork START
    (void)m_connectedSrvWrap->init();
    //Fix klocwork END
    
    QObject::connect(m_timer, &QTimer::timeout, this, [this]() {
        m_timer->stop();
        m_isCanOpenScreen = true;
        m_isPopupNotExpiredTimer = false;
    });
    
    m_UIComCtrl.sendDataThroughSys("CSModelCheckCompleted", QDBusVariant(QVariant("")));
    emit needCompletedStatus();
    m_UIComCtrl.sendDataThroughSys("REQUEST_HOME_STATE", QDBusVariant(QVariant("")));
    m_UIComCtrl.sendDataThroughSys("REQUEST_POPUP_STATE", QDBusVariant(QVariant("")));
    WLOG_INFO(MODEL_NAME << " completed Initialized ");
}


/*!
 * \brief CSModel::collectingData 
 */
void CsApp::CSModel::collectingData() {
    auto val = this->readMemory("connectedService","screenList");
    // std::cout << "Value of reading: " << val.toString() << std::endl;
    if (!val.isNull()) {
//        auto listScreens = val.toString();
//        auto splitScreen = listScreens.split(',');
//        int size_ = splitScreen.size();
//        for (int idex = 0; idex < size_; ++idex) {
//            if (splitScreen[idex] != "") {
//                m_displayScreen[splitScreen[idex]].isDisplay = true;
//            }
//        }
//        auto infoPopupList = val.toStringList();
        m_infoList = val.toStringList();
        for(auto eleInfo : m_infoList){
            auto splitDataInfo = eleInfo.split('#');
            m_displayScreen[splitDataInfo[3]].isDisplay = true;
        }
    }
}


/*!
 * \brief CSModel::connectedServiceInforCb
 * \param event
 * \param cntSrvInf
 */
void CsApp::CSModel::connectedServiceInforCb(srvwrp::ConnectedServiceWrapper::Event tempEvent,
                                      const srvwrp::ConnectedServiceWrapper::ConnectedServiceInfo & cntSrvInf)
{
    WLOG_INFO("[connectedServiceInforCb]");
    // Confirm index
    switch (tempEvent)
    {
    case srvwrp::ConnectedServiceWrapper::Event::INIT: {
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-START
        (void)headerIF.setCntdSrvStgState((cntSrvInf.connectedSetupFlag == srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag::On));
        (void)headerIF.setTelematicsSrvState((cntSrvInf.teleContractFlag == srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag::On));
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-END
        break;
    }
    case srvwrp::ConnectedServiceWrapper::Event::INFO_CHANGED: {
        handleConnectedSerivceList(cntSrvInf.infoList);
        handleConnectedServiceSettingList(cntSrvInf.infoList);
        break;
    }
    case srvwrp::ConnectedServiceWrapper::Event::NETWORK_RESET_RESULT:
        handleNetworkResetResult(cntSrvInf.networkConnResetResult);
        break;
    case srvwrp::ConnectedServiceWrapper::Event::CONNECTED_CHANGED:
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-START
        (void)headerIF.setCntdSrvStgState((cntSrvInf.connectedSetupFlag == srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag::On));
        (void)headerIF.setTelematicsSrvState(cntSrvInf.teleContractFlag == srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag::On);
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-END
        break;
    case srvwrp::ConnectedServiceWrapper::Event::DCM_WAVE_STATUS:
    {
        std::optional<srvwrp::ConnectedServiceWrapper::DcmWaveStatus> dcmWaveStatus = cntSrvInf.dcmWaveStatus;
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET, MISRA.C_CAST-START
        (void)headerIF.setRadioWaveIntensity(static_cast<int>(dcmWaveStatus.value()));
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET, MISRA.C_CAST-END
        break;
    }
    default: {
        break;
    }
    }
}

/*!
 * \brief CSModel::handleConnectedSerivceList this function is used to getSzkTroubleSupportAvailability to handle displayScreen and send Data and serviceList to 1_Setting
 * \param serviceList
 */
void CsApp::CSModel::handleConnectedSerivceList(const std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation>& serviceList)
{
    WLOG_INFO("" << MODEL_NAME << " => handleConnectedSerivceList ");
    m_connectInfor = serviceList;
    auto szkTrouble = m_variantService->getSzkTroubleSupportAvailability();
    for (auto itr = m_connectInfor.begin(); itr != m_connectInfor.end(); ++itr) {
        WLOG_INFO("" << MODEL_NAME << " => srvwrp::ConnectedServiceWrapper::ConnectedInformationKind: " << CsApp::CSModel::_pretty(itr->kind));
        switch (itr->kind) {
            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Recall: {
                m_displayScreen["CS_03"].isDisplay = true;
                if (itr->reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) {
                    this->m_displayScreen["CS_03"].isReminder = true;
                    WLOG_INFO("" << MODEL_NAME << "=> Set CS_03 to true");
                }
                break;
            }

            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::VehicleInspection: {
                m_displayScreen["CS_04"].isDisplay = true;
                if (itr->reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) {
                    this->m_displayScreen["CS_03"].isReminder = true;
                    WLOG_INFO("" << MODEL_NAME << "=> Set CS_04 to true");
                }
                break;
            }

            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::PeriodicInspection: {
                m_displayScreen["CS_05"].isDisplay = true;
                if (itr->reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) {
                    this->m_displayScreen["CS_05"].isReminder = true;
                    WLOG_INFO("" << MODEL_NAME << "=> Set CS_05 to true");
                }
                break;
            }

            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Inspection: {
                m_displayScreen["CS_06"].isDisplay = true;
                if (itr->reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) {
                    this->m_displayScreen["CS_06"].isReminder = true;
                    WLOG_INFO("" << MODEL_NAME << "=> Set CS_06 to true");
                }
                break;
            }

            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Failure: {    // CS_07 || CS_08 
                if (szkTrouble == SzkTroubleSupport::Supported) {
                    // m_displayScreen["CS_07"].isDisplay = true;
                    if (itr->reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) {
                        this->m_displayScreen["CS_07"].isReminder = true;
                        WLOG_INFO("" << MODEL_NAME << "=> Set CS_07 to reminder");
                    }
                    requestShowPopup("CS_07");
                    WLOG_INFO("" << MODEL_NAME << "=> show CS_07");
                }
                else{
                    // m_displayScreen["CS_08"].isDisplay = true;
                    if (itr->reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) {
                        this->m_displayScreen["CS_08"].isReminder = true;
                    }
                    WLOG_INFO("" << MODEL_NAME << "=> show CS_08");
                    requestShowPopup("CS_08");
                }
                break;
            }

            default: {
                WLOG_INFO("" << MODEL_NAME << "=> Else Case");
                break;
            }
        }
    }

    if (m_isCompletedInitSuzuki && m_isPopupReady && m_isCompletedOpening) {
        if (m_displayScreen["CS_07"].isDisplay) {
            WLOG_INFO(MODEL_NAME << " Call Popup CS_07");
            requestShowPopup("CS_07");
        }
        else if (m_displayScreen["CS_08"].isDisplay) {
            WLOG_INFO(MODEL_NAME << " Call Popup CS_08");
            requestShowPopup("CS_08");
        }
    }
}

/**
 * @brief CSModel::handleConnectedServiceSettingList
 * @param serviceList AddItemList from getConnectedInfomation and send Data and sizeList to 1_Setting
 */
void CsApp::CSModel::handleConnectedServiceSettingList(const std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation> &serviceList)
{
    WLOG_INFO("" << MODEL_NAME << "=> Request Showing Popup CS_07");
    if(m_checkIsDeteled){
        m_infoList.clear();
    }
    QStringList m_tempInfoList;
    std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation> inforCSSetting;
    //Klocwork-Fix rule VA_UNUSED.INIT-START
    //auto szkTrouble = m_variantService->getSzkTroubleSupportAvailability();
    //Klocwork-Fix rule VA_UNUSED.INIT-END
    int listSrvSize = m_connectedSrvWrap->getConnectedInformation().size();
    if(listSrvSize >= 1){
        for(auto &strItemService : serviceList) {
            if(inforCSSetting.size() >= 6){  break;}

            QString temp = "";
            if (strItemService.kind == srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Recall) {
                temp = "CS_03";
            }
            else if (strItemService.kind == srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::VehicleInspection){
                temp ="CS_04";
            }
            else if (strItemService.kind == srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::PeriodicInspection){
                temp ="CS_05";
            }
            else if(strItemService.kind == srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Inspection) {
                temp = "CS_06";
            }
            else if (strItemService.kind == srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Failure) {
            auto szkTrouble = m_variantService->getSzkTroubleSupportAvailability();
                //Klocwork-Fix rule VA_UNUSED.INIT-START
                if (szkTrouble == SzkTroubleSupport::Supported) {
                //Klocwork-Fix rule VA_UNUSED.INIT-END
                    temp = "CS_07";
                }
                //Klocwork-Fix rule VA_UNUSED.INIT-START
                else if (szkTrouble == SzkTroubleSupport::NotSupported) {
                //Klocwork-Fix rule VA_UNUSED.INIT-END
                    temp = "CS_08";
                }else{
                    //MISRA.IF.NO_ELSE
                }
            }
            else {/*do nothing*/}
            WLOG_INFO("" << MODEL_NAME << "=> Temp: " << temp.toStdString());
    //        if(static_cast<uint32_t>(strItemService.year) != 0 && temp != ""){
    //            m_displayScreen[temp].isYear = static_cast<uint32_t>(strItemService.year);
    //            m_displayScreen[temp].isMonth = static_cast<uint32_t>(strItemService.month);
    //            m_displayScreen[temp].isDay = static_cast<uint32_t>(strItemService.day);
    //            qWarning() << "handleConnectedServiceSettingList 1111 - year: " << m_displayScreen[temp].isYear
    //                       << "- month: " <<  m_displayScreen[temp].isMonth
    //                       <<"- day: " << m_displayScreen[temp].isDay;
    //        }

            int yearTmp = static_cast<int>(strItemService.year);
            int monthTmp = static_cast<int>(strItemService.month);
            int dayTmp = static_cast<int>(strItemService.day);
#ifdef BUILD_BOARD
            QDate date(yearTmp + 2000, (monthTmp <= 0) ? 1 : monthTmp, (dayTmp <= 0) ? 1 : dayTmp);
#else
            QDate date(yearTmp, (monthTmp <= 0) ? 1 : monthTmp, (dayTmp <= 0) ? 1 : dayTmp);
#endif
            WLOG_INFO("" << MODEL_NAME << "=> Set " << temp.toStdString()
                        << " - day: " << dayTmp
                        << " - month: " << monthTmp
                        << " - year: " << yearTmp);

            int yearsDifference = date.daysTo(QDate::currentDate());
            if( (std::abs(yearsDifference) / 365) < 2 ){
                inforCSSetting.push_back(strItemService);
                QString tempItemListCS= QString(date.toString("yyyy/MM/dd"))
                        .append("#").append(QString::number(static_cast<int>(strItemService.kind)))
                        .append("#").append(QString::number(static_cast<int>(strItemService.index)))
                        .append("#").append(temp)
                        .append("#").append(QString::number(m_displayScreen[temp].isReminder))
                        .append("#").append(QString::number(m_displayScreen[temp].isDisplay));
                m_tempInfoList.push_back(tempItemListCS);
                WLOG_INFO("" << MODEL_NAME << "=> Item Need To Append (Connected String): " << tempItemListCS.toStdString());
                if(m_infoList.count() > 0){
                    bool checkDulicateItem = false;
                    for(int idx = 0; idx < m_infoList.count(); idx++){
                        auto splitInfoItem = m_infoList[idx].split("#");
                        if(temp == splitInfoItem[3]){
                            if(QString(date.toString("yyyy/M/d")) == splitInfoItem[0]){
                                checkDulicateItem = true;
                            }
                        }
                    }
                    if(!checkDulicateItem){
                        WLOG_INFO("" << MODEL_NAME << "=> Pushing Item Into List: " << tempItemListCS.toStdString());
                        m_infoList.push_back(tempItemListCS);
                    }
                } else{
                    WLOG_INFO("" << MODEL_NAME << "=> Pushing Item Into Empty List: " << tempItemListCS.toStdString());
                    m_infoList.push_back(tempItemListCS);
                }
            }
        }
    }
    m_checkIsDeteled = false;
    m_SysIF->sendDataThroughSys("DataCSList", QDBusVariant(QVariant(m_tempInfoList)));
    WLOG_INFO("" << MODEL_NAME << "=> Sending throug dbus");
}

/*!
 * \brief CSModel::requestOEMStatus
 * \return
 */
bool CsApp::CSModel::requestOEMStatus()
{
    bool retVal = false;
    uint8_t dealeroem = static_cast<uint8_t>(m_variantService->getDealerOEM());
    (void)qRegisterMetaType<uint8_t>("uint8_t");
    (void)QMetaObject::invokeMethod(this, "onDealerOEMChangedHandleCs", Q_RETURN_ARG(bool, retVal), Q_ARG(uint8_t, dealeroem));
    return retVal;
}

bool CsApp::CSModel::onDealerOEMChangedHandleCs(uint8_t dealeroem)
{
    return (dealeroem == static_cast<uint8_t>(DealerOEM::S));
}

/*!
 * \brief CSModel::handleNetworkResetResult
 * \param result
 */
void CsApp::CSModel::handleNetworkResetResult(const srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult &result)
{
    switch (result) {
    case srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Success:
        if (m_networkConnectionResetResult == srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Resetting) {
            requestShowPopup("CS_16");
            m_networkConnectionResetResult = result;
        }
        break;
    case srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Resetting:
        m_SysIF->sendDataThroughSys("RequestShowResettingText",QDBusVariant(QVariant(true)));
        m_networkConnectionResetResult = result;
        break;
    case srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Failure:
        if (m_networkConnectionResetResult == srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Resetting) {
            requestShowPopup("CS_17");
            m_networkConnectionResetResult = result;
        }
        break;
    default:
        break;
    }
}

/*!
 * \brief CSModel::handleToWriting this method handles of writing screen
 */
void CsApp::CSModel::handleToWriting() {
//    QString writeScreenIDList = "";
    QStringList writeInfoPopupList;
#ifndef BUILD_BOARD
        int count = 0;
#endif
//    for (auto itr = m_displayScreen.begin(); itr != m_displayScreen.end(); ++itr) {
//        if (itr->first == "CS_07") {
//            break;
//        }
        for(int idx = 0; idx < m_infoList.count(); idx++){
            //        if (itr->second.isDisplay || itr->second.isReminder) {
            auto splitInfoItem = m_infoList[idx].split("#");
            if((splitInfoItem[3] != "CS_07") && (splitInfoItem[3] != "") && (splitInfoItem[3] != "CS_08")){
                writeInfoPopupList.append(m_infoList[idx]);
#ifndef BUILD_BOARD
                count++;
#endif
            }
        }
#ifndef BUILD_BOARD
    if (count > 0) {
        writeInfoPopupList.append("2023/9/30#1#6#CS_04#0#1");
        writeInfoPopupList.append("2023/10/1#1#7#CS_05#0#1");
        writeInfoPopupList.append("2023/10/2#1#8#CS_06#0#1");
    }
#endif

//    writeScreenIDList = writeScreenIDList.left(writeScreenIDList.lastIndexOf(QChar(',')));
    this->writingMemory("connectedService", "screenList", writeInfoPopupList);
}

/*!
 * \brief This method for openning the popup one by one
 */
void CsApp::CSModel::openConnectedServiceInfor()
{
    //Klocwork-Fix rule MISRA.ITER.ONETERM-START
    bool loopControl = false;
    //Klocwork-Fix rule MISRA.ITER.ONETERM-END
    do {
        if (!m_isCompletedInitSuzuki || !m_isPopupReady) {
                //Klocwork-Fix rule MISRA.ITER.ONETERM-START
                loopControl = true;
                //Klocwork-Fix rule MISRA.ITER.ONETERM-END
        }

        if (m_isFromSetting && (loopControl == false)) {
                m_isFromSetting = false;
                //Klocwork-Fix rule MISRA.ITER.ONETERM-START
                loopControl = true;
                //Klocwork-Fix rule MISRA.ITER.ONETERM-END
                //break;
        }

        if (m_curPopup == m_displayScreen.end() && (loopControl == false)) {
                WLOG_INFO(MODEL_NAME << "Finished Passing whole message of CS");
                m_isCompletedOpening = true;
                m_isFinishPassingCS = true;
                m_curPopup = m_displayScreen.begin();
                //Klocwork-Fix rule MISRA.ITER.ONETERM-START
                loopControl = true;
                //Klocwork-Fix rule MISRA.ITER.ONETERM-END
        }

        if(loopControl == false)
        {
            m_timer->stop();
            // Handle with isDrivingMode when closing popup
            if (m_isDriving && isInRangeDriving(m_curPopup->first)) {
            if (m_isPopupNotExpiredTimer) {
                // Reverse popup index
                m_curPopup--;
                // set again the status of display to true when popup close before 8 seconds
                m_curPopup->second.isDisplay = true;
                // Reset flag of experied timer of popup
                m_isPopupNotExpiredTimer = false;
            }
            //Klocwork-Fix rule MISRA.ITER.ONETERM-START
            loopControl = true;
            //Klocwork-Fix rule MISRA.ITER.ONETERM-END
            }
        }
        
        if (loopControl == true) {
            break;
        }

        if (m_curPopup->second.isDisplay == true)
        {
            // Dbus signal for opening popup
            requestShowPopup(m_curPopup->first);

            // When opening the popup -> set the display to false
            m_curPopup->second.isDisplay = false;

            // Turn the flag off to prevent of the next processing of popup, until the flag is turn on again
            m_isCanOpenScreen = false;

            // Setting flag for trigger timer of closing popup
            m_isPopupNotExpiredTimer = true;

            // Checking timer of closing popup before 8s or not
            m_timer->start(EXPIRED_POPUP_TIMER);
        }
        // Update the next popup
        m_curPopup++;
    } while (m_isCanOpenScreen == true);
}

/*!
 * \brief CSModel::receivePopupInfoFromSetting this method used for receiving dbus-signal from setting when open CS screen
 * \param screenIDMsg
 */
void CsApp::CSModel::receivePopupInfoFromSetting(const QString& screenIDMsg)
{
    if (screenIDMsg == "") {
        m_isFromSetting = true;
    }
    else
    {
        for(int idx = 0; idx < m_infoList.count(); idx++){
            auto splitItem = m_infoList[idx].split("#");
            if(splitItem[3] == screenIDMsg){
                auto foundIt = m_displayScreen.find(splitItem[3]);
                if (foundIt != m_displayScreen.end()) {
                    foundIt->second.isDisplay = false;
                    break;
                }
            }
        }
    }
//    auto foundIt = m_displayScreen.find(screenIDMsg);
//    if (foundIt != m_displayScreen.end()) {
//        foundIt->second.isDisplay = false;
//    }
    // if (screenIDMsg != "") {
    //     m_displayScreen[screenIDMsg].isDisplay = false;
    // }
    // m_isFromSetting = true;
}

/*!
 * \brief CSModel::onCarSpeedChanged
 * \param info
 */
void CsApp::CSModel::onCarSpeedChanged(const srvwrp::VehicleServiceInfo &info)
{
    WLOG_INFO(MODEL_NAME << " Start onCarSppedChanged ");
    if (!m_isPopupReady || !m_isCompletedInitSuzuki) {
        WLOG_INFO(MODEL_NAME << " Popup is not ready, break out ");
        return;
    }

    bool isJapan = info.getIsJapanDestination();
    // Fix klocwork START
    double speedKmh = static_cast<double>(info.getSpeedKmh());
    if(((speedKmh > static_cast<double>(5)) || (fabs(speedKmh - static_cast<double>(5)) < 1e-6)) && (isJapan == true)){
    // Fix klocwork END
        m_isDriving = true;
        this->openConnectedServiceInfor();
    }
    // Fix klocwork START
    else if((speedKmh < static_cast<double>(3)) && (isJapan == true)){
    // Fix klocwork END
        m_isDriving = false;
        m_isCanOpenScreen = true;
        this->openConnectedServiceInfor();
    }else{
        //
    }
}

/*!
 * \brief CSModel::requestShowPopup
 * \param idScreenName
 */
void CsApp::CSModel::requestShowPopup(const QString &idScreenName)
{
    m_UIComCtrl.receiveAppToCallOut("System_Popup",m_displayScreenID[idScreenName]);
}

/**
 * @brief CSModel::setConnectedInfomationRemindexOff
 * @param idScreenName
 */
void CsApp::CSModel::setConnectedInfomationRemindexOff(const QString& idScreenName)
{
    for(int idx = m_infoList.count() - 1; idx >= 0; idx--){
        auto splitInfoItem = m_infoList[idx].split("#");
        if(idScreenName == splitInfoItem[3]){
            auto splitDate = splitInfoItem[0].split("/");
            m_connectedSrvWrap->setConnectedInformationReminderOff(splitInfoItem[1].toInt(), splitInfoItem[4].toInt(), splitDate[2].toInt(), splitDate[1].toInt(), splitDate[0].toInt());
            m_infoList.remove(idx);
        }
    }
}

/*!
 * \brief This method using to setting the mode of screen (Home or ot Home)
 */
void CsApp::CSModel::setIsHome(const bool& val) {
    m_isHome = val;
}

/*!
 * \brief CSModel::setIsCanOpen
 * \param val
 */
void CsApp::CSModel::setIsCanOpen(const bool& val)
{
    m_isCanOpenScreen = val;
    /*
        The priority of opening Systempopup would have to be order as this (from top to bottom):
            [CS_18;CS_23]
            [CS_07;CS_08]
            [CS_03;CS_06]

    */
    if (!m_isNotCompletedFormCS18_23 && m_isPopupReady && m_isCompletedInitSuzuki) {
        WLOG_INFO(MODEL_NAME << " Not Finish Open CS of XOR[18;23] ");
        m_isNotCompletedFormCS18_23 = false;
        if (m_displayScreen["CS_07"].isDisplay) {
            WLOG_INFO("" << MODEL_NAME << "=> show CS_07");
            requestShowPopup("CS_07");
        }
        else if (m_displayScreen["CS_08"].isDisplay) {
            WLOG_INFO("" << MODEL_NAME << "=> show CS_08");
            requestShowPopup("CS_07");
        }
        return;
    }

    // Start opening the next popup
    this->openConnectedServiceInfor();
    // DBus start Opening SSYP to setting app.
    if(m_isFinishPassingCS){
        m_UIComCtrl.sendDataThroughSys("CS_DISPLAY_END", QDBusVariant(QVariant(true)));
    }
}

/*!
 * \brief CSModel::readMemory This method will be used to read the keys to the file ini.
 * \param groupKey
 * \param key
 * \return
 */
QVariant CsApp::CSModel::readMemory(const QString &groupKey, const QString &_key) {
    //Klocwork-Fix rule MISRA.FUNC.UNUSEDPAR-START
    (void)groupKey;
    //Klocwork-Fix rule MISRA.FUNC.UNUSEDPAR-END
    uicommon::UISetting::Reader reader = m_setting.getReader();
    return reader.read(_key);
#if 0 //FIXME: TBD
    QSettings setting("../../system-ui/CSServiceSetting.ini", QSettings::IniFormat);
    setting.beginGroup(groupKey);
    QVariant ret = setting.value(_key, QVariant());
    setting.endGroup();
    return ret;
#endif
}

/*!
 * \brief CSModel::writingMemory This method will be used to write the keys to the file ini.
 * \param groupKey
 * \param key
 * \param value
 */
void CsApp::CSModel::writingMemory(const QString &groupKey, const QString &_key, const QVariant &_value) {
    //Klocwork-Fix rule MISRA.FUNC.UNUSEDPAR-START
    (void)(groupKey);
    //Klocwork-Fix rule MISRA.FUNC.UNUSEDPAR-END
    uicommon::UISetting::Writter writer = m_setting.getWriter();
    writer.write(_key, _value);
#if 0 //FIXME: TBD
    QSettings setting("../../system-ui/CSServiceSetting.ini", QSettings::IniFormat);
    setting.beginGroup(groupKey);
    setting.setValue(_key, _value);
    setting.endGroup();
#endif
}

/**
 * @brief CSModel::requestNetworkConnectionReset call wrapperConnectedService
 */
void CsApp::CSModel::requestNetworkConnectionReset()
{
    if(m_connectedSrvWrap != nullptr){
        //Fix klocwork START
        (void)m_connectedSrvWrap->requestNetworkConnectionReset();
        //Fix klocwork END
    }
}

/**
 * @brief CSModel::deleteConnectedInformation
 * @param listIndexDelete
 * This function is used to send std::vector<index> to function deleteConnectedInfomation service
 */
void CsApp::CSModel::deleteConnectedInformation(const QString &listIndexDelete)
{
    m_checkIsDeteled = true;
    QStringList obj = listIndexDelete.split("#");
    std::vector<uint32_t> indexsItemSevice;
    for (int var = 0; var < (obj.size() -1); ++var) {
        indexsItemSevice.push_back(obj[var].toInt());
        //int idx = obj[var].toInt();

        // To delete conditional index such as listIndex and Recall and Inspection send setConnectedInformationReminderOff
        for (int idx = 0; idx < m_connectInfor.size() ; ++idx ){
            if(m_connectInfor[idx].index ==  obj[var].toInt() ){
                //Klocwork-Fix rule MISRA.EXPR.PARENS.INSUFFICIENT-START
                if((m_connectInfor[idx].kind == srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Inspection)
                        || (m_connectInfor[idx].kind ==srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Recall) ){
                //Klocwork-Fix rule MISRA.EXPR.PARENS.INSUFFICIENT-END
                    m_connectedSrvWrap->setConnectedInformationReminderOff(static_cast<uint32_t>(m_connectInfor[idx].kind),static_cast<uint32_t>(m_connectInfor[idx].reminder),static_cast<uint32_t>(m_connectInfor[idx].day),static_cast<uint32_t>(m_connectInfor[idx].month),static_cast<uint32_t>(m_connectInfor[idx].year));
                }
            }
        }
    }
    //Fix klocwork START
    (void)m_connectedSrvWrap->deleteConnectedInformation(indexsItemSevice);
    //Fix klocwork END
}

#ifdef HMI_SHOW_TEST_APP
/**
 * @brief CSModel::StartWriting
 */
void CsApp::CSModel::StartWriting() {
    this->handleToWriting();
}

/**
 * @brief CSModel::setIsdisplayWithIdScreen set isDisplay with Id screen name
 */
void CsApp::CSModel::setIsDisplayWithIdScreen(const QString& idPopup)
{
    m_displayScreen[idPopup].isDisplay = true;
}

/*!
 * \brief CSModel::getConnectedServiceSettingState
 * \return
 */
void CsApp::CSModel::cleanIniFile() {
    this->writingMemory("connectedService", "screenList", "");
}
#endif

/*!
 * \brief This method would be use for calling to start opening popup after completed initialize screen
 */
void CsApp::CSModel::startOpening() 
{
    bool _telematicSrvState = this->getTelematicsServiceState();
    bool _ctnSrvSetState = this->getConnectedServiceSettingState();
    bool _highDrvResState = this->getHighDrivingRestrictionState();

    WLOG_DEBUG(MODEL_NAME << " Calling start opening");
    WLOG_DEBUG(MODEL_NAME << " getTelematicsServiceState: " << _telematicSrvState);
    WLOG_DEBUG(MODEL_NAME << " getConnectedServiceSettingState: " << _ctnSrvSetState);
    WLOG_DEBUG(MODEL_NAME << " getHighDrivingRestrictionState: " << _highDrvResState);

    if (_telematicSrvState == true) {
        WLOG_DEBUG(MODEL_NAME << " Showing [CS_20;CS_23] ");
        if (_ctnSrvSetState == true) {
            if (_highDrvResState == true) {
                this->requestShowPopup("CS_21");
                WLOG_DEBUG(MODEL_NAME << " => Call CS_21 ");
            }
            else {
                this->requestShowPopup("CS_20");
                WLOG_DEBUG(MODEL_NAME << " => Call CS_20 ");
            }
        }else {
            if (_highDrvResState) {
                this->requestShowPopup("CS_23");
                WLOG_DEBUG(MODEL_NAME << " => Call CS_23 ");
            }else {
                this->requestShowPopup("CS_22");
                WLOG_DEBUG(MODEL_NAME << " => Call CS_22 ");
            }
        }
    } 
    else {
        WLOG_DEBUG(MODEL_NAME << " Showing [CS_18;CS_19] ");
        if (_highDrvResState) {
            this->requestShowPopup("CS_19");
            WLOG_DEBUG(MODEL_NAME << " => Call CS_19 ");
        } else {
            this->requestShowPopup("CS_18");
            WLOG_DEBUG(MODEL_NAME << " => Call CS_18 ");
        }
    }

#ifdef BUILD_BOARD
    for (auto itr = m_displayScreen.begin();
        itr != m_displayScreen.end();
        ++itr) {
            WLOG_INFO(MODEL_NAME << "=> Screen: " << itr->first.toStdString() << " - isDisp: " << itr->second.isDisplay);
        }
#endif
}

/*!
 * \brief CSModel::requestStartCall
 */
void CsApp::CSModel::requestStartCall()
{
    //Klocwork-Fix rule MISRA.VAR.MIN.VIS, VA_UNUSED.INIT-START
    //srvwrp::ConnectedServiceWrapper::CallState m_callState = srvwrp::ConnectedServiceWrapper::CallState::None;
    //Klocwork-Fix rule MISRA.VAR.MIN.VIS, VA_UNUSED.INIT-END
    if (m_connectedSrvWrap != nullptr) {
        bool flag = false;
        do {
            bool statusStCall = m_connectedSrvWrap->requestStartCall();
            auto callState = m_connectedSrvWrap -> getCallState();
            WLOG_INFO(MODEL_NAME << " Request Status Start Call: " << statusStCall);
            if ( !statusStCall && ! callState.has_value() ) {
                WLOG_INFO(MODEL_NAME << " Request Status Start Call: False or Call Status is out range - Request show CS_13 ");
                requestShowPopup("CS_13");
                break;
            }
            WLOG_DEBUG(MODEL_NAME << " Request Status Start Call: " << static_cast<int>(callState.value()));
            switch(callState.value()) {
                case srvwrp::ConnectedServiceWrapper::CallState::Voice: {
                    WLOG_DEBUG(MODEL_NAME << " srvwrp::ConnectedServiceWrapper::CallState::Voice -  request End Call ");
                    m_connectedSrvWrap->requestEndCall();
                    m_SysIF->sendDataThroughSys("REQUEST_START_CLOSE_POPUP",QDBusVariant(QVariant(true)));
                    break;
                }
                case srvwrp::ConnectedServiceWrapper::CallState::Calling: {
                    WLOG_DEBUG(MODEL_NAME << " srvwrp::ConnectedServiceWrapper::CallState::Calling -  Request show CS_12 ");
                    requestShowPopup("CS_12");
                    break;
                }

                case srvwrp::ConnectedServiceWrapper::CallState::Impossible: {
                    WLOG_DEBUG(MODEL_NAME << " srvwrp::ConnectedServiceWrapper::CallState::Impossible - Request show CS_13 ");
                    requestShowPopup("CS_13");
                    break;
                }

                case srvwrp::ConnectedServiceWrapper::CallState::None: {
                    WLOG_DEBUG(MODEL_NAME << " srvwrp::ConnectedServiceWrapper::CallState::None -  Request show CS_13 ");
                    requestShowPopup("CS_13");
                    break;
                }
                default: {
                    break;
                }
            }

        } while (flag);
    }
}

void CsApp::CSModel::onConnectedSrvUpdated()
{
    this->collectingData();
}

/*!
 * \brief CSModel::getHighDrivingRestrictionState
 * \return
 */
bool CsApp::CSModel::getHighDrivingRestrictionState()
{
    bool m_isHighDrivingRestriction = false;
    if (m_variantVehicleSvwrp != nullptr) {
        m_isHighDrivingRestriction = m_variantVehicleSvwrp->getHighDrivingRestrictionState();
    }
    return m_isHighDrivingRestriction;
}

/*!
 * \brief CSModel::getTelematicsServiceState
 * \return
 */
bool CsApp::CSModel::getTelematicsServiceState()
{
    bool m_telematicsServiceState = false;
    if (m_connectedSrvWrap != nullptr) {
        auto tetematicsServiceState = m_connectedSrvWrap->getTelematicsServiceState();
        bool serviceValid = tetematicsServiceState.has_value();
        if (serviceValid == true) {
            m_telematicsServiceState = static_cast<bool>(tetematicsServiceState.value() == srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag::On);
        }
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-START
        (void)headerIF.setTelematicsSrvState(m_telematicsServiceState);
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-END
    }
    return m_telematicsServiceState;
}

/*!
 * \brief CSModel::getConnectedServiceSettingState
 * \return
 */
bool CsApp::CSModel::getConnectedServiceSettingState()
{
    bool m_connectedServiceSettingState = false;
    if (m_connectedSrvWrap != nullptr) {
        auto connectedServiceSettingState = m_connectedSrvWrap->getConnectedServiceSettingState();
        bool serviceValid = connectedServiceSettingState.has_value();
        if (serviceValid == true) {
            m_connectedServiceSettingState = static_cast<bool>(connectedServiceSettingState.value() == srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag::On);
        }
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-START
        (void)headerIF.setCntdSrvStgState(m_connectedServiceSettingState);
        //Klocwork-Fix rule MISRA.FUNC.UNUSEDRET-END
    }
    return m_connectedServiceSettingState;
}

/*!
 * \brief CSModel::isInRangeDriving
 * \return
 */
bool CsApp::CSModel::isInRangeDriving(const QString& val) {
    bool valueInRangeDriving = false;
    for (auto itr = m_displayScreen.begin(); itr != m_displayScreen.end(); ++itr) {
        if (itr->first == "CS_07") {
            break;
        }
        if (itr->first == val) {
            valueInRangeDriving = true;
            break;
        }
    }
    return valueInRangeDriving;
}

void CsApp::CSModel::setSuzukiInitCompleted(const bool val) {
    if (m_isCompletedInitSuzuki) {
        WLOG_INFO(MODEL_NAME << " HOME already ready: ");    
        return;
    }
    m_isCompletedInitSuzuki = val;
    WLOG_INFO(MODEL_NAME << " m_isPopupReady: " << m_isPopupReady);
    WLOG_INFO(MODEL_NAME << " m_isCompletedInitSuzuki: " << m_isCompletedInitSuzuki);
    if (m_isPopupReady && m_isCompletedInitSuzuki) {
        if (m_isRunFirstTime) {
            m_isRunFirstTime = false;
            this->startOpening();
            WLOG_INFO(MODEL_NAME << " set m_isRunFirstTime to: " << m_isRunFirstTime);
        }
    }
    else {
        // Waiting for completed the opening -> Doing nothing
    }
}

void CsApp::CSModel::setPopupStateReady(const bool val) {
    if (m_isPopupReady) {
        WLOG_INFO(MODEL_NAME << " Popup already ready " << m_isPopupReady);
        return;
    }
    m_isPopupReady = val;
    WLOG_INFO(MODEL_NAME << " m_isPopupReady: " << m_isPopupReady);
    WLOG_INFO(MODEL_NAME << " m_isCompletedInitSuzuki: " << m_isCompletedInitSuzuki);
    if (m_isPopupReady && m_isCompletedInitSuzuki) {
        if (m_isRunFirstTime) {
            m_isRunFirstTime = false;
            this->startOpening();
            WLOG_INFO(MODEL_NAME << " set m_isRunFirstTime to: " << m_isRunFirstTime);
        }  
    }
    else{
        // Waiting for popup and home is ready
    }
}