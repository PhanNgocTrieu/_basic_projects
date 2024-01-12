#include "HMISystemServiceAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

namespace uicommon {
    /*
     * Implementation of adaptor class SysAdaptor
     */

    HMISystemService::~HMISystemService()
    {
    }

    HMISystemServiceAdaptor::HMISystemServiceAdaptor(uicommon::HMISystemService *parent)
        : QDBusAbstractAdaptor(parent)
    {
        // constructor
        setAutoRelaySignals(true);
    }

    HMISystemServiceAdaptor::~HMISystemServiceAdaptor()
    {
        // destructor
    }

    int HMISystemServiceAdaptor::probeTransitionRule(const QString& appId, const QString& screenId)
    {
        return parent()->probeTransitionRule(appId, screenId);
    }

    void HMISystemServiceAdaptor::changeLanguage(uint id)
    {
        // handle method call ese.hmi.sys.changeLanguage
        parent()->changeLanguage(id);
    }

    void HMISystemServiceAdaptor::showDiagScreen(QString appId)
    {
        // handle method call ese.hmi.sys.showDiagScreen
        parent()->showDiagScreen(appId);
    }

    void HMISystemServiceAdaptor::changeGlobalSetting(const QString &name, const QDBusVariant &value)
    {
        parent()->changeGlobalSetting(name, value);
    }
    void HMISystemServiceAdaptor::screenCaptureMode(const QString &name, const QDBusVariant &value)
    {
        parent()->screenCaptureMode(name, value);
    }

    void HMISystemServiceAdaptor::requestSetPrintOverFlowTextLog(const bool &isPrint)
    {
        parent()->requestSetPrintOverFlowTextLog(isPrint);
    }

    void HMISystemServiceAdaptor::enableCamera(bool enable){
        parent()->enableCamera(enable);
    }


    void HMISystemServiceAdaptor::isHandlePosition(bool status) {
        parent()->isHandlePosition(status);
    }

    bool HMISystemServiceAdaptor::popupEmerged(){
        return parent()->popupEmerged();
    }
    QString HMISystemServiceAdaptor::getPopupPathOfAApllication(const QString& app){
        return parent()->getPopupPathOfAApllication(app);
    }

    void HMISystemServiceAdaptor::setPopupStateOfApplication(const QString& app, const QString& popupPath){
        parent()->setPopupStateOfApplication(app, popupPath);
    }

    void HMISystemServiceAdaptor::setLayoutDisplay(LayoutDisplay layout){
        parent()->setLayoutDisplay(layout);
    }

    LayoutDisplay HMISystemServiceAdaptor::getLayoutDisplay(){
        return parent()->getLayoutDisplay();
    }

    void HMISystemServiceAdaptor::showCMN04(uint id)
    {
        parent()->showCMN04(id);
    }

    bool HMISystemServiceAdaptor::requestCPNaviMeter(bool requestType)
    {
        return parent()->requestCPNaviMeter(requestType);
    }

    bool HMISystemServiceAdaptor::requestAANaviMeter(bool requestType)
    {
        return parent()->requestAANaviMeter(requestType);
    }

    void HMISystemServiceAdaptor::requestStreamerFullScreen(bool isFullScreen)
    {
        parent()->requestStreamerFullScreen(isFullScreen);
    }
    
    void HMISystemServiceAdaptor::requestFullScreenDone()
    {
        parent()->requestFullScreenDone();
    }
}
