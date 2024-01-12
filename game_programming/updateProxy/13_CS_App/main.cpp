#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtAppManCommon/logging.h>
#include <QtAppManLauncher/launchermain.h>
#include <QtAppManLauncher/dbusapplicationinterface.h>
#include <QtAppManLauncher/dbusnotification.h>
#include "csengine.h"
#include <servicemanager.h>

int main(int argc, char *argv[])
{
    QtAM::Logging::initialize(argc, argv);
    QtAM::Logging::setApplicationId("13_CS_App");
    QtAM::LauncherMain::initialize();

    QGuiApplication app(argc, argv);
    QtAM::LauncherMain launcher;
    launcher.registerWaylandExtensions();
    launcher.loadConfiguration();
    launcher.setupLogging(false, launcher.loggingRules(), QString(), launcher.useAMConsoleLogger());
    launcher.setupDBusConnections();
    
    if (!srvwrp::ServiceManager::start(srvwrp::ServiceManager::AppIDCS))
    {
        //start service mamager fail
    }

    auto engine = CsApp::CSEngine::getInstance();
    engine->setApplication(&app);

    QtAM::DBusApplicationInterface iface(launcher.p2pDBusName(), launcher.notificationDBusName());
    //Fix klocwork START
    (void)iface.initialize();
    //Fix klocwork END
    QObject::connect(&iface, &QtAM::DBusApplicationInterface::quit, [&iface] () {
        iface.acknowledgeQuit();
    });
    engine->connectSignals();

    return engine->exec();
}
