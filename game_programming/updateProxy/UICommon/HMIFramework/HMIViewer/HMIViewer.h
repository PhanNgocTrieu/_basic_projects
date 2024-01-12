#ifndef HMIVIEWER_H
#define HMIVIEWER_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>

#include "HMIFramework.h"
#include <QQuickWindow>

namespace uicommon {
class HMIViewer : public QObject
{
    Q_OBJECT
        explicit HMIViewer(uint32_t scr);
    public:
        virtual ~HMIViewer();
        void initialized();
        void completed();
        bool registerContextProperty(const QString &str, const QVariant &var);
        QList<QString> contextPropertiesRegisted() const;
        bool updateContextProperty(const QString &str, const QVariant &var);
        Q_INVOKABLE void sendEvent(uint32_t eventID, QVariant msg = QVariant());
        bool setViewerSize(int width, int height);
        QQmlEngine *qmlEngine();
        QQmlContext *getQmlContext();
        QQuickWindow *getViewer();
        QList<uint32_t> getCurrentStates() const;
        static void registerStates(const STATE_SYSTEM tbl[], uint len);
        static HMIViewer* getInstance();
        Q_INVOKABLE  QString getCurrentScreenPath()  {return mCurrentScreenPath;}
        Q_INVOKABLE  bool checkCurrentScreen(const QString& screenpath)  {return mCurrentScreenPath==screenpath;}
        const uint32_t& getCurrentEvent() const {return mCurrentEvent;}
        void initAllComponents();
        
        QQuickItem* getContentItem() const;
    public slots:
        void show();
        
        void hide();

        void destroyWindowResource();

        void closeSession();
    private:
        // It's static so it can be shared with all instances.
        // Since both views are sharing the QQmlEngine we can simply reuse the QQmlComponents.
        // The Loader will set the correct QQmlContext on them, so they see the properties for the view
        // they are in.
        static QQmlEngine                                   *mQmlEngine;
        static bool                                         mRegister;
        static QHash<uint32_t, HMIViewer*>                  mViewRegisted;
        static QHash<uint32_t, const APPLICATION_STATE*>       mStateRegisted;
        static QHash<uint32_t, QHash<uint32_t, STATE_TRIGGER> >   mPoolEvt;
        QQuickWindow                                    *mViewer;
        QQmlContext                                         *mContext;
        uint32_t                                               mScreen;
        uicommon::ScreenManager                             *mScreenMng;
        QList<QString>                                      mContextProperties;
        uint32_t                                               mRootState;
        //Fix klocwork START
        QString                                             mCurrentScreenPath = "";
        //Fix klocwork END
        uint32_t                                               mCurrentEvent{0};
    private:
        void handleTransition(const APPLICATION_STATE *from, const APPLICATION_STATE *to, QVariant msg = QVariant());

        bool showScreen(uint32_t tempId, QVariant msg = QVariant());

        void collectGarbage();

    signals:
        void visibleChanged(bool state);

        void eventReceiver(int tempEvent, int data);

        void windowIsReadyToShow();

        void windowIsReadyToHide();

};
}
#endif // HMIVIEWER_H
