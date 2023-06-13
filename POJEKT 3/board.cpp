#include "board.hh"

board::board()
{
    int i = 0;
    int j;
    for (; i <  SIZE ; i++)
    {
        j = 0;
        for (; j < 2 * SIZE - 1; j++)
        {
            if (j % 2 != 0)
            {
                std::cout << "drukuje kreche na " << j << "-tym miejscu w " << i << "-tym wierszu\n";
                piecesBoard[i][j] = '|';
            }
            else{
                piecesBoard[i][j] = ' ';
            }
        }
    }
}
void board::printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 2 * SIZE - 1; j++)
        {
            std::cout << piecesBoard[i][j];
        }
        std::cout << std::endl;
    }
}
void board::xMove(int x, int y) {
    piecesBoard[x][2*y]='x';
}

void board::oMove(int x, int y) {
    piecesBoard[x][2*y]='o';
}