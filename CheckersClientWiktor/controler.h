#ifndef CONTROLER_H
#define CONTROLER_H
#include "loginwindow.h"
#include "roomwindow.h"
#include "communication.h"
#include "state.h"
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
    QString user;
    LoginWindow loginWindow;
    RoomWindow roomWindow;
    Communication* comm;
    state crrState = NLG;
    void changeState(state nextState);
    void LGN_WFRcommandAnalyser(fullCommand fllCmmnd);
    void NLGcommandAnalyser(fullCommand fllCmmnd);
    void CRA_WFRcommandAnalyser(fullCommand fllCmmnd);
    void ROOMcommandAnalyser(fullCommand fllCmmnd);
    void LSP_WFRcommandAnalyser(fullCommand fllCmmnd);
    void WAITRcommandAnalyser(fullCommand fllCmmnd);
    void WAITGcommandAnalyser(fullCommand fllCmmnd);
    void GAMEcommandAnalyser(fullCommand fllCmmnd);
    void unexpectedCommand();
    void openRoomWindow();
    void refreshPlayersList();
    //QNetworkSession *networkSession;

    //QDataStream in;
};

#endif // CONTROLER_H
