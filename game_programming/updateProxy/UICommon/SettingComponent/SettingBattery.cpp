#include "SettingBattery.h"

SettingBattery::SettingBattery(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_beginPos(0),
    m_topWidth(0),
    m_bottomWidth(0),
    m_heightBattery(0),
    m_slopeEndHeight(0)
{

}
void SettingBattery::paint(QPainter *painter)
{
    QBrush brush(QColor("#FFCC00"));

    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->setRenderHint(QPainter::Antialiasing);

    QPointF points[6] = {
        QPointF(this->beginPos(), 0.0),
        QPointF(this->topWidth(), 0.0),
        QPointF(this->bottomWidth(), this->slopeEndHeight()),
        QPointF(this->bottomWidth(), this->heightBattery()),
        QPointF(0.0, this->heightBattery()),
        QPointF(0.0, this->slopeEndHeight())
    };
    painter->drawPolygon(points, 6);
}

int SettingBattery::topWidth() const
{
    return m_topWidth;
}

void SettingBattery::setTopWidth(int newTopWidth)
{
    if (m_topWidth == newTopWidth)
        return;
    m_topWidth = newTopWidth;
    emit topWidthChanged();
}

int SettingBattery::bottomWidth() const
{
    return m_bottomWidth;
}

void SettingBattery::setBottomWidth(int newBottomWidth)
{
    if (m_bottomWidth == newBottomWidth)
        return;
    m_bottomWidth = newBottomWidth;
    emit bottomWidthChanged();
    this->update();
}

int SettingBattery::heightBattery() const
{
    return m_heightBattery;
}

void SettingBattery::setHeightBattery(int newHeightBattery)
{
    if (m_heightBattery == newHeightBattery)
        return;
    m_heightBattery = newHeightBattery;
    emit heightBatteryChanged();
}

int SettingBattery::slopeEndHeight() const
{
    return m_slopeEndHeight;
}

void SettingBattery::setSlopeEndHeight(int newSlopeEndHeight)
{
    if (m_slopeEndHeight == newSlopeEndHeight)
        return;
    m_slopeEndHeight = newSlopeEndHeight;
    emit slopeEndHeightChanged();
}

int SettingBattery::beginPos() const
{
    return m_beginPos;
}

void SettingBattery::setBeginPos(int newBeginPos)
{
    if (m_beginPos == newBeginPos)
        return;
    m_beginPos = newBeginPos;
    emit beginPosChanged();
}
