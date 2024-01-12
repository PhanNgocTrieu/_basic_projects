#include "BluetoothAdapterAgencyAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

namespace uicommon
{

    BluetoothAdapterAgencyAdaptor::BluetoothAdapterAgencyAdaptor(BluetoothAdapterAgency *parent)
        : QDBusAbstractAdaptor(parent)
    {
        // constructor
        setAutoRelaySignals(true);
    }

    BluetoothAdapterAgencyAdaptor::~BluetoothAdapterAgencyAdaptor()
    {
        // destructor
    }

    int BluetoothAdapterAgencyAdaptor::getPower()
    {
        // handle method call ese.hmi.btadapter.getPower
        return parent()->getPower();
    }

    bool BluetoothAdapterAgencyAdaptor::setPower(int status)
    {
        // handle method call ese.hmi.btadapter.setPower
        return parent()->setPower(status);
    }

}