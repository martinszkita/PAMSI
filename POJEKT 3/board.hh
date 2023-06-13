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
    std::vector<pieces> area;

public:
    void printBoard();
    void makeMove(square sq);
    board();
};

void board::printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << "| ";
        }
        std::cout << std::endl;
    }
}