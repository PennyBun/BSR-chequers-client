#include "communication.h"

Communication::Communication(QObject *parent):
    QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
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
//        QString command = "LGN#";
//        command+=login;
//        command+='#';
//        command+=password;
//        command+='\r\n';
//        socket->write(command.toLocal8Bit());
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
//        QString command = "CRA#";
//        command+=login;
//        command+='#';
//        command+=password;
//        command+='\r\n';
//        socket->write(command.toLocal8Bit());
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
    switch(cmnd){
    case LGN:
        cmndToSend = "LGN";
        break;
    case CRA:
        cmndToSend = "CRA";
        break;
    case LSP:
        cmndToSend = "LSP";
        break;
    case RFP:
        cmndToSend = "RFP";
        break;
    case RP1:
        cmndToSend = "RP1";
        break;
    case RP2:
        cmndToSend = "RP2";
        break;
    case INI:
        cmndToSend = "INI";
        break;
    case CHB:
        cmndToSend = "CHB";
        break;
    case YMV:
        cmndToSend = "YMV";
        break;
    case GVU:
        cmndToSend = "GVU";
        break;
    case EOG:
        cmndToSend = "EOG";
        break;
    case LGO:
        cmndToSend = "LGO";
        break;
    case ERR:
        cmndToSend = "ERR";
        break;
    case ERS:
        cmndToSend = "ERS";
        break;
    case MOV:
        cmndToSend = "MOV";
        break;
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
//         QString command = "LGN#";
//         command+=id;
//         command+='#';
//         command+=password;
//         command+='\r\n';
//         socket->write(command.toLocal8Bit());
         sendCommand(LGN,id,password);
     }
     else
         if(waitingRegister){
//             QString command = "CRA#";
//             command+=id;
//             command+='#';
//             command+=password;
//             command+='\r\n';
//             socket->write(command.toLocal8Bit());
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
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
}