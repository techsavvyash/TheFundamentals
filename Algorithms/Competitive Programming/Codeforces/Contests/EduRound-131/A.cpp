#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;


void solve() {
  int a, b, c, d ;
  cin >> a >> b >> c >> d ;
  
  if((b && c) && (a && d)) cout << 2 << endl ;
  else if(!a && !b && !c && !d) cout << 0 << endl ;
  else cout << 1 << endl ;
  
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; cin >> t ;
  while(t--) {
    solve() ;
  }

  return 0;
}
