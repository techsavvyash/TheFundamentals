#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t; 
  while(t--) {
    int n, x, y; cin >> n ;
    map<int, bool> X; map<int, bool> Y;
    int ans = 0 ;
    for(int i = 0; i < n; i++) {
      cin >> x >> y ;
      bool checkX = false, checkY = false ;
      if(!X[x]) {
        checkX = true ;
        X[x] = true ;
      }
      if(!Y[y]) {
        checkY = true ;
        Y[y] = true  ;
      }

      if(checkX && checkY) {
        ans += 2 ;
      } else if(checkX || checkY) {
        ans += 1 ;
      }
    }

    cout << ans << endl ;


    
  }
  return 0 ;
}

