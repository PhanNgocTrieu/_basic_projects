#ifndef SETTINGBATTERY_H
#define SETTINGBATTERY_H
#include <QQuickPaintedItem>
#include <QPainter>
class SettingBattery : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int beginPos READ beginPos WRITE setBeginPos NOTIFY beginPosChanged)
    Q_PROPERTY(int topWidth READ topWidth WRITE setTopWidth NOTIFY topWidthChanged)
    Q_PROPERTY(int bottomWidth READ bottomWidth WRITE setBottomWidth NOTIFY bottomWidthChanged)
    Q_PROPERTY(int heightBattery READ heightBattery WRITE setHeightBattery NOTIFY heightBatteryChanged)
    Q_PROPERTY(int slopeEndHeight READ slopeEndHeight WRITE setSlopeEndHeight NOTIFY slopeEndHeightChanged)
    QML_ELEMENT

public:
    SettingBattery(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;

    int beginPos() const;
    void setBeginPos(int newBeginPos);

    int topWidth() const;
    void setTopWidth(int newTopWidth);

    int bottomWidth() const;
    void setBottomWidth(int newBottomWidth);

    int heightBattery() const;
    void setHeightBattery(int newHeightBattery);

    int slopeEndHeight() const;
    void setSlopeEndHeight(int newSlopeEndHeight);

signals:
    void beginPosChanged();
    void topWidthChanged();
    void bottomWidthChanged();
    void heightBatteryChanged();
    void slopeEndHeightChanged();

private:
    int m_beginPos;
    int m_topWidth;
    int m_bottomWidth;
    int m_heightBattery;
    int m_slopeEndHeight;
};

#endif // SETTINGBATTERY_H
