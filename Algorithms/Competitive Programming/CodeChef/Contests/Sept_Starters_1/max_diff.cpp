#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        if(n >= s) {
            cout << s << endl;
        } else {
            cout << abs(s - (2*n)) << endl;
        }
    }
    return 0;
}