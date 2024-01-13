#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
    long long int n;
    cin >> n;
    long long int odd = 1 ;
    for(int i = 0;i<n;i++) {
        cout << odd << " ";
        odd += 2 ; 
    }
    cout << endl ;

    }

    return 0;
}