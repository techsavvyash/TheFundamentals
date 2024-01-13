#include <iostream>
#include <climits>
using namespace std;


int main() {
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, *arr, max = INT_MIN, maxIdx;
        cin >> n;
        arr = new long long int[n];
        for(int i = 0;i<n;i++) {
            cin >> arr[i];
            if(max < arr[i]) {
                max = arr[i];
                maxIdx = i ;
            }
        }
        if(arr[n-1] == max) {
            cout << 0 << endl;
            continue ;
        } else {
            long long int maxTillNow = arr[n-1], count = 0;
            for(int i = n-2;i>=0 && arr[i] < max;i--) {
                if(arr[i] > maxTillNow) {
                    maxTillNow = arr[i];
                    count++ ;
                }
            }
            cout << count + 1 << endl;
        }
        delete[] arr ;
    }
    return 0;
}