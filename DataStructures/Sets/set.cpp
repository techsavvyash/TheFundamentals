#include <iostream>
using namespace std;

class Set { 
    int *arr;
    int currentSize, capacity;
public:
    Set() {
        arr = new int[10];
        currentSize = 0;
    }

    void insert(int val) {
        int i;
        for(i = currentSize - 1; i>=0;i--) {
            if(arr[i] > val) {
                arr[i+1] = arr[i];
            } else {break;}
        }
        arr[i+1] = val;
    }

    int* getArray() { return arr; }

};


int main() {

    Set *s = new Set();

    s->insert(1) ;
    s->insert(2) ;
    s->insert(2) ;
    s->insert(3) ;

    int *arr = s->getArray();

    for(int i=0; i<4;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}