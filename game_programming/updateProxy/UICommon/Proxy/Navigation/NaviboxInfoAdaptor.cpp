#include "NaviboxInfoAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

NaviboxInfoAdaptor::NaviboxInfoAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

NaviboxInfoAdaptor::~NaviboxInfoAdaptor()
{
    // destructor
}
