#pragma once
#include "film.h"
#include <iostream>

using namespace std;

film::film(){}

film::film(int _nr, string _name, float _rating)
    {
        nr = _nr;
        rating = _rating;
        name = _name;
    }

ostream &operator<<(ostream &out, const film &_film)
{  
    out<<_film.nr<<", "<<_film.name<<", "<<_film.rating<<endl;
    return out;
}

istream &operator>>(istream &in, film &_film){
    in>>_film.nr>>_film.name>>_film.rating;
    return in;
}