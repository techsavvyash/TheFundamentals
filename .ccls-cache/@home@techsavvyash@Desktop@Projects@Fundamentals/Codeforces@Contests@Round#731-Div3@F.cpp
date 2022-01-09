#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t ;
  cin >> t ;
  while(t--) {
    ll n; cin >> n;
    vector<ll> a(n) ;
    bool flag = true ; cin >> a[0] ;
    for(ll i = 1; i < n; i++) {
      cin >> a[i] ;
      if(a[i] != a[i-1]) flag = false ;
    }


    

  }
  return 0;
}
