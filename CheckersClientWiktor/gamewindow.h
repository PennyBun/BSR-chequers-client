#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "board.h"
#include "usersgamepanel.h"
namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
     Board* board;
     UsersGamePanel* uGPanel;
     void currentPlayer(bool crrPlr);
private:
    Ui::GameWindow *ui;

    QPushButton* giveUpButton;
};

#endif // GAMEWINDOW_H
