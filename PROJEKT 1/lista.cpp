#include "lista.h"
#include "klient.h"
#include <iostream>
#include "test.h"

using namespace std;

class Klient;
int Klient::liczbaKlientow;

lista::lista()
{
}

lista::~lista()
{
}

bool lista::listaPusta()
{
    if (this->glowa == nullptr)
    {
        return true;
    }
    return false;
}

void lista::dodajKlienta(Klient klijentello)
{
    ogniwoWsk noweOgniwo = new ogniwo;
    noweOgniwo->nastepny = NULL;
    noweOgniwo->klient = klijentello;

    if (glowa != NULL)
    {
        noweOgniwo->nastepny = glowa;
    }

    glowa = noweOgniwo;

    // cout << "dodano transakcje nr " << klijentello.nrTransakcji << " do listy\n";
    ++Klient::liczbaKlientow;
}

void lista::usunKlienta(unsigned int nr) // usuwanie po numerze transakcji
{
    ogniwoWsk usuwanyWsk = NULL;
    tmp = glowa;
    obecny = glowa;

    while (obecny->klient.nrTransakcji != nr && obecny->nastepny != NULL)
    {
        tmp = obecny;
        obecny = obecny->nastepny;
    }

    if (obecny->klient.nrTransakcji == nr)
    {
        usuwanyWsk = obecny;
        obecny = obecny->nastepny;
        tmp->nastepny = obecny;

        std::cout << "transakcja nr " << nr << " zostala usunieta! \n";

        delete usuwanyWsk;
    }

    else
    {
        std::cout << "transakcja nr " << nr << " nie znajduje sie na liscie!\n";
    }
    --Klient::liczbaKlientow;
}

void lista::wypiszLiczbeKlientow()
{
    cout << "obecna liczba klientow: " << this->obecny->klient.liczbaKlientow << endl;
}

void lista::wypiszListe()
{
    cout << "###Wypisywanie listy###" << endl;
    obecny = glowa;
    while (obecny != NULL)
    {
        cout << obecny->klient;
        obecny = obecny->nastepny;
    }
    cout << "########################";
}

void lista::wypiszNajstarszegoKlienta()
{
    
    tmp = glowa;
    while (tmp != NULL)
    {
        tmp = tmp->nastepny;
        if (tmp->nastepny == NULL)
        {
            cout<< tmp->klient;
        }
    }
}

void lista::wyswietlMenu()
{
    cout << endl;
    cout << "### MENU ###" << endl;
    cout << "1.Dodaj klienta na liste" << endl;
    cout << "2.Usun klienta z listy" << endl;
    cout << "3.Wyswietl liste klientow" << endl;
    cout << "4.Wyswietl najstarszego klienta" << endl;
    cout << "5.Wyswietl ilosc klientow" << endl;
    cout << "6.Wykonaj testy" << endl;
    cout << "0.Zakoncz program" << endl;
    cout << "#############" << endl;
}

void lista::oblsugaMenu(int opcja) // zamienic na int na  char  (obsluga liter)
{
    unsigned int tmp;
    Klient kl;
    system("clear");
    switch (opcja)
    {
    case 0:
        cout << "Koniec dzialania programu!" << endl;
        break;
    case 1:
        cin >> kl;
        this->dodajKlienta(kl);
        break;
    case 2:
        if (this->listaPusta())
        {
            cout << "lista jest pusta!" << endl;
            break;
        }
        cout << "Podaj nr transakcji klienta ktorego chcesz usunac: " << endl;
        cin >> tmp;
        this->usunKlienta(tmp);
        break;
    case 3:
        if (this->listaPusta())
        {
            cout << "lista jest pusta!" << endl;
            break;
        }
        this->wypiszListe();
        break;
    case 4:
        if (this->listaPusta())
        {
            cout << "lista jest pusta!" << endl;
            break;
        }
        this->wypiszNajstarszegoKlienta();
        break;
    case 5:
        this->wypiszLiczbeKlientow();
        break;
    case 6:
        wykonajTest();
        break;
    default:
        cout << "Podaj wlasciwy numer opcji: " << endl;
        break;
    }
}
