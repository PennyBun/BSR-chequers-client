#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "board.h"
namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    Board* board;
    QPushButton* giveUpButton;
};

#endif // GAMEWINDOW_H
