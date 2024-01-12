#ifndef IDSAPP_H
#define IDSAPP_H
#include <QObject>
#ifndef CUSTOM_APP
#include <HMIViewer.h>
#endif
#include "../SysUI/SysUIInterface.h"
namespace uicommon
{
    class IDSApp: public QObject 
    {
        Q_OBJECT
        public:
            IDSApp(QObject* parent = nullptr, bool IsInitResourceLater = false);

        protected:
            void initialize();

            void completeView();

        protected:

            HMIViewer*                      mViewer;

            hmi::service::sysifapps*        m_SysIF;

            const QString                   mAppName;

            bool                            mIsInitResourceLater = false;
    };
};

#endif //IDSAPP_H