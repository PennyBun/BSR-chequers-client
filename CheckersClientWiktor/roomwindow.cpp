#include "roomwindow.h"
#include "ui_roomwindow.h"

RoomWindow::RoomWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomWindow)
{
    ui->setupUi(this);
}

RoomWindow::~RoomWindow()
{
    delete ui;
}

void RoomWindow::setUser(QString user)
{
    ui->userLabel->setText(user);
}
