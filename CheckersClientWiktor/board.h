#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "square.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <QGridLayout>
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);

signals:

public slots:
private:
    //Square *square;
    //std::vector<std::vector<Square*>>* squaresTable;//(8,vector<point>(8));
    Square **squareTable;
    //Matrix ma;
    //Square squaresTable [8][8];
};

#endif // BOARD_H
