#include "piece.h"
#include "qpainter.h"
Piece::Piece(QWidget *parent, PieceState pS) : QWidget(parent)
{
    pieceState=pS;
    QPalette palette(Piece::palette());
    palette.setColor(backgroundRole(),Qt::white);
    setPalette(palette);
    setFixedSize(40,40);
    setContentsMargins(5,5,5,5);

}

void Piece::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        switch (pieceState)
        {
            case black:
            {
                painter.setBrush(QBrush(Qt::black));
                painter.setPen(QPen(Qt::white));
                break;
            }
            case white:
            {
                painter.setBrush(QBrush(Qt::white));
                break;
            }
            case black_King:
            {
                painter.setBrush(QBrush(Qt::black));
                break;
            }
            case white_King:
            {
                painter.setBrush(QBrush(Qt::white));
                break;
            }
        }
        painter.drawEllipse(0,0,40,40);
}
