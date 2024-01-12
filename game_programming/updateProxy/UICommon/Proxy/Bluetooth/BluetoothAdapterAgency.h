#ifndef BLUETOOTH_ADAPTER_AGENCY_H
#define BLUETOOTH_ADAPTER_AGENCY_H

#include <QObject>

namespace uicommon {
    class BluetoothAdapterAgency: public QObject {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.btadapter")
        public slots:
            virtual int getPower() = 0;
            virtual bool setPower(int status) = 0;
        signals:
            void onPowerChangedSignal(int status);
            void onPairFinishedSignal(bool successFlag);
        protected:
            BluetoothAdapterAgency() {};        
    };
}

#endif
