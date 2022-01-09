#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t; cin >> t ;
  while(t--) {
    ll n, l, r; cin >> n >> l >> r ;
    vector<ll> a(n) ;
    
    for(ll i = 0; i < n; i++) {
      cin >> a[i] ;
    }

    sort(a.begin(), a.end()) ;
    ll ans = 0 ;
    
    for(ll i = 0; i < n;i++) {
      ans += upper_bound(a.begin(), a.end(), r - a[i]) - a.begin() ;
      ans -= lower_bound(a.begin(), a.end(), l - a[i]) - a.begin() ;
      if (l <= 2 * a[i] && 2 * a[i] <= r) {
        ans--;
      }
    }

    cout << ans/2 << endl ;



  }
  return 0;
}
