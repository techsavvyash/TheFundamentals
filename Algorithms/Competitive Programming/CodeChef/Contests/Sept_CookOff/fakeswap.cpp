#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        string s, p;
        cin >> s;
        cin >> p;
        int same = 0, diff = 0, p1 = 0, p0 = 0;
        for(int i=0;i<n;i++) {
            int xorr = (s[i]-'0')^(p[i]-'0');
            xorr ? diff++ : same++ ;
            if(p[i] == '1') p1++;
             int xorr = (s[i]-'0')^(p[i]-'0');
            xorr ? diff++ : same++ ;
            if(p[i] == '1') p1++;
            else p0++;
        }  
        if(same == n) {
            cout << "YES" <<endl;
            continue;
        }
        if(p1 > 0 && p0 > 0) {
            cout << "YES" <<endl;
        } else {
            cout << "NO" <<endl;
        }
    }
    return 0;
}


