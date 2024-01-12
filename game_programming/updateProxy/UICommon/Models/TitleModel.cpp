#include <QFontMetrics>
#include "TitleModel.h"
#include "../UICommon.h"

namespace uicommon
{
    /**
     * @brief Construct a new Title Model:: Title Model object
     *
     * @param parent
     * @param width
     * @param separatorStr
     * @param hidenStr
     */
    TitleModel::TitleModel(QObject *parent, int width, const QString &separatorStr, const QString &hidenStr) :
        QAbstractListModel(parent),
        m_maxHeaderWidth(width),
        m_separator(separatorStr),
        m_hidenStr(hidenStr),
        m_font(QFont()) {
        m_font.setFamily(DEFAULT_HEADER_FONT_FAMILY);
        m_font.setPixelSize(DEFAULT_HEADER_FONT_PIXELSIZE);
        m_font.setWeight(static_cast<QFont::Weight>(DEFAULT_HEADER_FONT_WEIGHT));

        QObject::connect(&uicommon::HMISystemServiceProxy::getInstance(), &uicommon::HMISystemServiceProxy::onChangeLanguage, this, [this](uint id) {
            Q_UNUSED(id)
            beginResetModel();
            calculateHeaderSize();
            endResetModel();
        });
    }

    TitleModel::~TitleModel() {
    }

    int TitleModel::rowCount(const QModelIndex &parent) const {
        int count = static_cast<int>(m_headerItems.count());
        if (parent.isValid() == true) {
            count = 0;
        }
        return count;
    }

    QVariant TitleModel::data(const QModelIndex &index, int role) const {
        QVariant ret;
        if (index.isValid() == true) {
            int row = index.row();
            if ((row >= 0) && (row < static_cast<int>(m_headerItems.size()))) {
                switch (static_cast<TitleModel::Role>(role)) {
                case TitleModel::Role::Visible:
                    ret = m_headerItems.at(row).visible;
                    break;
                case TitleModel::Role::Text:
                    ret = m_headerItems.at(row).displayText;
                    break;
                case TitleModel::Role::IsSeparator:
                    ret = m_headerItems.at(row).isSeparator;
                    break;
                case TitleModel::Role::DisplayFlag:
                    ret = m_headerItems.at(row).flag;
                    break;
                case TitleModel::Role::Width:
                    ret = m_headerItems.at(row).width;
                    break;
                default:
                    break;
                }
            }
        }
        return ret;
    }

    QHash<int, QByteArray> TitleModel::roleNames() const {
        QHash<int, QByteArray> roles;
        roles[static_cast<int>(TitleModel::Role::Visible)] = "visible";
        roles[static_cast<int>(TitleModel::Role::Text)] = "label";
        roles[static_cast<int>(TitleModel::Role::IsSeparator)] = "isseparator";
        roles[static_cast<int>(TitleModel::Role::DisplayFlag)] = "flag";
        roles[static_cast<int>(TitleModel::Role::Width)] = "width";
        return roles;
    }

    void TitleModel::setMaxWidth(int width) {
        if (m_maxHeaderWidth != width) {
            m_maxHeaderWidth = width;
            emit maxWidthChanged();
        }
    }

    int TitleModel::getMaxWidth() const {
        return m_maxHeaderWidth;
    }

    void TitleModel::setSeparatorWidth(int width) {
        if (m_separatorWidth != width) {
            m_separatorWidth = width;
            emit separatorWidthChanged();
        }
    }

    int TitleModel::getSeparatorWidth() const {
        return m_separatorWidth;
    }

    void TitleModel::setCollapseText(const QString &str) {
        if (m_collapseText != str) {
            m_collapseText = str;
            emit collapseTextChanged();
        }
    }
    QString TitleModel::getCollapseText() const {
        return m_collapseText;
    }

    void TitleModel::setSeparator(const QString &separator) {
        m_separator = separator;
    }

    void TitleModel::updateItems(const QList<HeaderItem> &headerItems) {
        clear();
        for (HeaderItem item : headerItems) {
            pushBack(item);
        }
        emit sizeChanged();
        calculateHeaderSize();
    }

    void TitleModel::pushBack(const HeaderItem &item) {
        if (m_headerItems.size() > 0U) {
            m_headerItems.push_back(HEADER_ITEM(0, 0, true, m_separator));
        }
        m_headerItems.push_back(item);

        emit sizeChanged();
        calculateHeaderSize();
    }

    void TitleModel::pushBack(const QString &item) {
        if (m_headerItems.size() > 0U) {
            m_headerItems.push_back(HEADER_ITEM(0, 0, true, m_separator));
        }

        int index = static_cast<int>(this->size());
        m_headerItems.push_back(HEADER_ITEM(index, 0, false, item));

        emit sizeChanged();
        calculateHeaderSize();
    }

    void TitleModel::popBack() {
        if (m_headerItems.size() > 0) {
            m_headerItems.pop_back();
            if (m_headerItems.size() >= 2U) {
                m_headerItems.pop_back();
            }
            emit sizeChanged();
            calculateHeaderSize();
        }
    }

    void TitleModel::append(QJSValue jsonObj) {
        if (jsonObj.isObject() == true) {
            if (jsonObj.property("name").isString() == true) {
                beginResetModel();
                pushBack(jsonObj.property("name").toString());
                endResetModel();
            }
        }
    }

    const QList<TitleModel::HeaderItem> &TitleModel::headerFull() const {
        return m_headerItems;
    }

    QList<TitleModel::HeaderItem> TitleModel::header() const {
        QList<TitleModel::HeaderItem> header;
        for (auto &item : m_headerItems) {
            if (item.isSeparator == false) {
                header.push_back(item);
            }
        }
        return header;
    }

    void TitleModel::clear() {
        m_headerItems.clear();
    }

    size_t TitleModel::size() const {
        size_t size = 0;
        for (auto &item : m_headerItems) {
            if (item.isSeparator == false) {
                size += 1;
            }
        }
        return size;
    }

    void TitleModel::setFont(QFont font) {
        m_font = font;
        calculateHeaderSize();
        beginResetModel();
        endResetModel();

        emit fontChanged();
    }

    QFont TitleModel::getFont() const {
        return m_font;
    }

    static int calTotalSize(const QList<TitleModel::HeaderItem> &items) {
        int w = 0;
        for (auto &item : items) {
            if (item.visible == true) {
                w += item.width;
            }
        }
        return w;
    }

    void TitleModel::calculateHeaderSize() {
        QFontMetrics fontMetrics(m_font);
        int size = static_cast<int>(m_headerItems.size());
        int dotSize = fontMetrics.size(0, m_collapseText).width();
        int total = 0;
        int max = m_maxHeaderWidth;
        size_t totalItem = this->size();

        do {
            if (totalItem == 0) {
                break;
            }

            for (int index = 0; index < size; index++) {
                auto &item = m_headerItems[index];
                item.visible = true;
                item.displayText = item.text;
                item.width = 0;
                item.flag = 0;

                if (item.isSeparator) {
                    item.width = m_separatorWidth;
                } else {
                    item.width = fontMetrics.size(0, qtTrId(item.text.toStdString().c_str())).width();
                }
            }

            total = calTotalSize(m_headerItems);
            /* No changes */
            if (total <= max) {
                break;
            }

            auto &firstItem = m_headerItems.front();
            /* size == 1 */
            if (totalItem == 1) {
                firstItem.flag = static_cast<int>(DisplayFlag::ElidedRight);
                firstItem.width = max;
                break;
            }

            auto &firstArrowItem = m_headerItems[1];
            auto &lastItem = m_headerItems.back();
            /* 5b lastest item over the header size */
            if ((max - (lastItem.width + m_separatorWidth)) < dotSize) {
                for (qsizetype i = 0; i < m_headerItems.size(); i++) {
                    m_headerItems[i].visible = false;
                    m_headerItems[i].width = 0;
                }
                firstItem.flag = static_cast<int>(DisplayFlag::Dot);
                firstItem.width = dotSize;
                firstItem.visible = true;
                firstItem.displayText = m_collapseText;
                firstArrowItem.visible = true;
                lastItem.flag = static_cast<int>(DisplayFlag::ElidedRight);
                lastItem.width = max - (dotSize + m_separatorWidth);
                lastItem.visible = true;
                break;
            }

            /* loop for all item, if any lastest item makes over header size, resize all previous items to "..."
             *  except the first item and last item (no changes)
             */
            for (int i = 1; i < (size - 1); i++) {
                auto &item = m_headerItems[i];

                if (item.isSeparator == true) {
                    continue;
                }

                item.width = dotSize;
                item.flag = static_cast<int>(DisplayFlag::Dot);
                item.displayText = m_collapseText;
            }

            /* if the size is fixed, return */
            total = calTotalSize(m_headerItems);
            if (total <= max) {
                break;
            }

            if (totalItem == 2) {
                firstItem.width = max - (m_separatorWidth + lastItem.width);
                firstItem.flag = static_cast<int>(DisplayFlag::ElidedRight);
                break;
            }

            /* f > ... > l*/
            for (int i = 4; i < (size - 1); i++) {
                auto &item = m_headerItems[i];
                item.visible = false;
            }

            /* after hide some dot item and the size is fixed*/
            total = calTotalSize(m_headerItems);
            if (total <= max) {
                break;
            }

            /* after hide but t he size still not fixed, make the first item shorter*/
            int w = max - (lastItem.width + m_separatorWidth * 2 + dotSize);
            if (w < dotSize) {
                for (qsizetype i = 0; i < m_headerItems.size(); i++) {
                    m_headerItems[i].visible = false;
                }
                firstItem.flag = static_cast<int>(DisplayFlag::Dot);
                firstItem.width = dotSize;
                firstItem.visible = true;
                firstItem.text = m_collapseText;
                firstArrowItem.visible = true;
                lastItem.flag = static_cast<int>(DisplayFlag::ElidedRight);
                lastItem.width = max - (dotSize + m_separatorWidth);
                lastItem.visible = true;

            } else {
                firstItem.width = w;
                firstItem.flag = static_cast<int>(DisplayFlag::ElidedRight);
            }

        } while (false);
    }

    void TitleModel::beginResetModel() {
        QAbstractListModel::beginResetModel();
    }

    void TitleModel::endResetModel() {
        QAbstractListModel::endResetModel();
    }
} // namespace uicommon