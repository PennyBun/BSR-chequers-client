#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>

class Square : public QWidget
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr, Qt::GlobalColor color = Qt::white);
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
private:
    Qt::GlobalColor color;

};

#endif // SQUARE_H
