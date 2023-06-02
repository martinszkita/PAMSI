#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "film.h"

template <typename T>
class MaxHeap
{
private:
    // Helper functions
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Constructor
    MaxHeap();
    std::vector<T> heap;
    // Heap operations
    void insert(T value);
    T extractMax();
    void printHeap();
    void heapSort();
    bool isMax();
    // T getHeap() const;
    // void setHeap(vector<T> tmp);
};

template <typename T>
MaxHeap<T>::MaxHeap() {}

template <typename T>
void MaxHeap<T>::heapifyUp(int index)
{
    if (index < 1)
        return;

    int parent = (index - 1) / 2;

    if (heap[index] > heap[parent])
    {
        std::swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

template <typename T>
void MaxHeap<T>::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        largest = leftChild;

    if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        largest = rightChild;

    if (largest != index)
    {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

template <typename T>
void MaxHeap<T>::printHeap()
{
    for (T tmp : heap)
    {
        std::cout << tmp << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MaxHeap<T>::insert(T value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
    // printHeap();
}

template <typename T>
T MaxHeap<T>::extractMax()
{
    if (heap.empty())
    {
        std::cout << "Heap is empty, can't extract max element!" << std::endl;
        return T();
    }

    T maxElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return maxElement;
}

template <typename T>
bool MaxHeap<T>::isMax()
{
    for (int i = 1; i < heap.size(); i++)
    {
        int parent = (i - 1) / 2;
        if (heap[i] > heap[parent])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void MaxHeap<T>::heapSort()
{
    if (!this->isMax())
    {
        cout << "the heap is not a max heap, cant sort sorry!\n";
        return;
    }

    MaxHeap<T> tmp;
    while (!heap.empty())
    {
        // cout<<extractMax()<<endl;
        tmp.heap.push_back(extractMax());
    }
    heap = tmp.heap;
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int dataQuantity = stoi(argv[1]);
    string fname = "dane.csv";
    vector<film> filmy;
    vector<string> row;
    string line;
    string word;
    MaxHeap<film> h;




    /*deklaracja pliku wejsciowego*/
    fstream file(fname, ios::in);

    if (file.is_open())
    { // jesli udalo sie otworzyc plik
        /*dla kazdego wiersza z pliku zapisuje do jednej linijki*/
        int ktorePole;
        int _nr;
        float _rating;
        string _name;

        for (int nrWiersza = 0; nrWiersza < dataQuantity && (getline(file, line)); nrWiersza++)
        {
            ktorePole = 0;
            row.clear();
            stringstream stream(line);

            while (getline(stream, word, ','))
            {
                // cout<<"ktore pole: "<<ktorePole<<" word to teraz: "<<word<<endl;
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
                    // filmy.push_back(*tmp);
                    h.insert(*tmp);

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

    // jest vector obiektow typu film elegancko
    cout << "before heapsort: \n";
    for (int i = 0; i < filmy.size(); i++)
    {
        cout << filmy[i];
    }

    
    // h.heap = filmy;
    h.printHeap();
    h.heapSort();

    cout << "after heapsort:\n";
    h.printHeap();
}
