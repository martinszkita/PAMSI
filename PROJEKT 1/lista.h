#pragma once
#include <string>
#include "klient.h"

using namespace std;

class lista
{
    public:
        typedef class ogniwo
        {
            public:               // struktura do przechowywania ogniwa (node)
                Klient klient;    // pole do przechowywania danych
                ogniwo *nastepny;// wskaznik na nastepne ogniwo
        } *ogniwoWsk;         // ogniwo * ---> ogniwoWsk

        ogniwoWsk obecny;
        ogniwoWsk glowa;
        ogniwoWsk tmp;

        lista();
        ~lista();
        void dodajKlienta(Klient klientello);
        void usunKlienta(unsigned int nr);
        void wypiszListe();
        void wypiszLiczbeKlientow();
        void wypiszNajstarszegoKlienta();
        void wyswietlMenu();
        void oblsugaMenu(int opcja);
        bool listaPusta(); 
};