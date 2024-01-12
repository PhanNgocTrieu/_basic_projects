#include "IDSWindow.h"
#include <QThread>
#include <QtAppManLauncher/launchermain.h>

namespace uicommon {

IDSWindow::IDSWindow(QWindow *parent)
    : QtAM::ApplicationManagerWindow{parent}
{
    QObject::connect(this,&IDSWindow::xChanged,this,&IDSWindow::_xChanged,Qt::QueuedConnection);
    QObject::connect(this,&IDSWindow::yChanged,this,&IDSWindow::_yChanged,Qt::QueuedConnection);
    setWindowProperty("name","ABCDEF");
}

void IDSWindow::setName(const QString& value)
{
    if (m_name != value) {
        m_name = value;
        setWindowProperty("name",QVariant::fromValue(value));
        emit nameChanged();
// Fix klocwork START
    }else{
        //Do something
// Fix klocwork END
    }
}

void IDSWindow::setDisplayLayer(const QString& value)
{
    if (m_layer != value) {
        m_layer = value;

        setWindowProperty("displayLayer",QVariant::fromValue(value));
        emit displayLayerChanged();
    }
}

void IDSWindow::_xChanged(int arg)
{
    setWindowProperty("x",QVariant::fromValue(arg));
}

void IDSWindow::_yChanged(int arg)
{
    setWindowProperty("y",QVariant::fromValue(arg));
}

}
