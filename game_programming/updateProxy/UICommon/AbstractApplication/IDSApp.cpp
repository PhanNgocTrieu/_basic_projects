#include "IDSApp.h"
namespace uicommon
{
    IDSApp::IDSApp(QObject* parent,bool IsInitResourceLater)
        :QObject{parent}
        ,mAppName{QCoreApplication::applicationName()}
        ,mIsInitResourceLater{IsInitResourceLater}
    {
    }

    void IDSApp::initialize()
    {
        m_SysIF = &hmi::service::sysifapps::getInstance();
        mViewer = HMIViewer::getInstance();
        if (!mIsInitResourceLater)
        {
            mViewer->initialized();
            mViewer->qmlEngine()->addImportPath(":/qt-project.org/imports");
            mViewer->completed();
        }
        QObject::connect(m_SysIF, &hmi::service::sysifapps::onRequestShowApp, this,[this](QString app)
        {
            if (app == mAppName)
            {
                qWarning()<<"Request Show " << app;
                HMIViewer::getInstance()->show();
                QPlatformSurfaceEvent* event = new QPlatformSurfaceEvent(QPlatformSurfaceEvent::SurfaceEventType::SurfaceCreated);
                QCoreApplication::postEvent(HMIViewer::getInstance()->getViewer(), event, Qt::HighEventPriority);
            }
        },Qt::UniqueConnection);
        QObject::connect(m_SysIF, &hmi::service::sysifapps::onRequestHideApp, this,[this](QString app)
        {
            if (app == mAppName)
            {
                qWarning()<<"Request Hide " << app;
                QPlatformSurfaceEvent* event = new QPlatformSurfaceEvent(QPlatformSurfaceEvent::SurfaceEventType::SurfaceAboutToBeDestroyed);
                QCoreApplication::postEvent(HMIViewer::getInstance()->getViewer(), event, Qt::HighEventPriority);
                QMetaObject::invokeMethod(HMIViewer::getInstance(),"hide", Qt::QueuedConnection);
            }
        },Qt::UniqueConnection);
    }

    void IDSApp::completeView()
    {
        mViewer->completed();
    }
};