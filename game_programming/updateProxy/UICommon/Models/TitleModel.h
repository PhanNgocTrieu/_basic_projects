#ifndef TITLEMODEL_H
#define TITLEMODEL_H

#include <QAbstractListModel>
#include <unordered_map>
#include <QFont>
#include <QJsonObject>
#include <QJSValue>

#define DEFAULT_SEPARATOR_STR         ">"
#define DEFAULT_HIDEN_STR             "..."
#define DEFAULT_HEADER_FONT_FAMILY    "Suzuki_IF TazuganeInfo"
#define DEFAULT_HEADER_FONT_PIXELSIZE 28
#define DEFAULT_HEADER_FONT_WEIGHT    275
#define DEFAULT_MAX_HEADER_ITEM_WIDTH 824
#define DEFAULT_HEADER_ITEM_WIDTH     300
#define DEFAULT_SEPARATOR_WIDTH       48


namespace uicommon
{
#define HEADER_ITEM(index, type, separator, txt) \
    uicommon::TitleModel::HeaderItem { true, static_cast<int>(index), static_cast<int>(type), separator, DEFAULT_HEADER_ITEM_WIDTH, txt, txt, 0 }

    class TitleModel : public QAbstractListModel
    {
        Q_OBJECT
        Q_PROPERTY(size_t size READ size NOTIFY sizeChanged)
        Q_PROPERTY(QFont font READ getFont WRITE setFont NOTIFY fontChanged)
        Q_PROPERTY(int maxWidth READ getMaxWidth WRITE setMaxWidth NOTIFY maxWidthChanged)
        Q_PROPERTY(int separatorWidth READ getSeparatorWidth WRITE setSeparatorWidth NOTIFY separatorWidthChanged)
        Q_PROPERTY(QString collapseText READ getCollapseText WRITE setCollapseText NOTIFY collapseTextChanged)

    public:
        enum class Role {
            Visible = Qt::UserRole,
            Text,
            IsSeparator,
            DisplayFlag,
            Width,
        };

        enum class DisplayFlag {
            Normal = 0,
            ElidedRight,
            ElidedLeft,
            Hiden,
            Dot,
        };

        struct HeaderItem {
            bool visible;
            int index;
            int type;
            bool isSeparator;
            int width;
            QString text;
            QString displayText;
            int flag;
        };

        explicit TitleModel(QObject *parent = nullptr,
                            int width = DEFAULT_MAX_HEADER_ITEM_WIDTH,
                            const QString &separatorStr = DEFAULT_SEPARATOR_STR,
                            const QString &hidenStr = DEFAULT_HIDEN_STR);
        ~TitleModel();

        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role) const override;
        QHash<int, QByteArray> roleNames() const override;

        void setMaxWidth(int width);
        int getMaxWidth() const;

        void setSeparatorWidth(int width);
        int getSeparatorWidth() const;

        void setCollapseText(const QString &str);
        QString getCollapseText() const;

        void setSeparator(const QString &separator);
        void updateItems(const QList<TitleModel::HeaderItem> &headerItems);
        void pushBack(const HeaderItem &item);

        Q_INVOKABLE void pushBack(const QString &item);
        Q_INVOKABLE void popBack();
        Q_INVOKABLE void append(QJSValue jsonObj);

        /* Raw data including separator character */
        const QList<HeaderItem> &headerFull() const;
        /* Text only */
        QList<HeaderItem> header() const;

        Q_INVOKABLE void clear();
        Q_INVOKABLE size_t size() const;

        Q_INVOKABLE void setFont(QFont font);
        QFont getFont() const;

        void calculateHeaderSize();

        void beginResetModel();
        void endResetModel();

    signals:
        void sizeChanged();
        void fontChanged();
        void maxWidthChanged();
        void separatorWidthChanged();
        void collapseTextChanged();

    private:
        int m_maxHeaderWidth{};
        QString m_separator{DEFAULT_SEPARATOR_STR};
        QString m_hidenStr{DEFAULT_HIDEN_STR};
        QList<HeaderItem> m_headerItems;
        QFont m_font;
        QString m_collapseText{DEFAULT_HIDEN_STR};
        int m_separatorWidth{DEFAULT_SEPARATOR_WIDTH};
    };
} // namespace uicommon
#endif // TITLEMODEL_H