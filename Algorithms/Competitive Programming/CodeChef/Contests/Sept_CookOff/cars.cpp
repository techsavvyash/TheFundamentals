#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        n%4 ? (cout << "YES" << endl) : (cout << "NO" << endl) ; 
    }
    return 0;
}