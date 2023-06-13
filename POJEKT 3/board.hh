#pragma once
#include "kik.hh"
#include "size.hh"
#include <iostream>
#include <vector>

struct square
{
    int x;
    int y;
    // bool isEmpty();
};

struct pawn
{
    square posP;
};

struct queen
{
    square posQ;
};

struct pieces
{
    pawn p;
    queen q;
};

class board
{
    std::vector<pieces> pcs;
    char piecesBoard[SIZE][2*SIZE-1];

public:
    void printBoard();
    void xMove(int x, int y); // put a "x" character on the board
    void oMove(int x, int y); // put a "o" character on the board
    board();
};

