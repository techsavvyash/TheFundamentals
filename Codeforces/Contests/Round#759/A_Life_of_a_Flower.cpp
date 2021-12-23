#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, *arr;
        cin >> n;
        arr = new long long int[n];
        cin >> arr[0] ;
        bool flag = false ;
        long long int height = 1;
        if(arr[0] == 1) height++ ;
        for(int i = 1;i<n;i++) {
            cin >> arr[i] ;
            if(arr[i] == 0 && arr[i-1] == 0) {
                flag = true ;
            } else if(arr[i] == 1 && arr[i-1] == 1) {
                height += 5;
            } else if(arr[i] == 1 && arr[i-1] != 1) {
                height++ ;
            }
            
        }
        if(flag) {
            cout << -1 << endl;
            continue ;
        } else {
            cout << height << endl;
        }
        delete[] arr;
    }
    return 0;
}