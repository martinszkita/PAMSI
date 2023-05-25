#pragma once
#include <string>

using namespace std; // std::string

class Klient
{
public:
    Klient(string _imie, string _nazwisko, unsigned int _nrTransakcji, float _kwota);
    Klient();
    ~Klient();
    string imie;
    string nazwisko;
    unsigned int nrTransakcji;
    float kwota;
    static int liczbaKlientow;
    void wypiszKlienta();
    void wypiszLiczbeKlientow();
    bool operator==(Klient drugi);
};

ostream &operator<<(ostream &wyjscie, Klient &klientello);
istream &operator>>(istream &wejscie, Klient &klientello);
