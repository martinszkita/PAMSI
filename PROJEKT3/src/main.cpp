#include "../inc/board.hh"
#include "../inc/kik.hh"
#include "../inc/size.hh"
#include <iostream>

int main(int argc, char *argv[])
{
   kik k;
   int mode;

   std::cout << "Choose gameMode:\n";
   std::cout << "1.human vs human\n";
   std::cout << "2.human vs smart AI\n";
   std::cout << "3.human vs random AI\n";
   std::cout << "4.smart AI vs smart AI\n";
   std::cin >> mode;
   system("clear");
   std::cout << k.b << std::endl;
   k.play(mode);
   return 0;
}
