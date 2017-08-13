#include "communication.h"
#include <iostream>
#include <string>
Communication::Communication(QObject *parent):
    QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    //commandMap = new std::unordered_map<int, std::string>();
    commandMap.insert( // std::unordered_map<QString, command>();
    {
       {"LGN",LGN},
       {"CRA",CRA},
       {"LSP",LSP},
       {"RFP",RFP},
       {"RP1",RP1},
       {"RP2",RP2},
       {"INI",INI},
       {"CHB",CHB},
       {"YMV",YMV},
       {"GVU",GVU},
       {"EOG",EOG},
       {"LGO",LGO},
       {"ERR",ERR},
       {"ERS",ERS},
       {"MOV",MOV},
       {"INTERNAL_ERROR",INTERNAL_ERROR}
    });
//    for(auto& p : commandMap)
//    {
//  //      qDebug() << QString(p.first) << " " << QString(p.second);
//        qDebug() << " " << p.first.data();// << " => " << p.second.c_str() << '\n';
//    }
}

Communication::~Communication()
{
    sendCommand(LGO);
    socket->waitForBytesWritten(5000);
    socket->close();
    delete socket;
}


void Communication::startSession()
{
    socket->connectToHost("35.187.18.31",4000);

}

void Communication::login(QString login, QString password)
{
    waitingLogin = true;
    waitingRegister = false;
    id=login;
    this->password=password;
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        sendCommand(LGN,login,password);
    }
    else
    {
        startSession();
    }
}

void Communication::regist(QString login, QString password)
{
    waitingLogin = false;
    waitingRegister = true;
    id=login;
    this->password=password;
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        sendCommand(CRA,login,password);
    }
    else
    {
        startSession();
    }
}

void Communication::sendCommand(command cmnd, QString prm1, QString prm2, QString prm3, QString prm4)
{
    QString cmndToSend;
    for(auto& p : commandMap)
    {
        if(cmnd==p.second)
        {
            cmndToSend=p.first.data();
            break;
        }
    }
    QStringList cmndList;
    cmndList <<cmndToSend;
    if(!prm1.isNull())
    {
        cmndList <<prm1;
    }
    if(!prm2.isNull())
    {
        cmndList <<prm2;
    }
    if(!prm3.isNull())
    {
        cmndList <<prm3;
    }
    if(!prm4.isNull())
    {
        cmndList <<prm4;
    }
    QString fullCommand;
    fullCommand = cmndList.join('#');
    fullCommand+="\n";
    socket->write(fullCommand.toLocal8Bit());
    qDebug()<< "Send:";
    qDebug()<<fullCommand;
}

void Communication::connected()
{
     if(waitingLogin)
     {
         sendCommand(LGN,id,password);
     }
     else
         if(waitingRegister){
             sendCommand(CRA,id,password);
         }
}

void Communication::disconnected()
{
     qDebug() << "Disconnected!";
}

void Communication::bytesWritten(qint64 bytes)
{
    qDebug() << "Wrote: "<<bytes;
}

void Communication::readyRead()
{
    emit commandReceived(parse(socket->readAll()));
//    qDebug() << "Reading...";
//    qDebug() << socket->readAll();
}

fullCommand Communication::parse(QString notParsedCommand)
{
    notParsedCommand=notParsedCommand.trimmed();
    QStringList splitedCommand;
    splitedCommand = notParsedCommand.split('#');
    int numberOfParameters = splitedCommand.count()-1;
    fullCommand fllCmmnd;
    std::string commandString = splitedCommand[0].toString();

//    auto search = commandMap.find(commandString);

//    if(search!=commandMap.end())
//    {
//        fllCmmnd.com=search->second;
//    }
//    else
//    {
//        fllCmmnd.com=INTERNAL_ERROR;
//    }

    switch(numberOfParameters)
    {
    case 4:
        fllCmmnd.prm4=splitedCommand[4];
    case 3:
        fllCmmnd.prm3=splitedCommand[3];
    case 2:
        fllCmmnd.prm2=splitedCommand[2];
    case 1:
        fllCmmnd.prm1=splitedCommand[1];
    default:
        break;
    }
    return fllCmmnd;
}
