#include "controler.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
Controler::Controler(QObject *parent):

    QObject(parent)
    //, networkSession(Q_NULLPTR)
{
 //   in.setDevice(socket);
   // in.setVersion(QDataStream::Qt_4_0);
    loginWindow.show();
    comm = new Communication();
    connect(&loginWindow, SIGNAL(login(QString,QString)), this, SLOT(login(QString,QString)));
    connect(&loginWindow, SIGNAL(regist(QString,QString)), this, SLOT(regist(QString,QString)));
    connect(comm, SIGNAL(commandReceived(fullCommand)),this,SLOT(commandReceived(fullCommand)));
    connect(&roomWindow,SIGNAL(refreshButtonSignal()),this,SLOT(refreshButtonSlot()));
    connect(&roomWindow,SIGNAL(logout()),this,SLOT(logout()));
    connect(&roomWindow,SIGNAL(invite(QString)),this,SLOT(invite(QString)));
}

Controler::~Controler()
{
    delete comm;
}

void Controler::startSession()
{
    //socket->connectToHost("35.187.18.31",4000);
    //socket->connectToHost("bogotobogo.com", 80);
//    if(socket->waitForConnected(3000))
//    {
//        socket->write("LGN#WIK#WIK\r\n");
//        socket->waitForBytesWritten(1000);
//        socket->waitForReadyRead(500);
//        qDebug()<<"Reading : "<< socket->bytesAvailable();
//        qDebug()<<socket->readAll();

//        QString text;
//        in>>text;
//        qDebug()<<text;
//        socket->write("LGO\r\n");
//        socket->waitForBytesWritten(1000);
//        socket->close();
//    }
//    else
//    {
//        qDebug() << "Not Connected!";
//    }

}



void Controler::login(QString login, QString password)
{
    comm->login(login,password);
    changeState(LGN_WFR);
    user=login;
}

void Controler::regist(QString login, QString password)
{
    comm->regist(login,password);
    changeState(CRA_WFR);
}

void Controler::commandReceived(fullCommand fllCmmnd)
{
    switch (crrState) {
    case LGN_WFR:
        LGN_WFRcommandAnalyser(fllCmmnd);
        break;
    case CRA_WFR:
        CRA_WFRcommandAnalyser(fllCmmnd);
        break;
    case NLG:
        NLGcommandAnalyser(fllCmmnd);
        break;
    case ROOM   :
        ROOMcommandAnalyser(fllCmmnd);
        break;
    case LSP_WFR:
        LSP_WFRcommandAnalyser(fllCmmnd);
        break;
    case RFP_WFR:
        RFP_WFRcommandAnalyser(fllCmmnd);
        break;
    case WAITR  :
        WAITRcommandAnalyser(fllCmmnd);
        break;
    case WAITG  :
        WAITGcommandAnalyser(fllCmmnd);
        break;
    case GAME   :
        GAMEcommandAnalyser(fllCmmnd);
        break;
    default:
        break;
    }
}

void Controler::refreshButtonSlot()
{
    refreshPlayersList();
}

void Controler::logout()
{
    comm->sendCommand(LGO);
    changeState(NLG);
    roomWindow.close();
    loginWindow.show();
}

void Controler::invite(QString user)
{
    comm->sendCommand(RFP,user);
    changeState(RFP_WFR);
    invitedUser=user;
}

void Controler::changeState(state nextState)
{
    switch (nextState){
        case NLG    :
            qDebug()<<"state: NLG";
            break;
        case LGN_WFR:
            qDebug()<<"state: LGN_WFR";
            break;
        case CRA_WFR:
            qDebug()<<"state: CRA_WFR";
            break;
        case ROOM   :
            qDebug()<<"state: ROOM";
            break;
        case LSP_WFR:
            qDebug()<<"state: LSP_WFR";
            break;
        case WAITR  :
            qDebug()<<"state: WAITR";
            break;
        case WAITG  :
            qDebug()<<"state: WAITG";
            roomWindow.waitingForPlayerResponse(false);
            roomWindow.close();
            gameWindow.show();

            break;
        case GAME   :
            qDebug()<<"state: GAME";

            break;
    }
    prvState=crrState;
    crrState=nextState;

}

void Controler::LGN_WFRcommandAnalyser(fullCommand fllCmmnd)
{
    switch(fllCmmnd.com)
    {
    case LGN:


        if(fllCmmnd.par1()=="1")
        {
            changeState(ROOM);
            openRoomWindow();
            loginWindow.close();
            loginWindow.clearFields();
        }
        else if(fllCmmnd.par1()=="0")
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warcaby");
            msgBox.setText("Niepoprawne nazwa użytkownika lub hasło");
            msgBox.exec();
            changeState(NLG);
        }
        break;
    case ERR:
        if(fllCmmnd.par1()=="not enough parameters")
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warcaby");
            msgBox.setText("Przed zalogowaniem wypełnij pola 'login' i 'hasło'");
            msgBox.exec();
            changeState(NLG);

        }else
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warcaby");
            msgBox.setText("Błąd!");
            msgBox.setInformativeText("Niewłaściwa liczba parametrów");
            msgBox.exec();
            changeState(NLG);
        }
        break;
    default:
        unexpectedCommand();
        changeState(NLG);
        break;
    }
}

void Controler::NLGcommandAnalyser(fullCommand fllCmmnd)
{

}

void Controler::CRA_WFRcommandAnalyser(fullCommand fllCmmnd)
{
    switch (fllCmmnd.com)
    {
    case CRA:
        if(fllCmmnd.par1()=="1")
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warcaby");
            msgBox.setText("Zarejestrowano użytkownika.");
            msgBox.setInformativeText("Zaloguj się, aby zagrać.");
            msgBox.exec();
            changeState(NLG);

        }
        else if(fllCmmnd.par1()=="0")
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warcaby");
            msgBox.setText("Rejestracja nie powiodła się.");
            msgBox.setInformativeText("Nazwa użytkownika jest zajęta");
            msgBox.exec();
            changeState(NLG);
        }
        else{

        }
        break;
    case ERR:
        if(fllCmmnd.par1()=="not enough parameters")
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warcaby");
            msgBox.setText("Przed zarejestrowaniem wypełnij pola 'login' i 'hasło'");
            msgBox.exec();
            changeState(NLG);

        }else
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warcaby");
            msgBox.setText("Błąd!");
            msgBox.setInformativeText("Niewłaściwa liczba parametrów");
            msgBox.exec();
            changeState(NLG);
        }
        break;
    default:
        unexpectedCommand();
        changeState(NLG);
        break;
    }


}

void Controler::ROOMcommandAnalyser(fullCommand fllCmmnd)
{
    state defaultState = ROOM;
    switch (fllCmmnd.com)
    {
    case RP1:
        {
            QString question = "Otrzymałeś zaproszenie do gry od użytkownika '";
            question += fllCmmnd.par1();
            question += "'. Czy chcesz z nim zagrać?";
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(&roomWindow, "Zaproszenie do gry", question ,QMessageBox::No|QMessageBox::Yes);

            if (reply == QMessageBox::Yes) {
                comm->sendCommand(RP1,"1");
                changeState(WAITG);

            } else {
                comm->sendCommand(RP1,"0");
            }
        }
        break;

    case ERR:
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warcaby");
        msgBox.setText("Błąd protokołu!");
        msgBox.exec();
        changeState(defaultState);
    }
        break;
    case ERS:
        break;
    default:
    {
        unexpectedCommand();
        changeState(defaultState);
    }
        break;
    }
}

void Controler::LSP_WFRcommandAnalyser(fullCommand fllCmmnd)
{
    state defaultState = ROOM;
    switch (fllCmmnd.com)
    {
    case LSP:
    {
        int parNumber = fllCmmnd.parameters.length();
        Player tempPlayer;
        playersList.clear();
        for(int i =0;i<parNumber;i++)
        {

            if(i%2==0){

                tempPlayer.name=fllCmmnd.parameters[i];

            }
            else
            {
                if(fllCmmnd.parameters[i]=="A")
                {
                    tempPlayer.free=true;
                }
                else if(fllCmmnd.parameters[i]=="B")
                {
                    tempPlayer.free=false;
                }
                else{
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Warcaby");
                    msgBox.setText("Błąd protokołu!");
                    msgBox.exec();
                    changeState(defaultState);
                }
                playersList.push_back(tempPlayer);
            }
        }
        for (std::list<Player>::iterator a = playersList.begin(), end =playersList.end() ; a !=end; ++a )
        {

          //  qDebug()<<end->name;// <<" "<<end;
            if(a->name==user)
            {
                a=playersList.erase(a);
            }
        }
        playersList.sort();

        roomWindow.refreshPlayersList(playersList);
        changeState(defaultState);
    }
    break;
    case ERR:
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warcaby");
        msgBox.setText("Błąd protokołu!");
        msgBox.exec();
        changeState(defaultState);
    }
        break;
    case ERS:
        break;
    default:
    {
        unexpectedCommand();
        changeState(defaultState);
    }
        break;
    }
}

void Controler::RFP_WFRcommandAnalyser(fullCommand fllCmmnd)
{
    state defaultState = ROOM;
    switch (fllCmmnd.com)
    {
    case RFP:
        {
            if(fllCmmnd.par1()=="1")
            {
                changeState(WAITR);
                roomWindow.waitingForPlayerResponse(true,invitedUser);

            }
            else if(fllCmmnd.par1()=="0")
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Warcaby");
                msgBox.setText("Nie można zaprosić użytkownika do gry.");
                msgBox.exec();
                changeState(defaultState);
                refreshPlayersList();
            }
            else{
                QMessageBox msgBox;
                msgBox.setWindowTitle("Warcaby");
                msgBox.setText("Błąd protokołu!");
                msgBox.setInformativeText("Otrzymano nieprawidłowy parametr");
                msgBox.exec();
                changeState(defaultState);
            }
        }
        break;

    case ERR:
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warcaby");
        msgBox.setText("Nie można zaprosić użytkownika do gry.");
        msgBox.exec();
        changeState(defaultState);
        refreshPlayersList();
    }
        break;
    case ERS:
        break;
    default:
    {
        unexpectedCommand();
        changeState(defaultState);
    }
        break;
    }
}

void Controler::WAITRcommandAnalyser(fullCommand fllCmmnd)
{
    state defaultState = WAITR;
    switch (fllCmmnd.com)
    {
    case RP2:
        {
            if(fllCmmnd.par1()=="1")
            {
                changeState(WAITG);


            }
            else if(fllCmmnd.par1()=="0")
            {

                QMessageBox msgBox;
                msgBox.setWindowTitle("Warcaby");
                msgBox.setText("Użytkownik "+user+" odrzucił zaproszenie do gry");
                msgBox.exec();
                changeState(ROOM);
                roomWindow.waitingForPlayerResponse(false);
                //refreshPlayersList();
            }
            else{
                QMessageBox msgBox;
                msgBox.setWindowTitle("Warcaby");
                msgBox.setText("Błąd protokołu!");
                msgBox.setInformativeText("Otrzymano nieprawidłowy parametr");
                msgBox.exec();
                changeState(defaultState);
            }
        }
        break;


    case ERR:
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warcaby");
        msgBox.setText("Błąd protokołu!");
        msgBox.exec();
        changeState(defaultState);
    }
        break;
    case ERS:
        break;
    default:
    {
        unexpectedCommand();
        changeState(defaultState);
    }
        break;
    }
}

void Controler::WAITGcommandAnalyser(fullCommand fllCmmnd)
{

}

void Controler::GAMEcommandAnalyser(fullCommand fllCmmnd)
{

}

void Controler::unexpectedCommand()
{
    QMessageBox msgBox;
    msgBox.setText("Otrzymano od serwera nieoczekiwaną komendę");
    msgBox.exec();
}

void Controler::openRoomWindow()
{

    roomWindow.setUser(user);
    roomWindow.show();
    refreshPlayersList();
}

void Controler::refreshPlayersList()
{
    comm->sendCommand(LSP);
    changeState(LSP_WFR);
}
