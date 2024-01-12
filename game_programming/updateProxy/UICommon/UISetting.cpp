#include "UISetting.h"
#include <algorithm>
#include <QSettings>
#include <QFileInfo>
#include <QRect>
#include <QPoint>

namespace uicommon
{
    //MARK: reader
    UISetting::Reader::Reader(Reader&& other): 
        m_setting(other.m_setting)
    {
        //m_lock.swap(other.m_lock);
        m_settingMap = std::move(other.m_settingMap);
    }
    UISetting::Reader::~Reader()
    {
        //m_lock.unlock();
    }

    UISetting::Reader::Reader(UISetting& setting):
        m_setting(setting)//,
        //m_lock(setting.m_mux)
    {
        m_setting.copyTo(m_settingMap);
    }

    QVariant UISetting::Reader::read(const QString& key)
    {
	    QVariant ret;
        if(!m_settingMap.contains(key)) {
            ret = QVariant("");
        } else {
        	ret = QVariant(m_settingMap[key]);
		}
		return ret;
    }

    //MARK: writer
    UISetting::Writter::Writter(Writter&& other): 
        m_setting(other.m_setting)
    {
        //m_lock.swap(other.m_lock);
        m_settingMap = std::move(other.m_settingMap);
    }
    UISetting::Writter::Writter(UISetting& setting):
        m_setting(setting)//,
        //m_lock(setting.m_mux)
    {
        m_setting.copyTo(m_settingMap);
    }

    UISetting::Writter::~Writter()
    {
        m_setting.updateSetting(std::move(m_settingMap));
    }

    void UISetting::Writter::write(const QString& key, const QVariant& value)
    {
        m_settingMap[key] = value;
    }

    //MARK: UISetting
    UISetting::UISetting(std::tuple<std::string, std::string, std::function<void()>> info):
        QObject{nullptr},
        onSettingUpdated{std::move(std::get<2>(info))},
        m_defaultIniPath{std::move(std::get<1>(info))},
        m_BlobSetting{std::move(std::get<0>(info))}
    {
        // WLOG_INFO("default setting path:" << m_defaultIniPath << " group:" << m_BlobSetting.name());
        if(!m_defaultIniPath.empty()){
            QString path = QString::fromStdString(m_defaultIniPath);
            if(QFileInfo::exists(path)) 
            {
                QSettings setting(path, QSettings::IniFormat);
                const std::string& name = m_BlobSetting.name();
                // WLOG_INFO("default setting: path:" << m_defaultIniPath << " group:" << m_BlobSetting.name());
                setting.beginGroup(QString::fromStdString(m_BlobSetting.name())); //"settingTile"
                foreach (const QString &key, setting.childKeys())
                {
                    // WLOG_INFO("default setting: key:" << key.toStdString());
                    m_settingMap[key] = setting.value(key);
                }
                setting.endGroup();
            }
        }
        m_connectBlobSettingUpdate = m_BlobSetting.onSettingDataUpdated.connect(
            std::bind(&UISetting::onBlobSettingUpdate, this)
        );
        m_BlobSetting.requestSettingData();
    }
	
    UISetting::~UISetting()
    {

    }
	
    void UISetting::updateSetting(QVariantMap&& newSettingMap)
    {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setByteOrder( QDataStream::LittleEndian );

        m_mux.lock();
        m_settingMap = std::move(newSettingMap);
        for(auto iter = m_settingMap.cbegin(); iter != m_settingMap.cend(); ++iter)
        {
            auto& val = iter.value();
            int type = val.userType();

            switch(type)
            {
            case QMetaType::Int:
                stream << iter.key() << type << val.toInt();
                break;
            case QMetaType::QString:
                stream << iter.key() << type << val.toString();
                break;
            case QMetaType::Bool:
                stream << iter.key() << type << val.toBool();
                break;
            case QMetaType::Double:
                stream << iter.key() << type << val.toDouble();
                break;
            case QMetaType::Float:
                stream << iter.key() << type << val.toFloat();
                break;
            case QMetaType::QRect:
                stream << iter.key() << type << val.toRect();
                break;
            case QMetaType::QPoint:
                stream << iter.key() << type << val.toPoint();
                break;
            case QMetaType::QStringList:
                stream << iter.key() << type << val.toStringList();
                break;
            default:
                break;
            }
        }
        m_mux.unlock();
        m_BlobSetting.commitSettingData({data.begin(), data.end()});
    }
    void UISetting::onBlobSettingUpdate()
    {
        const std::vector<uint8_t>& cdata = m_BlobSetting.data();
        QByteArray qdata((const char*)cdata.data(), cdata.size());
        QDataStream stream(&qdata, QIODevice::ReadOnly);
        stream.setByteOrder( QDataStream::LittleEndian );
        QVariantMap newMap;
        while(true)
        {   
            QString key;
            int userType;
            stream >> key >> userType;

            if(key.isEmpty())
                break;
            
            QVariant value;
            switch(userType)
            {
            case QMetaType::Int:
            {
                int intVal; stream >> intVal; value.setValue(std::move(intVal));
                break;
            }
            case QMetaType::QString:
            {
                QString strVal; stream >> strVal; value.setValue(std::move(strVal));
                break; 
            }
            case QMetaType::Bool:
            {
                bool val; stream >> val; value.setValue(std::move(val));
                break; 
            }
            case QMetaType::Double:
            {
                double val; stream >> val; value.setValue(std::move(val));
                break; 
            }
            case QMetaType::Float:
            {
                float val; stream >> val; value.setValue(std::move(val));
                break; 
            }
            case QMetaType::QRect:
            {
                QRect val; stream >> val; value.setValue(std::move(val));
                break; 
            }
            case QMetaType::QPoint:
            {
                QPoint val; stream >> val; value.setValue(std::move(val));
                break; 
            }
            case QMetaType::QStringList:
            {
                QList<QString> val; stream >> val; value.setValue(std::move(val));
                break;
            }
            default:
            {
                WLOG_WARN("not support:" << userType);
                break;
            }
            }
            newMap[key] = value;
        }
        m_mux.lock();
        std::swap(m_settingMap, newMap);
        m_mux.unlock();
        onSettingUpdated();
    }
    void UISetting::copyTo(QVariantMap& out)
    {
        m_mux.lock_shared();
        out = m_settingMap;
        m_mux.unlock_shared();
    }
}
