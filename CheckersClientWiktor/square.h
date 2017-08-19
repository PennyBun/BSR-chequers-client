#ifndef SQUARE_H
#define SQUARE_H
#include "piece.h"
#include <QWidget>

class Square : public QWidget
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr, Qt::GlobalColor color = Qt::white,int x=0,int y=0);
    bool selected;
     int x,y;
protected:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event)override;
signals:
     void squareClickedWithMouse(Square* that);
public slots:

private:

    Qt::GlobalColor color;
    Piece* myChildPiece;


};

#endif // SQUARE_H
