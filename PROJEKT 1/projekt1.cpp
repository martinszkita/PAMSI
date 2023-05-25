#include <iostream>
#include "lista.h"
#include "test.h"
#include "klient.h"

using namespace std;

int main()
{
    int wybor;
    lista l;
 
    do
    {
        l.wyswietlMenu();
        std::cin >> wybor;
        l.oblsugaMenu(wybor);

    } while (wybor != 0);
}