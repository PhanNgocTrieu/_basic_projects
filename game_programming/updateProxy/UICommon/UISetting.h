#ifndef UICOMMON_UISETTING_H
#define UICOMMON_UISETTING_H

#include <QObject>
#include <QVariant>
#include <QIODevice>
#include <shared_mutex>
#include <contentproviderwrap/BlobSetting.h>
#include <contentproviderwrap/contentproviderwrapper.h>
#include <common/Logger.h>

namespace uicommon
{
    class UISetting: public QObject
    {
        Q_OBJECT
        WLOG_DEF
    public:

        using ConstructTuple = std::tuple<std::string, std::string, std::function<void()>>;

        class Reader 
        {
        public:
            Reader(Reader&&);
            QVariant read(const QString& key);
            ~Reader();
        private:
            WLOG_DEF;
            Reader(UISetting&);
            Reader(const Reader&) = delete;
            auto operator=(const Reader&) = delete;
            UISetting&  m_setting;
            QVariantMap m_settingMap;
            friend class UISetting;
        };

        class Writter 
        {
        public:
            Writter(Writter&&);
            void write(const QString&, const QVariant& value);
            ~Writter();
        private:
            WLOG_DEF;
            Writter(UISetting&);
            Writter(const Writter&) = delete;
            auto operator=(const Writter&) = delete;
            UISetting& m_setting;
            QVariantMap                 m_settingMap;
            friend class UISetting;
        };

        UISetting(std::tuple<std::string, std::string, std::function<void()>> info);

        virtual ~UISetting();

        inline Reader getReader()
        {
            return Reader(*this);
        }

        inline Writter getWriter()
        {
            return Writter(*this);
        }

        UISetting(const UISetting&) = delete;
        auto operator=(const UISetting&) = delete;

        std::function<void()> onSettingUpdated = {};

    private:
        void onBlobSettingUpdate();
        void copyTo(QVariantMap& out);
        void updateSetting(QVariantMap&& out);

        srvwrp::signalsrv::Connect     m_connectBlobSettingUpdate;
        QVariantMap                 m_settingMap;
        std::shared_mutex           m_mux;
        std::string                 m_defaultIniPath;
        srvwrp::content::BlobSetting m_BlobSetting;

        friend class UISetting::Reader;
        friend class UISetting::Writter;
    };
}
#endif //UICOMMON_UISETTING_H