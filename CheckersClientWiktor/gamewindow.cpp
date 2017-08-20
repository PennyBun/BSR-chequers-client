#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    board = new Board(this);
    uGPanel = new UsersGamePanel(this);
    giveUpButton = new QPushButton("Poddaję się",this);

   ui->horizontalLayout->addWidget(board);
   QVBoxLayout *vLayout = new QVBoxLayout;
    ui->horizontalLayout->addItem(vLayout);
    vLayout->addWidget(uGPanel);
    vLayout->addWidget(giveUpButton);
    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vLayout->addItem(spacer);
    connect(giveUpButton,SIGNAL(clicked()),this,SLOT(on_giveUpButton_Clicked()));
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::currentPlayer(bool crrPlr)
{
    uGPanel->currentPlayer(crrPlr);
    board->currentPlayer(crrPlr);
    update();
}

void GameWindow::on_giveUpButton_Clicked()
{
    emit(giveUp());
}
