#pragma once
#include <iostream>
using namespace std;

class film
{
public:
    int nr;
    float rating;
    string name;
    film();
    film(int _nr, string _name, float _rating);
};

ostream &operator<<(ostream &out, const film &_film);
istream &operator>>(istream &in,film &_film);
