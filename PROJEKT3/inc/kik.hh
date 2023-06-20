#pragma once
#include "size.hh"
#include "board.hh"

class kik
{

    void xMove(int x, int y); // put a "x" character on the board
    void oMove(int x, int y); // put a "o" character on the board

    bool diagonalStreak1();
    bool diagonalStreak2();
    bool diagonalStreak();

    bool verticalStreak();
    bool horizontalStreak();
    bool gameOver();
    bool streak();
    bool tie();

    int whoWon;//1 -> x , -1 -> o , 0 ->tie
    int minmax(int depth,bool isMaximizingPlayer);
    position findBestMove();

public:
    kik();
    board b;
    void play(int mode);
};
