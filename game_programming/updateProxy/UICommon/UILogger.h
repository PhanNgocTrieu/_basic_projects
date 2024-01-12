#ifndef UI_LOGGER_H
#define UI_LOGGER_H

#include <QObject>
#include <QQmlEngine>
#include <QDBusVariant>
#include <UICommon.h>

class UILogger: public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public Q_SLOTS:
    static UILogger* create(QQmlEngine *qmlEngine, QJSEngine *jsEngine);

    void logSeverity(int severity, const QString& content);
    void logDbg(const QString& content);
    void logInf(const QString& content);
    void logWrn(const QString& content);
    void logErr(const QString& content);
    void logFtl(const QString& content);
    void setSeverity(int severity);
protected:
    explicit UILogger(QQmlEngine* qmlEngine, QJSEngine *jsEngine, QObject *parent = nullptr);

    QQmlEngine* m_qmlEngine;
    QJSEngine* m_jsEngine;
    uint32_t m_loggerModuleId;
signals:

};

#endif
