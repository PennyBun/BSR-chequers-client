#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <QtNetwork>
#include "command.h"
class Communication: public QObject
{
        Q_OBJECT
public:
    explicit Communication(QObject *parent = 0);
    ~Communication();
    void startSession();
    void login(QString login, QString password);
    void regist(QString login, QString password);
    void sendCommand(command cmnd, QString prm1 = QString(), QString prm2 = QString(),QString prm3 = QString() ,QString prm4 = QString() );
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
private:
    QTcpSocket *socket;
    bool waitingLogin =0;
    bool waitingRegister = 0;
    QString id;
    QString password;
};

#endif // COMMUNICATION_H
