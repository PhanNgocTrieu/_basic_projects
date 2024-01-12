#include "HMISystemModel.h"
HMISystemModel& HMISystemModel::getInstance(){
    static HMISystemModel instance;
    return instance;
}
HMISystemModel* HMISystemModel::create(QQmlEngine* engine, QJSEngine* jsEngine){
    HMISystemModel& instance = HMISystemModel::getInstance();
    QJSEngine::setObjectOwnership(&instance,QJSEngine::CppOwnership);
    return &instance;
}
std::map<QString, uicommon::HMIApplication>  HMISystemModel::g_appEnums = {
    {"1_SETTING_App"     ,   uicommon::HMIApplication::SETTING_APP},
    {"2_AC_App"          ,   uicommon::HMIApplication::AC_APP},
    {"3_EV_App"          ,   uicommon::HMIApplication::EV_APP},
    {"4_PHONE_App"       ,   uicommon::HMIApplication::PHONE_APP},
    {"5_CARPLAY_App"     ,   uicommon::HMIApplication::CARPLAY_APP},
    {"7_NAVI_App"        ,   uicommon::HMIApplication::NAVI_APP},
    {"8_MEDIA_App"       ,   uicommon::HMIApplication::MEDIA_APP},
    {"9_PICTURE_App"     ,   uicommon::HMIApplication::PICTURE_APP},
    {"ALL_APPS"          ,   uicommon::HMIApplication::ALL_APPS}
};
HMISystemModel::HMISystemModel(QObject* parent)
    :QObject{parent}
     ,m_hmiSysIf{uicommon::HMISystemServiceProxy::getInstance()}
{
    m_app = QCoreApplication::instance()->applicationName();
    QObject::connect(&uicommon::HMISystemServiceProxy::getInstance(), &uicommon::HMISystemServiceProxy::onPressOnApplicationChanged, this, &HMISystemModel::handleOnPressOnApplicationChanged);

    QObject::connect(&uicommon::HMISystemServiceProxy::getInstance(), &uicommon::HMISystemServiceProxy::onRequestSetPrintOverFlowTextLog
                     , this, [this](const bool &isPrint){setIsPrintOverFlowTextLog(isPrint);});

    QObject::connect(&uicommon::HMISystemServiceProxy::getInstance(), &uicommon::HMISystemServiceProxy::onChangeLanguage
                     , this, [this](const int &newLanguage){
        setCurrentLanguage(m_languageList[newLanguage]);
    });

    m_languageList = {
        "ja",
        "en-US",
        "en-GB",
        "en-IN",
        "hi",
        "en-AU",
        "de",
        "nl",
        "fr",
        "it",
        "es",
        "es-MX",
        "pt",
        "hu",
        "pl",
        "da",
        "cs",
        "nb",
        "sv",
        "tr",
        "el",
        "ru",
        "th",
        "id",
        "ar",
        "sk",
        "ro",
        "zh",
        "uk",
        "nl-BE",
        "he",
        "hr",
        "sl",
        "fi"
    };
}

void HMISystemModel::handleOnPressOnApplicationChanged(uicommon::HMIApplication app, uicommon::HMIUserInteractiveStatus userStatus){
    typename std::map<QString, uicommon::HMIApplication>::iterator it = g_appEnums.begin();
    while (it != g_appEnums.end()){
        if ((*it).second == app){
            bool isReceivedApp = true;
            QString receivedApp = (*it).first;
            if ((receivedApp != m_app) && (receivedApp != "ALL_APPS")){
                isReceivedApp = false;
            }
            if (isReceivedApp){
                bool isValid = true;
                QString screenState = m_screenState;
                switch(userStatus){
                    case uicommon::HMIUserInteractiveStatus::NORMAL:{
                        screenState = "Normal";
                        break;
                    }
                    case uicommon::HMIUserInteractiveStatus::PRESSED:{
                        screenState = "Pressed";
                        break;
                    }
                    case uicommon::HMIUserInteractiveStatus::ACTIVE:{
                        screenState = "Active";
                        break;
                    }
                    case uicommon::HMIUserInteractiveStatus::HOVER:{
                        screenState = "Hover";
                        break;
                    }
                    default:{
                        isValid = false;
                        break;
                    }
                }
                if (isValid){
                    setScreenState(screenState);
                }
                break;
            }
        }
        ++it;
    }



}
void HMISystemModel::setScreenState(const QString& newScreenState){
    if (m_screenState != newScreenState){
        m_screenState = newScreenState;
        emit onScreenStateChanged();
    }
}

void HMISystemModel::setLayoutDisplay(const quint8& layout){
    //Fix klocwork START
    if (layout != m_layoutDisplay){
        m_layoutDisplay = layout;
        emit layoutDisplayChanged();
    }
    //Fix klocwork END
}


void HMISystemModel::requestModifyLayoutDisplay(const HMISystemModel::HMILayoutDisplay& layoutDisplay)
{
    //Fix klocwork START
    qDebug()<<"HMISystemModel::requestModifyLayoutDisplay layoutDisplay: " << layoutDisplay << ", m_layoutDisplay: " << m_layoutDisplay;
    if (static_cast<quint8>(layoutDisplay) != m_layoutDisplay){
        uicommon::LayoutDisplay layoutType;
        switch(layoutDisplay){
        case HMISystemModel::HMILayoutDisplay::LEFT_DISPLAY:
            layoutType = uicommon::LayoutDisplay::LEFT_DISPLAY;
            break;
        case HMISystemModel::HMILayoutDisplay::RIGHT_DISPLAY:
            layoutType = uicommon::LayoutDisplay::RIGHT_DISPLAY;
            break;
        default:
            layoutType = uicommon::LayoutDisplay::INVALID_LAYOUT_DISPLAY;
            break;
        }
        if (layoutType != uicommon::LayoutDisplay::INVALID_LAYOUT_DISPLAY) {
            m_hmiSysIf.setLayoutDisplay(layoutType);
        }
    }
    //Fix klocwork END
}
bool HMISystemModel::isPrintOverFlowTextLog() const
{
    return m_isPrintOverFlowTextLog;
}

void HMISystemModel::setIsPrintOverFlowTextLog(bool newIsPrintOverFlowTextLog)
{
    if (m_isPrintOverFlowTextLog != newIsPrintOverFlowTextLog) {
	    m_isPrintOverFlowTextLog = newIsPrintOverFlowTextLog;
	    emit isPrintOverFlowTextLogChanged();
	}
}

QString HMISystemModel::currentLanguage() const
{
    return m_currentLanguage;
}

void HMISystemModel::setCurrentLanguage(const QString &newCurrentLanguage)
{
    if (m_currentLanguage != newCurrentLanguage) {
	    m_currentLanguage = newCurrentLanguage;
	    emit currentLanguageChanged();
	}
}
