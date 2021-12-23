#include <iostream>
using namespace std;


template<typename T> class Stack {
    T *arr ;
    int capacity;
    int top;
public:
    Stack(){
        top = -1 ;
        capacity = 256;
        arr = new T[capacity]; 
    }

    Stack(int capacity) {
        this->capacity = capacity;
        top = -1;
        arr = new T[capacity] ;
    }

    void push(T val) {
        if(top < 256) {
            arr[++top] = val;
        } else {
            cout << "Overflow" << endl;
            return; 
        }
    }

    void pop() {
        if(top == -1) {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }

    T peek() {
        return arr[top] ;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }
};

int main() {

    return 0;
} 