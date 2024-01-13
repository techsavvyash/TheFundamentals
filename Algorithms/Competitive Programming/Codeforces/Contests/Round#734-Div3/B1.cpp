
#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

void solve() {
  
  string str ; cin >> str ;
  map<char, ll> f ;
  
  for(ll i = 0; i < str.length(); i++) {
    f[str[i]]++ ;
  }
  ll k = 0, moreThanOne = 0, equalToOne = 0 ;
  for(auto key:f) {
    if(key.second >= 2) {
      moreThanOne++ ;
    } else if(key.second == 1) equalToOne++ ;
  }

  k += moreThanOne ;
  k += (equalToOne/2) ;

  cout << k << endl ;

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
