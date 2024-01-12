#ifndef NAVIBOXINFOADAPTOR_H
#define NAVIBOXINFOADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "naviboxinfoservice.h"
#include <QtCore/qcontainerfwd.h>

class NaviboxInfoAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ese.hmi.nbif")
    Q_CLASSINFO("D-Bus Introspection", ""
"   <interface name=\"ese.hmi.nbif\">\n"
"       <signal name=\"onNaviboxInfoChanged\">\n"
"           <arg direction=\"out\" type=\"(i)\" name=\"type\"/>\n"
"           <arg direction=\"out\" type=\"v\" name=\"var\"/>\n"
"           <annotation value=\"NaviboxInfoType\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
"       </signal>\n"
"   </interface>\n")

public:
    NaviboxInfoAdaptor(QObject *parent);
    virtual ~NaviboxInfoAdaptor();

private:
    inline NaviboxInfoService *parent() const { return static_cast<NaviboxInfoService *>(QObject::parent()); }

Q_SIGNALS: // SIGNALS
    void onNaviboxInfoChanged(const NaviboxInfoType& type, const QDBusVariant& var);
};

#endif
