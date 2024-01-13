#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
  ios_base::sync_with_stdio(false) ; cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n, k ;
    cin >> n >> k ;
    if(n == 1 && k == 1) {cout << "R" << endl; continue ; }
    if(n%2 == 0 && k <= n/2) {
      //cout loop
      ll count = 0 ;
      for(int i = 0; i < n ;i++) {
        for(int j = 0; j < n ;j++) {
          if( i == j && i%2 == 0 && count < k) {
            cout << "R" ;
            count++ ;
          } else cout << "." ;
        }
        cout << endl ;
      }
    } else if(n%2 == 1 && k <= ((n/2) + 1)){
      //cout loop
      ll count = 0;
      for(int i = 0;i < n; i++) {
        for(int j = 0; j < n ; j++) {
          if(i == j && i%2 == 0 && count < k) {
            cout << "R" ;
            count++ ;
          } else cout << "." ;
        }
        cout << endl ;
      }
    } else {
    cout << -1 << endl ;
    }

    
  }

  return 0;
}
