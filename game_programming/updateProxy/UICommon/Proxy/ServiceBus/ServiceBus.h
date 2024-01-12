#ifndef SERVICEBUS_H
#define SERVICEBUS_H
#include "../../UICommon_global.h"
#include <QObject>
#include <QByteArray>
#include <common/ServiceBus.h>
#include <common/Logger.h>
#include "ServiceBusAgencyProxy.h"

namespace uicommon
{
    class UICOMMON_EXPORT ServiceBus : public QObject,
        virtual public srvwrp::ServiceBus
    {
        Q_OBJECT
        WLOG_DEF
        uicommon::ServiceBusAgencyProxy&            m_BusInterface;
        ServiceBus();
    public:
        virtual ~ServiceBus();
        static ServiceBus& getInstance();
        //implement ServiceBus
        void send(const std::vector<uint8_t>&) override;
    };
}

#endif