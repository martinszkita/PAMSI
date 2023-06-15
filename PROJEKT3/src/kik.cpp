#include "../inc/kik.hh"
#include "../inc/board.hh"
#include "../inc/size.hh"

kik::kik()
{
}
void kik::xMove(int x, int y)
{
    b.piecesBoard[x][y] = 'x';
}

void kik::oMove(int x, int y)
{
    b.piecesBoard[x][y] = 'o';
}

bool kik::diagonalStreak1()
{
    // diagonal streak of 1st type
    if (b.piecesBoard[0][0] != ' ')
    {
        // std::cout << "[0][0] nie jest puste!\n";
        for (int i = 0; i < SIZE; i++)
        {
            if (b.piecesBoard[i][i] != b.piecesBoard[0][0] || b.piecesBoard[i][i] == ' ')
            {
                std::cout << "nie ma diagonal streaku 1 typu!\n";
                return false;
            }
        }
        std::cout << "jest diagonal streaku 1 typu!\n";
        return true;
    }
    std::cout << "nie ma diagonal streaku 1 typu!\n";
    return false;
}

bool kik::diagonalStreak2()
{
    if (b.piecesBoard[0][SIZE - 1] != ' ')
    {
        // std::cout << "[0][SIZE-1] nie jest puste!\n";
        for (int i = 0; i < SIZE; i++)
        {
            if (b.piecesBoard[i][SIZE - 1 - i] != b.piecesBoard[0][SIZE - 1] || b.piecesBoard[i][SIZE - 1 - i] == ' ')
            {
                std::cout << "nie ma diagonal streaku 2 typu!\n";
                return false;
            }
        }
        std::cout << "jest diagonal streaku 2 typu!\n";
        return true;
    }
    std::cout << "nie ma diagonal streaku 2 typu!\n";
    return false;
}

bool kik::diagonalStreak()
{
    return ((this->diagonalStreak1() || this->diagonalStreak2()) ? true : false);
}

bool kik::verticalStreak()
{
    for (int col = 0; col < SIZE; col++)
    {
        if (b.piecesBoard[0][col] != ' ')
        {
            char player = b.piecesBoard[0][col];
            for (int row = 1; row < SIZE; row++)
            {
                if (b.piecesBoard[row][col] != player || b.piecesBoard[row][col] == ' ')
                {
                    std::cout << "nie ma pionowego streaku!\n";
                    return false;
                }
            }
            std::cout << "jest pionowy streak!\n";
            return true;
        }
    }
    std::cout << "nie ma pionowego streaku!\n";
    return false;
}

bool kik::horizontalStreak()
{
    for (int row = 0; row < SIZE; row++)
    {
        if (b.piecesBoard[row][0] != ' ')
        {
            char player = b.piecesBoard[row][0];
            for (int col = 1; col < SIZE; col++)
            {
                if (b.piecesBoard[row][col] != player || b.piecesBoard[row][col] == ' ')
                {
                    std::cout << "nie ma poziomego streaku!\n";
                    return false;
                }
            }
            std::cout << "jest poziomy streak!\n";
            return true;
        }
    }
    std::cout << "nie ma poziomego streaku!\n";
    return false;
}

bool kik::streak()
{
    return (this->diagonalStreak1() || this->diagonalStreak2() || this->verticalStreak() || this->horizontalStreak());
}

bool kik::gameOver()
{
    if (this->streak())
    {
        std::cout << "GAME OVER!" << std::endl;
        return true;
    }
    std::cout << "GAME NOT OVER!" << std::endl;
    return false;
}

void kik::play()
{
    kik plansz;
    bool whoseTurn = false;
    int xx, yy;

    while (!plansz.gameOver())
    {
        std::cout << "podaj ruch:" << std::endl;
        std::cin >> xx >> yy;
        whoseTurn ? plansz.oMove(xx, yy) : plansz.xMove(xx, yy);
        whoseTurn = !whoseTurn;
        std::cout << plansz.b;
    }
}