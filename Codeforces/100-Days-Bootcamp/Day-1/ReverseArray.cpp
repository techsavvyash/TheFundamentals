#include <iostream>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int *arr = new long long int[n] ;
    for(int i=0;i<n;i++) {
        cin >> arr[i] ;
    }

    for(int i=0;i<n/2;i++) {
        swap(arr[i], arr[n - 1-i]);
    }

    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}