#ifndef CONTROLER_H
#define CONTROLER_H
#include "loginwindow.h"
#include "communication.h"

#include <QObject>
#include <QDebug>

class Controler : public QObject
{
    Q_OBJECT
public:
    explicit Controler(QObject *parent = 0);
    ~Controler();
    void show();
    void startSession();
public slots:
    void login(QString login, QString password);
    void regist (QString login, QString password);
    void commandReceived(fullCommand fllCmmnd);

private:
    LoginWindow loginWindow;
    Communication* comm;

    //QNetworkSession *networkSession;

    //QDataStream in;
};

#endif // CONTROLER_H
