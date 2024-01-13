#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, even[500], odd[500];
    cin >> t;
    while(t--) {
        cin >> n;
        int el, evenC = 0, oddC = 0, i, j;
        for(i=0;i<n;i++) {
            cin >> el;
            el&1 ? (odd[oddC++] = el) : (even[evenC++] = el);
        }
        if(evenC == 0 || oddC == 0) {
            cout << -1 << endl;
        } else {
            for(i=0;i<oddC;i++) {
                cout << odd[i] << " ";
            }
            for(i = 0;i<evenC;i++) {
                cout << even[i] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}