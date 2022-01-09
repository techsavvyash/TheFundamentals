
#include <climits>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ; cin >> t ;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k), t(k) ;
    for(ll i = 0; i < k ; i++) {
      cin >> a[i] ;
    }
    ll minT = LONG_LONG_MAX;
    for(ll i = 0; i < k ; i++) {
      cin >> t[i] ;
      minT = min(minT, t[i]) ;
    }
    
    vector<ll> ans(n) ;


  }
  return 0;
}
