#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "global.h"

class Board
{
    int _board[HEIGHT][WIDTH];

public:
    Board();
    void printBoard();
    int dropDisk(int column, int player);
    void removeDisk(int row, int column);
    bool boardFull();
    bool columnFull(int column);
    long scoreBoard();
};

#endif // BOARD_H