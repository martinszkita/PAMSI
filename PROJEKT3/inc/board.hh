#ifndef BOARD_HH
#define BOARD_HH
#include "size.hh"
#include <vector>
#include <iostream>

struct position
{
    int x;
    int y;
    position(){}
    position(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};

class board
{
    // std::vector<pawn> pawnsVec;

public:
    board();
    char piecesBoard[SIZE][SIZE];
};

std::ostream &operator<<(std::ostream &os, const board &b);

#endif // BOARD.HH