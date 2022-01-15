#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

void solve() {
  ll n, c1, c2 ; cin >> n ;
  if(n%3 == 0) {
    c1 = n/3 ;
    c2 = c1 ;
  } else if(n%3 == 1) {
    n = n - 1 ;
    c1 = (n/3) + 1 ;
    c2 = (n/3) ;
  } else if(n%3 == 2) {
  n = n-2;
  c1 = n/3 ;
  c2 = c1 + 1 ;
  }

  cout << c1 << " " << c2 << endl ;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    solve() ;
  }
  return 0; 
}
