#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t; cin >> t ;
  while(t--) {
    ll n ;
    cin >> n ; vector<ll> arr (n+1) ; map<ll, ll> f ;
    arr[0] = -1 ;
    for(ll i = 1; i <= n; i++){
      cin >> arr[i] ;
      arr[i] -= i;
      f[arr[i]]++ ;
    }
    ll ans = 0 ;
    /* UNOPOTIMISED O(n^2) soln
    for(ll i = 1; i < n; i++) {
      for(ll j = i+1; j<=n;j++) {
        if(arr[j] == (arr[i] + j - i)) ans++ ;
      }
    }
    
    cout << ans << endl ;*/

    for(auto key: f) {
        ans += (key.second*(key.second-1))/2 ;
    }

    cout << ans << endl ;


  }
  return 0;
}
