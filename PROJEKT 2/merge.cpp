#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <cstring>
#include "film.h"

using namespace std;

void merge(vector<film> &filmyVector, int left, int right, int mid)//int array[] --> vector <filmy>
{
    // rozmiary prawej i lewej podtablicy
    auto leftSize = mid - left + 1;
    auto rightSize = right - mid;

    // alokacja pamieci na lewa i prawa podtablice
    auto *leftArray = new film[leftSize];
    auto *rightArray = new film[rightSize];

    // wypelnienie obu podtablic
    for (int i = 0; i < leftSize; i++)
    { // left sie bedzie potem przesuwac, dlatego jest w ideksie oryginalnej tablicy
        leftArray[i] = filmyVector[left + i];
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = filmyVector[mid + 1 + j];
    }

    // wyzerowanie starych zamiast inicjacja nowych zmiennych
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = left;

    /*porownywanie kolejnych elementow obu podtablic
    i przypisywanie mniejszego za kazdym razem do pierwotnej tablicy*/
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        /*jesli liczba w lewej tablicy mniejsza
        wpisac ja do glownej*/
        if (leftArray[leftIndex].rating <rightArray[rightIndex].rating)
        {
            filmyVector[mergedIndex] = leftArray[leftIndex];
            //cout<<leftArray[leftIndex].rating <<"<"<<rightArray[rightIndex].rating<<endl;
            /*liczba z lewej podtablicy zostaje wpisana
            do glownej tablicy wiec przesuwamy wskaznik
            w lewej zeby zaczac porownywac kolejna liczbe*/
            leftIndex++;
        }
        else
        {
            filmyVector[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        /*Tak czy siak jakas liczba zostanie wpisana
        do glownej tablicy przesuwamy wskaznik
        na kolejne nieposortowane jeszcze miejce*/
        mergedIndex++;
    }
    /*teraz indeks jednej podtablicy musi dojsc do konca,
    czyli tablica jest jakby zuzyta,

    dlatego dopisujemy pozostale elementy juz posortowane
    do glownej tablicy (ktoras petla sie nie wykona)
    */

    while (leftIndex < leftSize)
    {
        filmyVector[mergedIndex] = leftArray[leftIndex];
        mergedIndex++;
        leftIndex++;
    }

    while (leftIndex < leftSize)
    {
        filmyVector[mergedIndex] = leftArray[leftIndex];
        mergedIndex++;
        leftIndex++;
    }

    /*zwalniamy pamiec na niepotrzebne juz podtablice*/
    // delete[] leftArray;
    // delete[] rightArray;
}

void mergeSort(vector <film> &array, int left_begin, int right_end)//int array[]
{
    // przypadek bazowy
    if (left_begin >= right_end)
    {
        return;
    }
    int mid = (left_begin + right_end) / 2;
    mergeSort(array, left_begin, mid);
    mergeSort(array, mid + 1, right_end);
    merge(array, left_begin, right_end, mid);
}


int main(int argc, char *argv[])
{

    int dataQuantity = stoi(argv[1]);
    string fname = "dane.csv";
    vector<film> filmy;
    vector<string> row;
    string line;
    string word;

    /*deklaracja pliku wejsciowego*/
    fstream file(fname, ios::in);

    if (file.is_open())
    { // jesli udalo sie otworzyc plik
        /*dla kazdego wiersza z pliku zapisuje do jednej linijki*/
        int ktorePole;
        int _nr;
        float _rating;
        string _name;
        
        for (int nrWiersza = 0; nrWiersza< dataQuantity && (getline(file, line)); nrWiersza++)
        {
            ktorePole = 0;
            row.clear();
            stringstream stream(line);

            while (getline(stream, word, ',')){
                // cout<<"ktore pole: "<<ktorePole<<" word to teraz: "<<word<<endl;
                switch(ktorePole){
                    case 0:
                        _nr = stoi(word);
                        break;
                    case 1:
                        _name = word;
                        break;
                    case 2:{
                        _rating = stof(word);
                        film* tmp = new film(_nr, _name, _rating);
                        filmy.push_back(*tmp);
                        break;
                    }
                    default:
                        ktorePole = -1;
                        break;
                }
                ktorePole++;
            }
        }
    }

    else
    {
        cout << "Could not open the file !\n";
    }

    //jest vector obiektow typu film elegancko
    cout<<"przed sortowaniem: \n";
    for (int i = 0; i < filmy.size(); i++)
    {
        cout << filmy[i];
    }
   
    mergeSort(filmy, 0, filmy.size() - 1);
    
    cout<<"po sortowaniu:\n";
    for (int i = 0; i < filmy.size(); i++)
    {
        cout << filmy[i];
    }

    

}
