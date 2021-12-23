#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, L, a, *t, *l;
    cin >> n >> L >> a;
    if(n == 0) {
        cout << (L/a) << endl;
        return 0;
    }
    t = new long long int[n];
    l = new long long int[n];
    long long int count = 0;
    cin >> t[0] >> l[0];
    for(long long int i=1;i<n;i++) {
        cin >> t[i] >> l[i] ;
        count += (t[i] - (t[i-1] + l[i-1]))/a ;
    }

    count += (L - (t[n-1] + l[n-1]))/a ;

    cout << count << endl;


    return 0;
}