#ifndef LANGUAGEMANAGEMENT_H
#define LANGUAGEMANAGEMENT_H

#include <QObject>
#include <QTranslator>

#include "UICommon_global.h"

namespace uicommon {
    class UICOMMON_EXPORT LanguageManagement : public QObject
    {
        Q_OBJECT
    public:
        /**
         * @brief LanguageManagement
         * @param prefix Indicate the current application that use this Language Handler
         * @param parent
         */
        explicit LanguageManagement(const QString& prefix, QObject* parent = nullptr);
        /**
         * @brief ~LanguageManagement
         */
        virtual ~LanguageManagement();
        /**
         * @brief Set new Language
         * @param languageId The id of the new Language
         * @return
         */
        bool setLanguage(uint32_t languageId);
        /**
         * @brief getCurLanguage
         * @return
         */
        int getCurLanguage() const {
            return m_curLanguageId;
        }
    private:
        /**
         * @brief Prefix
         */
        QString m_prefix;
        /**
         * @brief the current language id
         */
        int m_curLanguageId;
        /**
         * @brief m_curTranslator
         */
        QTranslator* m_curTranslator;

    signals:
        /**
         * @brief Signal to indicate that the current language has changed
         * @param languageId
         */
        void onChangeLanguage(uint32_t languageId);
    };
}

#endif // LANGUAGEMANAGEMENT_H
