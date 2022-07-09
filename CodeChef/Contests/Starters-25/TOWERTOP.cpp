#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  while(t--) {
    ll x; cin >> x;
    unsigned long long int m; cin >> m ;
    if(m == 0) {
      cout << 0 << endl ;
      continue ;
    }
    cout << log2(x) << endl ;
    int ops = ceil(log2(x)) ;
    cout << m - ops << endl ;
  }


  return 0 ;
}
