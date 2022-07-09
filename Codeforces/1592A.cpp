#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  while(t--) {
    int n, h ; cin >> n >> h ;

    vector<int> v(n) ;
    int m = 0, smin = 0 ;
    for(int i = 0; i < n; i++) {
      cin >> v[i] ;
      m = (v[m] > v[i] ? m : i) ;
    }
    
    for(int i = 1; i < n ; i++) {
      if(v[i] > v[smin] && i != m) {
        smin = i ;
      }
    }
    
    int ans = 0, i = 0 ;
    while(h > 0) {
      if(i == 0) {
        h -= v[m] ;
      } else if(i == 1) {
        h -= v[smin] ;
      } 
      i = (i+1)%2 ;
      ans++ ;
    }

    cout << ans << endl ;

  }
  return 0 ;
}
