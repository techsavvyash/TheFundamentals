#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  while(t--) {
    int n; cin >> n ;
    if(n%2 == 0) {
      int c = 2 ;
      int m = n/2 ;
      cout << (2*(m/2)) << " " << c << " " << (2*(m-(m/2)) << endl ;
    } else {
      int c ;
      
      for(int i = 3 ; i < (n/2); i++) {
        if(n%i == 0) {
          c = i ;
          break ;
        }
      }
      int q = n/c ;
      cout << c << " " << (c*(q/2)) << " " << (c*(q-(q/2))) << endl ; 


    }
  }
  return 0 ;
}
