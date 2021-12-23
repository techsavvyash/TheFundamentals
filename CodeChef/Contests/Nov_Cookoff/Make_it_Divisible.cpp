#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int n;
        cin >> n;
        long long int *arr = new long long int[n];
        vector<int> rem1;
        vector<int> rem2;
        for(long long int i=0;i<n;i++) {
            cin >> arr[i] ;
            if(arr[i]%3 == 1) rem1.push_back(i) ;
            else if(arr[i]%3 == 2) rem2.push_back(i) ;
        }
        
        int one = rem1.size() ;
        int two = rem2.size() ;

        if(one == two) {
            cout << one << endl ;
        } else if((n - abs(one - two)) % 2 == 0 && (n != (one + two)) ) {
            cout <<  (one > two ? one : two) << endl ;
        } else { 
            cout <<  -1 << endl ;
        }
    }
     
    
    
    return 0;
}