#include "test.h"
#include <iostream>

template <typename T>
void test(T poprawne, T rzeczywiste, string nazwaTestu)
{
    if (rzeczywiste == poprawne)
    {
        cout << "test " << nazwaTestu << "przeszedl PRAWIDLOWO!" << endl;
    }
    else
    {
        cout << "test " << nazwaTestu << "przeszedl NIEPRAWIDLOWO!" << endl;
    }
    return;
}

void wykonajTest()
{
    lista l;
    Klient marek("marek", "kowalski", 1111, 500);
    Klient arek("marek", "kowalski", 1111, 500);
    Klient stefan("stefan","lebski",0,1);
    test(true,l.listaPusta(),"sprawdzanie czy lista jest pusta ");
    l.dodajKlienta(marek);
    l.dodajKlienta(arek);
    l.dodajKlienta(stefan);
    test(true, marek == arek, "operatora == ");
    test(3,l.obecny->klient.liczbaKlientow,"liczby klientow na liscie ");
}