#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxVal(long long int n, long long int a, long long int b, long long int &maxV) {
    //base case
    if(n == 1) {
        return maxV ;
    }

    long long int op1 = n&1 ? b : a ;
    long long int idx;
    for(long long int i=n/2;i>=2;i++) {
        if(n%i == 0) {
            idx = i;
            break;
        }
    }
    maxV = maxV + (idx&1 ? b : a) ;
    if(maxV < op1) maxV = op1 ;
    n = n/idx ;
    cout << "n: " << n << endl;
    return maxVal(n, a, b, maxV) ;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long int n, a, b;
        cin >> n >> a >> b;
        long long int maxV = 0 ;
        cout << maxVal(n, a, b, maxV) << endl;
    }
    return 0;
}