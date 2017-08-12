//#include "loginwindow.h"
#include "roomwindow.h"
#include "controler.h"
#include <QApplication>
#include<time.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controler controler;// = new Controler();
    //controler.startSession();
    //RoomWindow rmwndw;
    //rmwndw.show();

    return a.exec();
}
