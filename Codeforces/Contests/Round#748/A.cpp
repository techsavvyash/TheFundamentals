#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long int arr[3];
        int same = 0;
        for(int i=0;i<3;i++) {
            cin >> arr[i] ;
            for(int j = 0;j<i;j++) {
                if(arr[i] == arr[j]) same = arr[i] ;
            }
        }
        long long int addn = max(arr[0], max(arr[1], arr[2]));
        if(same == addn) {
            for(int i=0;i<3;i++) {
                if(addn == arr[i]) {
                    cout << 1 << " ";
                    continue;
                }
                cout << (addn - arr[i]) + 1 << " ";
            }
            cout << endl;
        } else {    
            for(int i=0;i<3;i++) {
            if(addn == arr[i]) {
                cout << 0 << " ";
                continue;
            }
            cout << (addn - arr[i]) + 1 << " ";
        }
            cout << endl;
        }
        
    }
} 