#include "../inc/board.hh"
#include <iostream>

board::board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            piecesBoard[i][j] = ' ';
        }
    }
}

std::ostream &operator<<(std::ostream &os, const board &b)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j >= 0 && j < SIZE - 1)
            {
                os << b.piecesBoard[i][j] << "|";
            }
            else
            {
                os << b.piecesBoard[i][j];
            }
        }

        os << std::endl;
    }
    return os;
}