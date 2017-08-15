#ifndef PIECE_H
#define PIECE_H

#include <QWidget>
enum PieceState{
    black,
    white,
    black_King,
    white_King
};

class Piece : public QWidget
{
    Q_OBJECT
public:
    explicit Piece(QWidget *parent = nullptr,PieceState pS = black);
    PieceState pieceState;
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
private:



};

#endif // PIECE_H
