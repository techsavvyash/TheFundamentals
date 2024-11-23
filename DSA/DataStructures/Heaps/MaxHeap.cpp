#include <iostream>
using namespace std;
class MaxHeap {
    int *arr ;
    int size, capacity ;

    void heapify(int idx) {
        int maxIdx = idx ;
        int leftChild = 2*idx ;
        int rightChild = 2*idx + 1 ; 

        if(leftChild <= size && arr[maxIdx] < arr[leftChild]) {
            maxIdx =  leftChild ;
        } 
        
        if(rightChild <= size && arr[maxIdx] < arr[rightChild]) {
            maxIdx = rightChild ;
        } 

        if(maxIdx != idx) {
            swap(arr[idx], arr[maxIdx]) ;
            heapify(maxIdx);
        }
    }

public:
    MaxHeap() {
        capacity = 16;
        size = 0;
        arr = new int[capacity] ;
        arr[0] = -1;
    }    

    MaxHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
        arr[0] = -1;
    }

    void push (int val) {
        if(size == capacity) {
            int *newArr = new int[capacity = 2*capacity] ;
            for(int i=1;i<=size;i++) {
                newArr[i] = arr[i];
            }

            arr = newArr ;
        }

        arr[++size] = val ;
        int idx = size;
        int parent = idx / 2 ;

        while(idx > 1 && arr[parent] < arr[idx] ) {
            arr[parent] = arr[parent] + arr[idx];
            arr[idx] = arr[parent] - arr[idx];
            arr[parent] = arr[parent] - arr[idx];

            idx = parent;
            parent = idx / 2;
        }
    }

    int top() {
        return arr[1];
    }

    void pop() {
        /*In a heap popping can take place only via the root*/
        for(int i=1;i<=size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        cout << arr[1] << " ";
        int temp = arr[1] ;
        arr[1] = arr[size] ;
        arr[size] = temp ;
        
        size-- ;
        heapify(1);
    }

    int getSize() { return size; }

};

int main() {

    MaxHeap *m = new  MaxHeap();
    
    for(int i = 0 ; i < 10;i++) {
        m->push(i+1);
    }
    
    for(int i=0;i<10;i++) {
        m->pop();
    }
    cout << endl;

    return 0;
}