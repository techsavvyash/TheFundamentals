#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, k;
        vector<long long int> v;
        cin >> n ;
        cin >> k ;
        for(int i=0;i<n;i++) {
            int el;
            cin >> el;
            v.push_back(el);
        }
        sort(v.begin(), v.end());
        long long int sum = 0, idx = 0;
        for(int i = 0 ;i<n;i++) {
            if(v[i] > 0) {
                idx = i;
                break ;
            }
        }

        int i = idx + k;
        while(i < n) {
            sum += abs(v[i - 1]);
            i += k;
        }
        i = idx - k;
        while(i > 0) {
            sum += abs(v[i]) ;
            i -= k;
        }

        if((abs(v[0]) < abs(v[n-1])) && idx != 0) {
            sum += abs(v[0]);
            cout << 2*sum + abs(v[n-1]) << endl;
        } else {
            sum += abs(v[n-1]);
            cout << (2*sum) + abs(v[0]) << endl;
        }
    }
    return 0;
}