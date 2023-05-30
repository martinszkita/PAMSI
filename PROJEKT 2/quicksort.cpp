#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "film.h"

using namespace std;

void quickSort(vector<film> &arr, int L, int P)
{
    if (P > L)
    {
        int i = L;
        int j = L;
        int pivot = P;

        while (j < pivot)
        {
            if (arr[j].rating <= arr[pivot].rating)
            {
                swap(arr[i], arr[j]);
                i++;
            }
            j++;
        }
        swap(arr[i], arr[j]);
        quickSort(arr, L, i - 1);
        quickSort(arr, i + 1, P);
    }
}

int main(int argc, char *argv[])
{
    // system("clear");
    int size =stoi(argv[1]);
    string fname = "dane.csv";
    vector<film> filmy;
    vector<string> row;
    string line;
    string word;
    fstream file(fname, ios::in);

    if (file.is_open())
    { // jesli udalo sie otworzyc plik
        /*dla kazdego wiersza z pliku zapisuje do jednej linijki*/
        int ktorePole;
        int _nr;
        float _rating;
        string _name;

        for (int nrWiersza = 0; nrWiersza < size && (getline(file, line)); nrWiersza++) // zczytuje wiersze
        {
            ktorePole = 0;
            stringstream stream(line);

            while (getline(stream, word, ',')) // zczytuje linie
            {
                switch (ktorePole)
                {
                case 0:
                    _nr = stoi(word);
                    break;
                case 1:
                    _name = word;
                    break;
                case 2:
                {
                    _rating = stof(word);
                    film *tmp = new film(_nr, _name, _rating);
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

    cout << "\nprzed sortowaniem: \n\n";
    for (int i = 0; i < filmy.size(); i++)
    {
        cout << filmy[i];
    }

    quickSort(filmy, 0, size - 1);

    cout << "\npo sortowaniu: \n\n";
    for (int i = 0; i < filmy.size(); i++)
    {
        cout << filmy[i];
    }
}