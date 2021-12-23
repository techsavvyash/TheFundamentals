#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t, n, k, arr[100000], ar[100000], zero = 0, sum = 0, second = 0;
    cin >> t;
    while(t--) {
        second = 0; zero = 0; sum = 0;
        cin >> n >> k;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            ar[i] = arr[i];
            if(arr[i] == 0) zero++;
            sum += arr[i];
        }
        if(k == 0){
            cout << sum << endl;
            continue;
        }
        while(second < k && zero != 0 ) {
            long long int temp = 0; 
            sum = 0;
            for(int i=1;i<n-1;i++) {
                if(arr[i]!=0){
                    ar[i-1]++;
                    ar[i+1]++;
                }
            }
            if(arr[0]!=0) {ar[n-1]++; ar[1]++;}
            if(arr[n-1]!=0) {ar[n-2]++; ar[0]++;}
            for(int i=0;i<n;i++) {
                arr[i] = ar[i];
                if(arr[i] == 0) temp++;
                sum += arr[i];
            }
            zero = temp;
            second++;
        }
        (sum == k) ? (cout << sum << endl) : (cout << sum + (k-second)*2*n << endl) ;   
    }

    delete[] arr;
    return 0;
}