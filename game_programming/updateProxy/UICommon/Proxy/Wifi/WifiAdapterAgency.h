#ifndef WIFI_ADAPTER_AGENCY_H
#define WIFI_ADAPTER_AGENCY_H

#include <QObject>

namespace uicommon {
    class WifiAdapterAgency: public QObject {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.wifiadapter")
        public slots:
            virtual int getPower() = 0;
            virtual bool setPower(int status) = 0;
            virtual QString getSSID() = 0;
        signals:
            void onPowerChangedSignal(int status);
        protected:
            WifiAdapterAgency() {};        
    };
}

#endif