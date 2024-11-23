#include <iostream>
using namespace std;

class MinHeap {
    int *arr;
    int size, capacity;

    void heapify(int idx) {
        int minIdx = idx;
        int leftChild = 2*idx ;
        int rightChild = 2*idx + 1 ;

        if(leftChild <= size && arr[minIdx] > arr[leftChild]){
            minIdx = leftChild;
        }

        if(rightChild <= size && arr[minIdx] > arr[rightChild]) {
            minIdx = rightChild;
        }

        if(minIdx != idx) {
            minIdx = minIdx + idx ;
            idx = minIdx - idx ;
            minIdx = minIdx - idx ;
            heapify(minIdx) ;
        }
    }


public:
    MinHeap() {
        capacity = 16;
        size = 0;
        arr = new int[capacity] ;
        arr[0] = -1;
    }

    MinHeap(int capacity) {
        this->capacity = capacity ;
        size = 0 ;
        arr = new int[capacity] ;
        arr[0] = -1 ;
    }


    void push(int val) {
        arr[++size] = val;
    }



};


int main() {



    return 0;
}