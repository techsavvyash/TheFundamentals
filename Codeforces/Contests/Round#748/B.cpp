#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        unsigned long long int n ;
        cin >> n;
        if((n%100)%25 == 0) {
            cout << 0 << endl;
            continue;
        } else {
            int arr[20], idx;
            for(int i = 0; n!= 0;i++) {
                arr[i] = n%10;
                n /= 10;
                if(arr[i] == 5 || arr[i]) {
                    
                }
            }
        }
    }

    return 0;
}