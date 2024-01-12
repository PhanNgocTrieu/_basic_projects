#ifndef VEHICLE_GENERAL_STATE_H
#define VEHICLE_GENERAL_STATE_H
#include <QObject>
#include <QQmlEngine>
#include "VehicleGeneralStateAgency.h"
namespace uicommon{
    class VehicleGeneralStateModel: public VehicleGeneralStateAgency{
        Q_OBJECT
        private:
            VehicleGeneralStateModel();            
        public:
            static VehicleGeneralStateModel& getInstance();
            static VehicleGeneralStateModel* create(QQmlEngine *qmlEngine, QJSEngine *jsEngine);
        public slots:
            bool getIsDrivingRestriction() const override;
            void playSound(int);  
            void popupStatus(const QString& popupStatus);
        private:
            void setIsDrivingRestriction(bool status)  override;
            void setCarType(const int& carType) override final;
            static QString application;
    };
};
#endif //VEHICLE_GENERAL_STATE_H