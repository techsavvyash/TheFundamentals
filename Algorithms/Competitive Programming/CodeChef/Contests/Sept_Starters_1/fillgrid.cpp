#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, count;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 2) {
            cout << "-1 -1" << endl <<"-1 -1" <<endl;
            continue;
        }
        for(int i = 0; i < n * n; i++){
            int r = i / n;
            int c = i % n;
            if(r == c) {
                cout << -1 << " ";
            } else if(c%n == 0) cout << endl << 1 << " ";
            else cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}