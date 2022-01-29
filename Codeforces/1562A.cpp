#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  while(t--) {
    int l, r; cin >> l >> r ;
    if(r < 2*l) {
      cout << r - l << endl ;
    } else 
    cout << (r-1)/2 << endl ;
  }

  return 0;
} 
