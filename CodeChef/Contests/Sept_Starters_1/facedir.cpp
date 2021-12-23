#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int rem = n%4;
        switch (rem)
        {
        case 0:
            cout << "North" << endl;
            break;
        case 1:
            cout << "East" << endl;
            break;
        case 2:
            cout << "South" << endl;
            break;
        case 3:
            cout << "West" << endl;
            break;
        default:
            break;
        }
    }
} 