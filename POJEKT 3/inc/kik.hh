#pragma once
#include "size.hh"
#include "board.hh"

class kik
{

    void xMove(int x, int y); // put a "x" character on the board
    void oMove(int x, int y); // put a "o" character on the board

    bool gameOver();
    bool streak();

public:
    kik();
    board b;
    void play();
};
