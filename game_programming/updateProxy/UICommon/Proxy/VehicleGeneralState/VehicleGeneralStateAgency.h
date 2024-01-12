#ifndef VEHICLE_GENERAL_AGENCY_H
#define VEHICLE_GENERAL_AGENCY_H
#include <QObject>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QScreen>
namespace uicommon{
    /**
     * @brief This class is dedicated to be served as template for model
     *        and provider of VehicleGeneralState which controls the driving restriction
     *        condition and so on
     *        The provider will implement this class to provide service and control UI property
     *        at the host (1_setting_app)
     *        The listeners (The applications which are interested in knowing the vehicle general states)
     *        will implement this class as uses as a model to update and query the vehicle state
     */
    class VehicleGeneralStateAgency: public QObject{
        Q_OBJECT
        Q_PROPERTY(bool isDriving READ isDriving NOTIFY isDrivingChanged)
        Q_PROPERTY(int carType READ carType NOTIFY carTypeChanged)
        Q_PROPERTY(qreal DPI READ DPI NOTIFY DPIChanged)
        public:
            enum CarType{
                SUZUKI=0,
                OEM,
            };
            Q_ENUMS(CarType)
            enum Sound{
                Touch = 0,
                LongPush,
                Accept,
                Reject,
                Popup
            };
            Q_ENUMS(Sound)
        public:
            VehicleGeneralStateAgency(QObject* parent = nullptr)
                :QObject{parent}
            {
                qreal dpi = QGuiApplication::primaryScreen()->logicalDotsPerInch();
                setDPI(dpi);
            }
        public slots:
            /**
             * @brief Query the actual driving restriction status
             * 
             */
            virtual bool getIsDrivingRestriction() const = 0;
            /**
             * @brief Get the Driving Restriction in View
             */
            bool isDriving() const {return m_isDriving;}

            int carType() const {return m_carType;}

            virtual void playSound(int) = 0;

            qreal DPI() const {return m_DPI;}
            
        signals:
            /**
             * @brief When the Driving restriction change, it will broadcast this signal
             * 
             */
            void onIsDrivingRestrictionChanged(bool);
            /**
             * @brief When the Car Type changes, it will broadcast this signal
             * 
             */
            void onCarTypeChanged(int);
            /**
             * @brief Update the Driving Restriction property in UI
             * 
             */
            void isDrivingChanged();

            void carTypeChanged();

            void DPIChanged();
        protected:
            /**
             * @brief Modify The Driving Restriction value
             * 
             * @param status 
             */
            virtual void setIsDrivingRestriction(bool status) = 0;
            virtual void setCarType(const int& carType) = 0;
            void setDPI(const qreal& dpi){
                if (dpi == m_DPI) return;
                m_DPI = dpi;
                emit DPIChanged();
            }
        protected:
            /**
             * @brief The Driving Restriction variable
             * 
             */
            bool m_isDriving = false;

            int m_carType = CarType::SUZUKI;

            qreal m_DPI = 1;
    };
};
#endif //VEHICLE_GENERAL_AGENCY_H