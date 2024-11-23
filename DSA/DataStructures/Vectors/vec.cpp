#include <iostream>
using namespace std;

template<typename T>
class Vector {
    T *arr;
    int currentSize, capacity ;

public:
    Vector() {
        arr = new T[capacity = 2] ;
        currentSize = 0;
    }

    Vector(int capacity) {
        this->capacity = capacity ;
        arr = new T[capacity];
        currentSize = 0;
    }

    void insert(T val) {
        if(currentSize == capacity) {
            T *newArr = new T[2*capacity] ;
            for(int i=0;i<currentSize;i++) {
                newArr[i] = arr[i];
            }
            capacity = 2*capacity ;
            arr = newArr ;
        }

        arr[currentSize++] = val;
    }

    int getSize() {return currentSize ;}

    int getCapacity() {return capacity;}
    
    T* getArray() { return arr ;}

};


int main() {

    Vector<int> *v = new Vector<int>() ;

    for(int i=0;i<10;i++) {
        v->insert(i+1);
    }

    int* arr = v->getArray() ;

    for(int i=0;i<10;i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "size: " << v->getSize() << " capacity: " << v->getCapacity() << endl;

    return 0;
}