#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;


void solve() {
  ll n, m ;
  cin >> n >> m ;
  bool isNEven = n%2 == 0 ;
  bool isMEven = m%2 == 0 ;
  
  if(isNEven && isMEven) {
    cout << 0 << endl ;
  } else if(!isNEven && !isMEven) {
    cout << (n + m - 1) << endl ;
  } else if(!isNEven) cout << m << endl ;
  else if(!isMEven) cout << n << endl ;

  return ;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; cin >> t ;
  while(t--) {
    solve() ;
  }
  return 0;
}
