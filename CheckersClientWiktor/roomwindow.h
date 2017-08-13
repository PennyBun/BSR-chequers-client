#ifndef ROOMWINDOW_H
#define ROOMWINDOW_H

#include <QDialog>

namespace Ui {
class RoomWindow;
}

class RoomWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RoomWindow(QWidget *parent = 0);
    ~RoomWindow();
     void setUser(QString user);

private:
    Ui::RoomWindow *ui;
};

#endif // ROOMWINDOW_H
