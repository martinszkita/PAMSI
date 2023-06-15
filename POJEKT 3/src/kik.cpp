#include "kik.hh"
#include "board.hh"
#include "size.hh"

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
// bool kik::streak()
// {
//     bool streak = false;
//     // vertically
//     for (int i = 0; i < SIZE; i++)
//     {
//         for (int j = 0; j < SIZE; j++)
//         {
//         }
//     }
// }
// bool kik::gameOver()
// {
//     // all squares on the board full
//     if ()
// }

void kik::play()
{
    kik plansz;
    bool whoseTurn = false;
    int xx, yy;

    while (1)
    { // dodac potem while !gameOver()
        std::cout << plansz.b;
        std::cout << "podaj ruch:" << std::endl;
        std::cin >> xx >> yy;
        whoseTurn ? plansz.oMove(xx, yy) : plansz.xMove(xx,yy);
        whoseTurn =!whoseTurn;
    }
}