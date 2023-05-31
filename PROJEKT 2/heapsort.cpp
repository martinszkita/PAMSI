#include <vector>
#include <iostream>
#include <iomanip>
class MaxHeap
{
private:
public:
    // Constructor
    MaxHeap();

    // Heap operations
    void insert(int value);
    int extractMax();
    void printHeap();
    void heapSort();

    // Helper functions
    void heapifyUp(int index);
    void heapifyDown(int index);
    std::vector<int> heap;
    bool isMax();
};

MaxHeap::MaxHeap() {}

void MaxHeap::heapifyUp(int index)
{
    if (index <= 1)
        return;

    int parent = (index - 1) / 2;

    if (heap[index] > heap[parent])
    {
        std::swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void MaxHeap::heapifyDown(int index)
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

void MaxHeap::printHeap()
{
    for (int value : heap)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
void MaxHeap::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
    // this->printHeap();
}

int MaxHeap::extractMax()
{
    if (heap.empty())
    {
        std::cout << "Heap is empty." << std::endl;
        return -1; // Or any appropriate handling of empty heap
    }

    int maxElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return maxElement;
}

bool MaxHeap::isMax()
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


void MaxHeap::heapSort()
{
    MaxHeap tmp;
    while (!heap.empty())
    {
        tmp.heap.push_back(this->extractMax());
    }
    this->heap = tmp.heap;
}

int main()
{
    system("clear");
    srand(time(NULL));
    MaxHeap h;
    for (int i = 0; i < 10; i++)
    {
        h.insert(rand() % 100);
    }
    h.printHeap();

    h.heapSort();
    for (int i = h.heap.size() - 1; i >= 0; i--)
    {
        std::cout << h.heap[i] << " ";
    }
}
