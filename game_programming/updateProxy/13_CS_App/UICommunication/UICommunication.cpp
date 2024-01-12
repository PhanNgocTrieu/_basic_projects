#include "UICommunication.h"
//#include "Views.h"
// #include "Common/modelenums.h"
#include <ViewsDefines.h>
#include <PopupViewsEnums.h>
#include <UICommon.h>
#include <ImagePoolProvider.h>
CsApp::UICommunication& CsApp::UICommunication::getInstance(){
    static CsApp::UICommunication _instance;
    return _instance;
}
CsApp::UICommunication::UICommunication(QObject* _parent)
    :QObject{_parent}
{
    // HMIViewer::registerStates(STATE_ALL, ARRAYLEN(STATE_ALL));
//    qmlRegisterType<E>("HMIEVENTS", 1, 0, "EVT");
    //Klocwork-Fix rule MISRA.C_CAST-START
    m_naviProxy = NavigationService::createProxy(reinterpret_cast<QObject *>(this));
    //Klocwork-Fix rule MISRA.C_CAST-END
    m_SysIF = &hmi::service::sysifapps::getInstance();
    mViewer = uicommon::HMIViewer::getInstance();
    mViewer->initialized();
    // mViewer->qmlEngine()->addImportPath(":/qt-project.org/imports");
    // mViewer->qmlEngine()->addImportPath(":/QML_RESOURCES/");
    // mViewer->completed();  // ../../system-ui/Animations
    mViewer->setViewerSize(1280, 720);
    // mViewer->registerContextProperty("imageDirPath",QDir(QString("../../system-ui/")).absolutePath());
    mViewer->registerContextProperty("UICommunication",QVariant::fromValue(this));
    QObject::connect(m_SysIF,&hmi::service::sysifapps::currentApplicationChanged ,this ,&CsApp::UICommunication::currentApplicationChanged);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::signallingDataThroughSys  ,this ,&CsApp::UICommunication::signallingDataThroughSys);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::signalErrorCodeForTest    ,this ,&CsApp::UICommunication::signalErrorCodeForTest);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::signalGetSettingTielType  ,this ,&CsApp::UICommunication::signalGetSettingTielType);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::signalSettingAppIdTile    ,this ,&CsApp::UICommunication::signalSettingAppIdTile);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::signalGetSettingTileAppId ,this ,&CsApp::UICommunication::signalGetSettingTileAppId);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::writeNewSettingInfo       ,this ,&CsApp::UICommunication::writeNewSettingInfo);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::writeNewDefaultBarApps    ,this ,&CsApp::UICommunication::writeNewDefaultBarApps);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::callScreensOfAGivenApp    ,this ,&CsApp::UICommunication::callScreensOfAGivenApp);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::signalChangeScreenSize    ,this ,&CsApp::UICommunication::signalChangeScreenSize);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::backToHome                ,this ,&CsApp::UICommunication::backToHome);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::notifyReplyResultPopup    ,this ,&CsApp::UICommunication::notifyReplyResultPopup);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::signallingDataThroughApp  ,this ,&CsApp::UICommunication::signallingDataThroughApp);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::propagatePosition         ,this ,&CsApp::UICommunication::propagatePosition);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::keyEvent                  ,this ,&CsApp::UICommunication::keyEvent);
    QObject::connect(m_SysIF,&hmi::service::sysifapps::collectAllDataFromApp,this,&CsApp::UICommunication::updateAppData);
    QObject::connect(m_SysIF,SIGNAL(transitionStateTrigger(uicommon::SysUI::TransitionType, const QString&, const QString&)),
                     this, SIGNAL(transitionStateTrigger(uicommon::SysUI::TransitionType, const QString&, const QString&)));
}
void CsApp::UICommunication::initializedView(){
    
}
CsApp::UICommunication::~UICommunication(){
    //Klocwork-Fix rule MISRA.STMT.COND.NOT_BOOLEAN-START
    if (mViewer!=nullptr) {
        delete mViewer;
        mViewer = nullptr;
    }
    //Klocwork-Fix rule MISRA.STMT.COND.NOT_BOOLEAN-END

}

void CsApp::UICommunication::registerAllComponents(){
    mViewer->initAllComponents();
}

void CsApp::UICommunication::changeDisplayOnOff()
{
    m_SysIF->changeDisplayOnOff();
}

void CsApp::UICommunication::manualDriverRecord()
{
    m_SysIF->manualDriverRecord();
}

void CsApp::UICommunication::manualDriverPicture()
{
    m_SysIF->manualDriverPicture();
}

void CsApp::UICommunication::changeScreen(uint32_t eventID, QVariant _msg){
    QString _oldScreenPath  = mViewer->getCurrentScreenPath();
    
    mViewer->sendEvent(eventID, _msg);

    QString _newScreenPath  = mViewer->getCurrentScreenPath();    

    if(_oldScreenPath != _newScreenPath) 
    {
        emit onCurrentSettingScreenChanged(_oldScreenPath, false);
        emit onCurrentSettingScreenChanged(_newScreenPath, true);
        if(_newScreenPath == SCREEN_SETTING_MAIN){
            m_SysIF->enableMultitouchSettingScreen(true);
        }
        if (_oldScreenPath == SCREEN_SETTING_MAIN){
            m_SysIF->enableMultitouchSettingScreen(false);
        }
    }


}
void CsApp::UICommunication::sendEvent(uint32_t eventID, QVariant _msg) const{
    //Klocwork-Fix rule MISRA.FUNC.UNUSEDPAR, MISRA.STMT.COND.NOT_BOOLEAN-START
    (void)(_msg);
    if (onSendEvent != nullptr){
        onSendEvent(eventID);
    }
    //Klocwork-Fix rule MISRA.FUNC.UNUSEDPAR, MISRA.STMT.COND.NOT_BOOLEAN-END
}
void CsApp::UICommunication::registerProcessScreen(std::function<void(uint32_t)> processor){
    //Klocwork-Fix rule MISRA.STMT.COND.NOT_BOOLEAN-START
    if (processor != nullptr){
        onSendEvent = processor;
    }
    //Klocwork-Fix rule MISRA.STMT.COND.NOT_BOOLEAN-END
}

void CsApp::UICommunication::registerContextProperty(QString pro, QVariant val){
    mViewer->registerContextProperty(pro,val);
}

void CsApp::UICommunication::showApp(){
    mViewer->show();
}

void CsApp::UICommunication::requestFullScreen(const bool &isFullSize){
    mViewer->updateContextProperty("IS_FULLSIZE_APPLICATION",isFullSize);
    m_SysIF->callToShowInternalPopup("13_CS_App", isFullSize);
}

void CsApp::UICommunication::retranslate(){
    if (mViewer != nullptr){
	    mViewer->qmlEngine()->retranslate();
	}
}

void CsApp::UICommunication::callASpecificScreen(const QString &appID, const int &screenNums)
{
    m_SysIF->receiveAppToCallOut(appID, screenNums);
}

void CsApp::UICommunication::requestShowSurface(const QString &app, const int &width, const int &height, const int &_x, const int &_y)
{
    m_SysIF->resizeWindowItem(app, width, height);
    m_SysIF->rePositionWindowItem(app, _x, _y);
    m_SysIF->callOutToExpand(app);
}

void CsApp::UICommunication::requestHideSurface(const QString &app)
{
    m_SysIF->callOutToExpand(app);
}


void CsApp::UICommunication::setCurrentScreenPath(const QString& path){
    m_SysIF->setCurrentScreenPath(path);
}


void CsApp::UICommunication::callOutToExpand(const QString& application, const QString& screenId, uicommon::SysUI::TransitionType transitionType){
    m_SysIF->callOutToExpand(application, screenId, transitionType);
}

void CsApp::UICommunication::callToShowInternalPopup(const bool& expand){
    m_SysIF->callToShowInternalPopup("FACTORY_App", expand);
}

void CsApp::UICommunication::enableMultitouchSettingScreen(const bool &isEnable){
    m_SysIF->enableMultitouchSettingScreen(isEnable);
}

void CsApp::UICommunication::disableOperationWhileDriving()
{
    m_SysIF->receiveAppToCallOut("System_Popup", POPUPENUM::E::EVT_TO_POPUP_DRIVING_RESTRICTION);
}


void CsApp::UICommunication::sendDataThroughSys(const QString& pro, const QDBusVariant& val){
    m_SysIF->sendDataThroughSys(pro, val);
}

void CsApp::UICommunication::setDefaultLayout(const QVariantList &newDefaultLayout){
    m_SysIF->setDefaultLayout(newDefaultLayout);
}

void CsApp::UICommunication::setappIdTiel(const QString &newAppIdTiel){
    m_SysIF->setappIdTiel(newAppIdTiel);
}

void CsApp::UICommunication::setDefaultApps(const QVariantList &newDefaultApps){
    m_SysIF->setDefaultApps(newDefaultApps);
}

void CsApp::UICommunication::setDefaultBarApps(const QVariantList &newDefaultBarApps){
    m_SysIF->setDefaultBarApps(newDefaultBarApps);
}


void CsApp::UICommunication::setlayoutType(int newLayoutType){
    m_SysIF->setlayoutType(newLayoutType);
}

void CsApp::UICommunication::backToHomeScreen(){
    m_SysIF->backToHomeScreen();
}

void CsApp::UICommunication::receiveAppToCallOut(const QString &appID, const int &screenID){
    m_SysIF->receiveAppToCallOut(appID,screenID);
}

void CsApp::UICommunication::getFavoriteFromApps(const QString& appId,const int& eventId){
    m_SysIF->getFavoriteFromApps(appId,eventId);
}

void CsApp::UICommunication::resizeWindowItem(const QString& SURFACE_ID, const int& width, const int& height){
    m_SysIF->resizeWindowItem(SURFACE_ID,width,height);
}
void CsApp::UICommunication::rePositionWindowItem(const QString& SURFACE_ID, const int& _x, const int& _y){
    m_SysIF->rePositionWindowItem(SURFACE_ID,_x,_y);
}


void CsApp::UICommunication::backToPreviousScreen(){
    m_SysIF->backToPreviousScreen();
}

void CsApp::UICommunication::setViewerSize(int width, int height){
    mViewer->setViewerSize(width,height);
}

bool CsApp::UICommunication::checkCurrentScreen(const QString& screenpath){
    return mViewer->checkCurrentScreen(screenpath);
}

void CsApp::UICommunication::notifySettingChanged(const QString& _str) {
    m_SysIF->notifySettingChanged(_str);
}

void CsApp::UICommunication::requestToHome()
{
    m_SysIF->requestToHome();
}
