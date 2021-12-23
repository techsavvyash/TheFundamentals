#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int *arr = new int[100];
    int count = 0;
    for(int i=0;i<str.length();i++) {
        if(str[i] != '+') {
            arr[count++] = str[i] - '0' ;
        }
    }

    sort(arr, arr + count);

    for(int i = 0; i <count - 1;i++) {
        cout << arr[i] <<"+";
    }
    cout << arr[count-1];

    return 0;
}