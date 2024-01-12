#include "LanguageManagement.h"
#include "QCoreApplication"
#include <QLocale>
#define MAX_NUM_LANGUAGES 34

namespace uicommon
{
    LanguageManagement::LanguageManagement(const QString& prefix, QObject* parent)
        : QObject{parent},
        m_prefix{prefix},
        m_curLanguageId{-1},
        m_curTranslator{nullptr}
    {

    }

    bool LanguageManagement::setLanguage(uint32_t languageId)
    {
        static const char* localDesc[MAX_NUM_LANGUAGES] = {
            "ja",
            "en-US",
            "en-GB",
            "en-IN",
            "hi",
            "en-AU",
            "de",
            "nl",
            "fr",
            "it",
            "es",
            "es-MX",
            "pt",
            "hu",
            "pl",
            "da",
            "cs",
            "nb",
            "sv",
            "tr",
            "el",
            "ru",
            "th",
            "id",
            "ar",
            "sk",
            "ro",
            "zh",
            "uk",
            "nl-BE",
            "he",
            "hr",
            "sl",
            "fi"
        };
        //Fix klocwork START
        bool isSetLang = false;
        if (m_curLanguageId == static_cast<int>(languageId)) {
            isSetLang = true;
        }else{
            if (languageId < static_cast<uint32_t>(MAX_NUM_LANGUAGES)) {
                QTranslator* transObj = new (std::nothrow) QTranslator();
                if (transObj != nullptr) {
                    if (!transObj->load(m_prefix + QString::fromStdString(std::string(localDesc[languageId])),":/i18n/")) {
                        delete transObj;
                    }else{
                        if (m_curTranslator != nullptr) {
                            (void)QCoreApplication::removeTranslator(m_curTranslator);
                            delete m_curTranslator;
                        }
                        m_curTranslator = transObj;
                        m_curLanguageId = languageId;
                        (void)QCoreApplication::installTranslator(m_curTranslator);

                        emit onChangeLanguage(languageId);

                        isSetLang = true;
                    }
                }
            }
        }
        return isSetLang;
        //Fix klocwork END
    }

    LanguageManagement::~LanguageManagement()
    {
        delete m_curTranslator;
    }




}
