#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->move(100,100);
  //  QDesktopWidget qdw = ;
//    int scrWdth=qdw.screen()->width();
//    int scrHght=qdw.screen()->height();
//    int width=this->frameGeometry().width();
//    int height=this->frameGeometry().height();
//    this->setGeometry(((scrWdth/2)-(width/2)),((scrHght/2)-(height/2)),width,height);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_loginButton_clicked()
{
    emit login(id,password);
}

void LoginWindow::on_loginLineEdit_textChanged(const QString &arg1)
{
    id = ui->loginLineEdit->text();

}

void LoginWindow::on_passwordLineEdit_textChanged(const QString &arg1)
{
    password = ui->passwordLineEdit->text();
}

void LoginWindow::on_registerButton_clicked()
{
    emit regist(id,password);
}
