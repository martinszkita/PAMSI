#include <vector>
#include <iostream>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper functions
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Constructor
    MaxHeap();

    // Heap operations
    void insert(int value);
    int extractMax();
    void printHeap();
    void heapSort();
};

MaxHeap::MaxHeap() {}

void MaxHeap::heapifyUp(int index) {
    if (index <= 1)
        return;

    int parent = index / 2;

    if (heap[index] > heap[parent]) {
        std::swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int largest = index;

    if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        largest = leftChild;

    if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        largest = rightChild;

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int MaxHeap::extractMax() {
    if (heap.empty()) {
        std::cout << "Heap is empty." << std::endl;
        return -1; // Or any appropriate handling of empty heap
    }

    int maxElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return maxElement;
}

void MaxHeap::printHeap() {
    for (int value : heap) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void MaxHeap::heapSort(){
    
}



int main() {
    MaxHeap maxHeap;
    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(3);
    maxHeap.insert(8);

    maxHeap.printHeap();

}
