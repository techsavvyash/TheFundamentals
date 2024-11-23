#include <iostream>
using namespace std;

template<typename T> class Queue {
    T *arr;
    int capacity, front, end;
public:
    Queue() {
        capacity = 256;
        front = end = -1;
        arr = new T[capacity] ;    
    }

    Queue(int capacity) {
        this->capacity = capacity ;
        front = end = -1;
        arr = new T[capacity] ;
    }

    void push(T val) {
        if(end != 255){ 
            arr[++end] = val;
        } else {
            cout << "Overflow" << endl;
            return ;
        }

        if(front == -1) ++front;
    }

    void pop() {
        if(front == -1) {
            cout << "Underflow" << endl;
            return;
        }
        if(front == end) {
            front = end = -1;
            return ;
        }

        ++front ;
    }

    void isEmpty() {
        if(front == -1 && end == -1) {
            return true;
        }
        return false;
    }

    T peek() {
        return arr[front] ;
    }
};

int main() {

    return 0;
} 