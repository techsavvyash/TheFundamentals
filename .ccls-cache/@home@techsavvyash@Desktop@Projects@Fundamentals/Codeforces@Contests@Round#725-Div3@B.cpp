#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t ; cin >> t;
  while(t--) {
    ll n, sum = 0; cin >> n; vector<ll> arr(n) ; map<ll, ll> f; ll maxF = INT_MIN ;

    for(ll i = 0; i < n; i++) {
      cin >> arr[i] ;
      f[arr[i]]++ ;
      maxF = max(maxF, f[arr[i]]) ;
      sum += arr[i] ;
    }

    double eq = (sum*1.0)/n ;
    if(ceil(eq) != floor(eq)) {
      cout << -1 << endl ; 
      continue;
    }

    if(f[eq] == n) {
      cout << 0 << endl ;
      continue ;
    }
    

    ll cnt = 0;

    for(ll i = 0; i < n;i++) {
      if(arr[i] > eq) {
        cnt++;
      }
    }

    cout << cnt << endl;

  


  }
  return 0;
}
