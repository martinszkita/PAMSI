#include "../inc/kik.hh"
#include "../inc/board.hh"
#include "../inc/size.hh"
#include <cmath>

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
                // std::cout << "nie ma diagonal streaku 1 typu!\n";
                return false;
            }
        }
        // std::cout << "jest diagonal streaku 1 typu!\n";
        b.piecesBoard[0][SIZE - 1] == 'x' ? whoWon = 1 : whoWon = -1;
        return true;
    }
    // std::cout << "nie ma diagonal streaku 1 typu!\n";
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
                // std::cout << "nie ma diagonal streaku 2 typu!\n";
                return false;
            }
        }
        // std::cout << "jest diagonal streaku 2 typu!\n";
        b.piecesBoard[0][SIZE - 1] == 'x' ? whoWon = 1 : whoWon = -1;
        return true;
    }
    // std::cout << "nie ma diagonal streaku 2 typu!\n";
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
                    // std::cout << "nie ma pionowego streaku!\n";
                    return false;
                }
            }
            // std::cout << "jest pionowy streak!\n";
            player == 'x' ? whoWon = 1 : whoWon = -1;
            return true;
        }
    }
    // std::cout << "nie ma pionowego streaku!\n";
    return false;
}

bool kik::tie()
{
    bool isEmptySpace = false;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (b.piecesBoard[i][j] == ' ')
            {
                isEmptySpace = true;
            }
        }
    }
    if (!this->streak() && !isEmptySpace)
    {
        whoWon = 0;
        return true;
    }

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
                    // std::cout << "nie ma poziomego streaku!\n";
                    return false;
                }
            }
            // std::cout << "jest poziomy streak!\n";
            player == 'x' ? whoWon = 1 : whoWon = -1;
            return true;
        }
    }
    // std::cout << "nie ma poziomego streaku!\n";
    return false;
}

bool kik::streak()
{
    return (this->diagonalStreak1() || this->diagonalStreak2() || this->verticalStreak() || this->horizontalStreak());
}

bool kik::gameOver()
{
    if (this->streak() || this->tie())
    {
        // std::cout << "GAME OVER!" << std::endl;
        // std::cout<<"streak: "<<std::boolalpha<<this->streak()<<std::endl;
        // std::cout<<"tie "<<std::boolalpha<<this->tie()<<std::endl;
        // switch (whoWon)
        // {
        // case 1:
        //     std::cout << "X WON !!!\n";
        //     break;
        // case -1:
        //     std::cout << "O WON !!!\n";
        //     break;
        // case 0:
        //     std::cout << "TIE, NOBODY WON !!!\n";
        //     break;
        // default:
        //     break;
        // }
        return true;
    }
    // std::cout << "GAME NOT OVER!" << std::endl;
    return false;
}

int kik::minmax(int depth, bool isMaximizingPlayer)
{
    if (this->gameOver())
    {
        return whoWon;
    }

    if (isMaximizingPlayer)
    {
        int bestScore = -1000;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (b.piecesBoard[i][j] == ' ')
                {
                    b.piecesBoard[i][j] = 'x';
                    bestScore = std::max(bestScore, minmax(depth + 1, !isMaximizingPlayer));
                    b.piecesBoard[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
    //! isMaximizgPlayer
    else
    {
        int bestScore = 1000;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (b.piecesBoard[i][j] == ' ')
                {
                    b.piecesBoard[i][j] = 'o';
                    bestScore = std::min(bestScore, minmax(depth + 1, !isMaximizingPlayer));
                    b.piecesBoard[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
}

position kik::findBestMove()
{
    int bestScore = -1000;
    position bestMove;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (b.piecesBoard[i][j] == ' ')
            {
                b.piecesBoard[i][j] = 'x';
                int moveScore = minmax(0, false);
                b.piecesBoard[i][j] = ' ';

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestMove.x = i; // albo na odwrot, nie wiem
                    bestMove.y = j; // x =j , y = i
                }
            }
        }
    }
    return bestMove;
}
void kik::play(int mode)
{
    kik plansz;
    bool xTurn = true;
    int xx, yy;

    switch (mode)
    {
    case 1: // human vs human
        while (!plansz.gameOver())
        {
            std::cout << "podaj ruch:" << std::endl;
            std::cin >> xx >> yy;
            xTurn ? plansz.oMove(xx, yy) : plansz.xMove(xx, yy);
            xTurn = !xTurn;
            std::cout << plansz.b;
        }
        break;
    case 2: // human vs AI
    {
        bool humanMove = true;
        while (!plansz.gameOver())
        {
            if (humanMove)
            {
                std::cout << "podaj ruch:" << std::endl;
                std::cin >> xx >> yy;
                plansz.xMove(xx, yy);
            }
            else
            {
                position aiMove = plansz.findBestMove();
                plansz.oMove(aiMove.x, aiMove.y);

            }
            std::cout << plansz.b;
            std::cout << (humanMove ? "Human move:" : "AI move:") << std::endl;
            humanMove = !humanMove;
        }
        break;
    }

    default:
        std::cerr << "wrong gamemode!\n";
        return;
    }
}