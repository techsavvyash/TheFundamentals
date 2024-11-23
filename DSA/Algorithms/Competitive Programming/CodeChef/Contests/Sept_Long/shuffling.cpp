#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>> t;
    while(t--) {
        int n, oddCount = 0, evenCount = 0, odd, even;
        long long int arr[100010];
        cin >> n;

        even = odd = n/2;
        if(n&1) odd++;

        for(int i=0;i<n;i++) {
            cin >> arr[i];
            if(arr[i]&1) oddCount++;
            else evenCount++;
        }

        if(evenCount == odd) {
            cout << n <<endl;
        } else if(evenCount < odd) {
            cout << (even + evenCount) << endl;
        } else if(evenCount > odd) {
            cout << (odd + oddCount) << endl;
        }
    }
    
    return 0;
}