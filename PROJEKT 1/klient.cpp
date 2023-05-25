#include "klient.h"
#include <iostream>

using namespace std;

Klient::Klient(string _imie, string _nazwisko, unsigned int _nrTransakcji, float _kwota)
{

    this->imie = _imie;
    this->nazwisko = _nazwisko;
    this->nrTransakcji = _nrTransakcji;
    this->kwota = _kwota;
}

Klient::Klient()
{
}

Klient::~Klient()
{
}

ostream &operator<<(ostream &wyjscie, Klient &klientello)
{
    wyjscie << endl;
    wyjscie << "Imie klienta: " << klientello.imie;
    cout << endl;
    wyjscie << "Nazwisko klienta: " << klientello.nazwisko;
    cout << endl;
    wyjscie << "Numer transakcji: " << klientello.nrTransakcji;
    cout << endl;
    wyjscie << "Kwota transakcji [PLN]: " << klientello.kwota;
    cout << endl;

    return wyjscie;
}

istream &operator>>(istream &wejscie, Klient &klientello)
{

    cout << "Imie klienta: ";
    wejscie >> klientello.imie;
    cout << "Nazwisko klienta: ";
    wejscie >> klientello.nazwisko;
    cout << "Numer transakcji: ";
    wejscie >> klientello.nrTransakcji;
    cout << "Kwota transakcji [PLN]: ";
    wejscie >> klientello.kwota;

    return wejscie;
}

void Klient::wypiszKlienta()
{
    cout << "#########################" << endl;
    cout << "Imie klienta: " << this->imie << endl;
    cout << "Nazwisko klienta: " << this->nazwisko << endl;
    cout << "Numer transakcji: " << this->nrTransakcji << endl;
    cout << "Kwota transakcji [PLN]: " << this->kwota << endl;
    cout << "#########################" << endl;
}

bool Klient::operator==(Klient drugi)
{
    if (drugi.imie != this->imie || drugi.nazwisko != this->nazwisko || drugi.nrTransakcji != this->nrTransakcji || drugi.kwota != this->kwota)
    {
        return false;
    }
    return true;
}