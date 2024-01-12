#ifndef HMI_SYSTEM_MODEL_H
#define HMI_SYSTEM_MODEL_H
#include <QObject>
#include "HMISystemServiceProxy.h"
#include <QQmlEngine>
class HMISystemModel: public QObject{
    Q_OBJECT
    Q_ENUMS(INTERACTION_EVENTS)
    Q_ENUMS(HMIInteractiveStatus)
    Q_ENUMS(HMILayoutDisplay)
    Q_PROPERTY(QString screenState READ screenState NOTIFY onScreenStateChanged)
    Q_PROPERTY(quint8 layoutDisplay READ layoutDisplay NOTIFY layoutDisplayChanged)
    Q_PROPERTY(bool isPrintOverFlowTextLog READ isPrintOverFlowTextLog WRITE setIsPrintOverFlowTextLog NOTIFY isPrintOverFlowTextLogChanged)
    Q_PROPERTY(QString currentLanguage READ currentLanguage WRITE setCurrentLanguage NOTIFY currentLanguageChanged)

    public:
        enum INTERACTION_EVENTS: quint32{
            NORMAL=0,
            PRESSED,
            ACTIVE,
            HOVER,
            NONE
        };
        enum HMILayoutDisplay: quint8{
            LEFT_DISPLAY = 0,
            RIGHT_DISPLAY
        };
    private:
        HMISystemModel(QObject* parent = nullptr);
    public: 
        static HMISystemModel& getInstance();
        static HMISystemModel* create(QQmlEngine* engine, QJSEngine* jsEngine);
        QString screenState() const {return m_screenState;}
        static std::map<QString, uicommon::HMIApplication> g_appEnums;  
        quint8 layoutDisplay() const {return m_layoutDisplay;}
        void requestModifyLayoutDisplay(const HMISystemModel::HMILayoutDisplay&);
        bool isPrintOverFlowTextLog() const;

        void setIsPrintOverFlowTextLog(bool newIsPrintOverFlowTextLog);

        QString currentLanguage() const;
        void setCurrentLanguage(const QString &newCurrentLanguage);

    private:
        void setScreenState(const QString& newScreenState);
        void handleOnPressOnApplicationChanged(uicommon::HMIApplication, uicommon::HMIUserInteractiveStatus);
        void setLayoutDisplay(const quint8& layout);
    signals:
        void onScreenStateChanged();
        void layoutDisplayChanged();
        void isPrintOverFlowTextLogChanged();

        void currentLanguageChanged();

    private:
        QString m_app = "UNDEFINED";
        uicommon::HMISystemServiceProxy&  m_hmiSysIf;
        QString m_screenState = "Normal";
        quint8 m_layoutDisplay = HMILayoutDisplay::LEFT_DISPLAY;
        bool m_isPrintOverFlowTextLog;

        QList<QString> m_languageList;
        QString m_currentLanguage{"ja"};
};
#endif //HMI_SYSTEM_MODEL_H
