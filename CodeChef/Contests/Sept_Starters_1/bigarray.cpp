#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned long long int t, n, s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        unsigned long long int sum = (n*(n+1))/2;
        if(sum > s) {
            cout << (sum - s) <<endl;
        } else {
            cout << -1 <<endl;
        }
    }
    return 0;
}