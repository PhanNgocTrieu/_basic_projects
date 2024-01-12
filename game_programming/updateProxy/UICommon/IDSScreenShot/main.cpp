#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QLocalSocket>
#include <QThread>
#include <QObject>

class KeyReader: public QThread
{
    Q_OBJECT
public:
    KeyReader(){}

protected:
    void run() override
    {
        while(1) {
            char ch;
            ch = getchar();
            if (ch == 'q') {
                QCoreApplication::quit();
                break;
            }
            else if (ch == 's') {
                qDebug() << "onScreenShot";
                emit onScreenShot("Screen Shot screen");
            }
        }
    }
signals:
    void onScreenShot(QString newMessage);
};

class MessagePostal: public QObject
{
    Q_OBJECT
public:
    explicit MessagePostal(const QString& socketAddr, QObject* parent = nullptr){
        m_socketAddr= socketAddr;

        QObject::connect(&localSocket, &QLocalSocket::connected, &localSocket, []() {
            qDebug() << "Socket connected";
        });
        localSocket.setServerName(m_socketAddr);
        localSocket.connectToServer();
    }


public slots:
    void sendScreenShotMessage(QString newMessage){
        QString msg(newMessage);
        qDebug() <<localSocket.write(msg.toLatin1()) << msg;
    }
protected:
    QLocalSocket localSocket;
    QString m_socketAddr;
};



int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    KeyReader m_keyReader;
    MessagePostal m_messagePostal("/tmp/idsScreenShot");
    QObject::connect (&m_keyReader,SIGNAL(onScreenShot(QString)), &m_messagePostal, SLOT(sendScreenShotMessage(QString)));
    m_keyReader.start();
    return app.exec();
}
#include "main.moc"
