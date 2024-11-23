#include <iostream>
using namespace std;
//prob code : MAKEPAL
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, *arr, numOdd = 0;
        cin >> n;
        arr = new long long int[n] ;
        for(int i=0;i<n;i++) {
            cin >> arr[i] ;
            if(arr[i]&1) numOdd++ ;
        }
        if(numOdd > 0) {
            cout << numOdd/2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}