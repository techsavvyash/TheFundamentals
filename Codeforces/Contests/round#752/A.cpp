#include <iostream>
#include <string>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long int diff = 0;
        string s;
        cin >> n ;
        long long int *arr = new long long int[n];
        for(int i = 0;i<n; i++) {
            cin >> arr[i] ;
            diff = (arr[i] - i) > diff ? (arr[i] - i) : diff ;
        }
        cout << (diff - 1) << endl;
    }
}