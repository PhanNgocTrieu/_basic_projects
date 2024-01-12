#include "UILogger.h"
#include <common/Logger.h>

const static srvwrp::logsrv::LogSeverity g_severityMap[] = {
        srvwrp::logsrv::LOG_DBG,
        srvwrp::logsrv::LOG_INF,
        srvwrp::logsrv::LOG_WRN,
        srvwrp::logsrv::LOG_ERR,
        srvwrp::logsrv::LOG_FTL
};

UILogger::UILogger(QQmlEngine* qmlEngine, QJSEngine *jsEngine, QObject *parent):QObject(parent),
                                                                                m_qmlEngine(qmlEngine),
                                                                                m_jsEngine(jsEngine)
{
    m_loggerModuleId = srvwrp::logsrv::LogCore::getInstance().registerModule("QML",srvwrp::logsrv::LogSeverity::LOG_INF);
}


UILogger* UILogger::create(QQmlEngine *qmlEngine, QJSEngine *jsEngine)
{
    static UILogger* singleton = nullptr;
    if (singleton == nullptr) {
        singleton = new UILogger(qmlEngine,jsEngine);

        QJSEngine::setObjectOwnership(singleton,
                                      QJSEngine::CppOwnership);
    }

    return singleton;
}

void UILogger::setSeverity(int severity)
{
    srvwrp::logsrv::LogSeverity _severity;
    if (severity > 4) {
        _severity = g_severityMap[4];
    }
    else {
        _severity = g_severityMap[severity];
    }

    srvwrp::logsrv::LogCore::getInstance().setSeverity(m_loggerModuleId,_severity);
}

void UILogger::logSeverity(int severity, const QString& content)
{
    srvwrp::logsrv::Logger _logger;
    srvwrp::logsrv::LogSeverity _severity;
    if (severity > 4) {
        _severity = g_severityMap[4];
    }
    else {
        _severity = g_severityMap[severity];
    }

    _logger.createRecord(_severity,m_loggerModuleId).getStreamer() << content.toStdString();
}

void UILogger::logDbg(const QString& content)
{
    logSeverity(0,content);
}

void UILogger::logInf(const QString& content)
{
    logSeverity(1,content);
}

void UILogger::logWrn(const QString& content)
{
    logSeverity(2,content);
}

void UILogger::logErr(const QString& content)
{
    logSeverity(3,content);
}

void UILogger::logFtl(const QString& content)
{
    logSeverity(4,content);
}
