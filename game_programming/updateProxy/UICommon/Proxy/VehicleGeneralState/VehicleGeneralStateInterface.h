#ifndef VEHICLE_GENERAL_STATE_INTERFACE_H
#define VEHICLE_GENERAL_STATE_INTERFACE_H
#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "VehicleGeneralStateModel.h"
namespace uicommon{
    class VehicleGeneralStateInterface: public QDBusAbstractInterface{
        Q_OBJECT
        private:
            inline const char* interfaceName() const{
                return "ese.hmi.VehicleGeneralState";
            }
            VehicleGeneralStateInterface(const QString& service,
                                         const QString& objectPath,
                                         const QDBusConnection& connection,
                                         QObject* parent = nullptr);
        public:
            ~VehicleGeneralStateInterface();
            static VehicleGeneralStateInterface& getInstance();
        public slots:
            inline QDBusPendingReply<bool> getIsDrivingRestriction(){
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList("getIsDrivingRestriction", argumentList);
            }
            inline QDBusPendingReply<>  playSound(int sound){
                QList<QVariant> argumentList;
                argumentList << sound;
                return asyncCallWithArgumentList("playSound",argumentList);
            }
        signals:
            void onIsDrivingRestrictionChanged(bool);
            void onCarTypeChanged(int);
    };
};
#endif //VEHICLE_GENERAL_STATE_INTERFACE_H