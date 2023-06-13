#include "board.hh"
#include "kik.hh"
#include "size.hh"

#define SIZE 3

int main(int argc , char * argv[]){

    board b;
    b.printBoard();
    b.oMove(1,1);
    std::cout<<std::endl;
    b.printBoard();
    b.xMove(0,0);
    std::cout<<std::endl;
    b.printBoard();
}
