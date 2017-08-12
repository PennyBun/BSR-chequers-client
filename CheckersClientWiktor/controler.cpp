#include "controler.h"
#include <QApplication>

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
}

void Controler::regist(QString login, QString password)
{
    comm->regist(login,password);
}
