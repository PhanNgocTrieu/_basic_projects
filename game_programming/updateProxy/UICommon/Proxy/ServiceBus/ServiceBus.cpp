#include "ServiceBus.h"
#include "ServiceBusAgencyProxy.h"

#undef WLOG_DEBUG
#define WLOG_DEBUG  WLOG_INFO

using namespace uicommon;
ServiceBus::ServiceBus():
    m_BusInterface(ServiceBusAgencyProxy::getInstance())
{
    QObject::connect(&m_BusInterface,
        &uicommon::ServiceBusAgencyProxy::dataOnBus, this,
        [this](const QByteArray& data){
            //char buff[10240];
            //char* p = &buff[0];
            //*p='\0';
            uint8_t *ptr = (uint8_t*)data.data();
            std::vector<uint8_t> rev;
            for(size_t i = 0; i< data.size(); i++)
            {
                //p += sprintf(p, "%d ", (int)(*ptr));
                rev.push_back( *ptr  );
                ptr++;
            }
            //WLOG_DEBUG("ServiceBus receive:" << std::string(buff));
            this->onReceived(rev);
        }
    );
}
ServiceBus::~ServiceBus()
{

}

ServiceBus& ServiceBus::getInstance()
{
    static ServiceBus ins;
    return ins;
}
//implement ServiceBus
void ServiceBus::send(const std::vector<uint8_t>& data) 
{
    //WLOG_DEBUG("ServiceBus bus sent:" << data.size());
    //char buff[10240];
    //char* p = &buff[0];
    //*p='\0';

    QByteArray arr;
    char* ptr = (char*) data.data();
    for(size_t i = 0; i< data.size(); i++)
    {
        //p += sprintf(p, "%d ", (int)(data[i]));
        arr.push_back(*ptr);
        ptr++;
    }
    //WLOG_DEBUG("ServiceBus send:" << std::string(buff));
    m_BusInterface.sendData(arr);
}