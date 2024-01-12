#ifndef SERVICEBUS_AGENCY_INTERFACE_H
#define SERVICEBUS_AGENCY_INTERFACE_H
#include "../../UICommon_global.h"
#include <QObject>
#include <QByteArray>
#include <common/ServiceBus.h>
#include <common/Logger.h>

namespace uicommon
{
    class UICOMMON_EXPORT ServiceBusAgency : public QObject
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.servicebus")
    public:
        virtual ~ServiceBusAgency(); 
    public Q_SLOTS:
        virtual void sendData(const QByteArray& data) = 0;
    Q_SIGNALS:
        void dataOnBus(const QByteArray&);
    };
}

#endif