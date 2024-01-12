#ifndef CSENGINE_H
#define CSENGINE_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <SysUI/SysUIInterface.h>
#include <QTimer>
#include <HMIViewer.h>
#include <QDBusConnection>
#include <QDBusVariant>
#include "PopupViewsEnums.h"
#include "Common/cscommon.h"
// #include "Models/CSModel.h"
#include "Models/ConnectedProvider.h"
#include <PopupViewsEnums.h>
//Klocwork-Fix rule MISRA.NS.GLOBAL-START
namespace CsApp{
class CSEngine : public QObject
{
    Q_OBJECT
public:
    //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
    explicit CSEngine(QObject *_parent = nullptr);
    //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
    ~CSEngine();
    static CSEngine *getInstance();
    //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-START
    static void registerContextProperty();
    //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-END
    int exec();
    void connectSignals();
    void setApplication(QGuiApplication* app);
    void receiveErrorCodeFromAppTest(QString appID, QString errorCode);
    void receiveDataFromSys(const QString& pro, const QDBusVariant& var);
    //Klocwork-Fix rule CL.FFM.COPY, CL.FFM.ASSIGN-START
    CSEngine(const CSEngine&) = delete;
    CSEngine& operator=(const CSEngine&) = delete;
    //Klocwork-Fix rule CL.FFM.COPY, CL.FFM.ASSIGN-END

private:
    //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-START
    static void registerGlobalContextEvent() {}
    //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-END

signals:
     void sendDataThroughSystem(const QString& pro, const QDBusVariant& var);
    
private:
    WLOG_DEF;
    uicommon::HMIViewer* mViewer     = nullptr;
    // CsApp::CSModel* m_csModel               = nullptr;
    CsApp::ConnectedServiceProvider* m_csProvider = nullptr;
    QGuiApplication *m_App           = nullptr;
    hmi::service::sysifapps *m_SysIF = nullptr;
};
}
//Klocwork-Fix rule MISRA.NS.GLOBAL-END
#endif // CSENGINE_H
