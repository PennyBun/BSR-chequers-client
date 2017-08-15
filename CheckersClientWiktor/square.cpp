#include "square.h"
#include "qpainter.h"
Square::Square(QWidget *parent, Qt::GlobalColor color) : QWidget(parent)
{
    QPalette palette(Square::palette());
    palette.setColor(backgroundRole(),Qt::white);
    setPalette(palette);
    setFixedSize(50,50);
    setContentsMargins(0,0,0,0);

    this->color=color;
}

void Square::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QBrush(color));
        painter.drawRect(0, 0, 100, 100);
}
