#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, a, b;
        cin >> n >> a >> b;

        if(a > ((n/2) + 1)) {
            cout << -1 << endl;
            continue ;
        }

        if(b < n/2) {
            cout << -1 << endl ;
            continue ;
        }

        // if((b-1)<((n/2) - 1)) {
        //     cout << -1 <<endl;
        //     continue ;
        // }

        // if((n-a) < ((n/2) - 1)) {
        //     cout << -1 << endl;
        //     continue ;
        // }

        int count = 1, i = a+1;
        cout << a << " ";
        while(count != n/2) {
            if(i == b) {
                i++;
                continue ;
            } 
            cout << i++ << " ";
            count++ ;
        }
        cout << b << " ";
        i = b-1, count = 1;
        while(count != n/2) {
            if(i == a) {
                i++;
                continue ;
            }

            cout << i++ << " ";
            count++ ;
        }
        cout << endl;

    }
    return 0;
} 