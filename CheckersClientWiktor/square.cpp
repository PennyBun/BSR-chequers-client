#include "square.h"
#include "qpainter.h"
Square::Square(QWidget *parent, Qt::GlobalColor color, int x, int y) : QWidget(parent)
{
    QPalette palette(Square::palette());
    palette.setColor(backgroundRole(),Qt::white);
    setPalette(palette);
    setFixedSize(50,50);
    setContentsMargins(0,0,0,0);
    this->x=x;
    this->y=y;
    this->color=color;
    selected=false;
}

void Square::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        if(selected){
            QPen qpen(Qt::red);
            qpen.setWidth(4);
            painter.setPen(qpen);
        }
        painter.setBrush(QBrush(color));
        painter.drawRect(0, 0, 49, 49);
}
void Square::mouseReleaseEvent(QMouseEvent *event)
{
    selected= !selected;
    update();
     emit squareClickedWithMouse(this);
}
