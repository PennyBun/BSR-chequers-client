#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    board = new Board();
    giveUpButton = new QPushButton("Poddaję się",this);

   ui->horizontalLayout->addWidget(board);
   QVBoxLayout *vLayout = new QVBoxLayout;
    ui->horizontalLayout->addItem(vLayout);
    vLayout->addWidget(giveUpButton);
}

GameWindow::~GameWindow()
{
    delete ui;
}
