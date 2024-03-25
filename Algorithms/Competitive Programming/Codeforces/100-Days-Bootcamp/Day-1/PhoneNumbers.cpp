#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int count = 0 ;
    string str ;
    cin >> str;
    for(int i = 0;i<str.length();i++) {
        if(str[i] == '8') {
            count++ ;
        }
    }

    if(count > (n/11)) {
        cout << (n/11) << endl;
    } else {
        cout << count << endl ;
    }
    return 0;
}