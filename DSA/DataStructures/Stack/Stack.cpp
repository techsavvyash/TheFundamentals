#include <iostream>
using namespace std;


template<typename T> class Stack {
    T *arr ;
    int capacity;
    int top;
    int _size ;
public:
    Stack(){
        top = -1 ;
        capacity = 256;
        arr = new T[capacity]; 
        _size = 0 ;  
    }

    Stack(int capacity) {
        this->capacity = capacity;
        top = -1;
        arr = new T[capacity] ;
        _size = 0 ;
    }


    void push(T val) {
        if(top < 256) {
            arr[++top] = val;
            _size++ ;
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
        _size--;
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
    
    int size() {
      return _size ;
    }

  
};

int main() {
  Stack<int> s;
  s.push(25);
  s.push(54);
  s.push(75);

  cout << s.isEmpty() << endl ;
  cout << s.peek() << endl;
  for(int i = 0; i < s.size(); i++) {
    cout << s.peek() << " ";
    s.pop() ;
  } cout << endl ;


    return 0;
} 
