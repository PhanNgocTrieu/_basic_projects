#ifndef IDSWINDOW_H
#define IDSWINDOW_H

#include <QObject>
#include <QQmlEngine>
#include <QtAppManLauncher/private/applicationmanagerwindow_p.h>

namespace uicommon {

class IDSWindow : public QtAM::ApplicationManagerWindow
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString displayLayer READ getDisplayLayer WRITE setDisplayLayer NOTIFY displayLayerChanged)
    QML_ELEMENT
public:
    explicit IDSWindow(QWindow *parent = nullptr);

    QString getName() const {
        return m_name;
    }

    QString getDisplayLayer() const {
        return m_layer;
    }

    void setName(const QString& value);

    void setDisplayLayer(const QString& value);

protected slots:
    void _xChanged(int arg);
    void _yChanged(int arg);


protected:
    QString m_name;
    QString m_layer;

signals:
    void nameChanged();
    void displayLayerChanged();
};

}

#endif // IDSWINDOW_H
