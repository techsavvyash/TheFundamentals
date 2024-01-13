
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ; cin >> t ;
  while(t--) {
    ll k, n, m; cin >> k >> n >> m ;
    vector<ll> a(n), b(m) ;

    for(ll i = 0; i < n; i++) {
      cin >> a[i] ;
    }
    for(ll i = 0; i < m; i++) {
      cin >> b[i] ;
    }
    
    ll i = 0, j = 0 ; vector<ll> ans ;
    bool flag = true ;
    while(i < n && j < m) {
      //cout << "i: " << i << " j: " << j << endl ; 
      if(a[i] == 0) {
        k++; ans.push_back(a[i]) ; i++ ; continue ;
      }
      if(b[j] == 0) {
        k++; ans.push_back(b[j]) ; j++ ; continue ;
      }
      if(a[i] > k && b[j] > k) {
        flag = false; break ;
      }
      if(a[i] > k) {
        if(b[j] == 0) {
          k++ ;
        }
        ans.push_back(b[j]) ; j++ ;
        continue ;
      }

      if(b[j] > k) {
        if(a[i] == 0) k++ ;
        ans.push_back(a[i]); i++ ; continue ;
      }

      if(a[i] <= k) {
        ans.push_back(a[i]); i++; continue ;
      }
      if(b[j] <= k) {
        ans.push_back(b[j]); j++; continue ;
      }
    }

    while(i < n) {
      if(a[i] == 0) k++ ;
      if(a[i] > k) {
        flag = false ; break ;
      }
      ans.push_back(a[i]); i++ ;
    }
    while(j < m) {
      if(b[j] == 0) k++ ;
      if(b[j] > k) {
        flag = false ; break ;
      }
      ans.push_back(b[j]); j++ ;
    }

    if(flag) {
      for(ll i = 0; i < n + m; i++) {
        cout << ans[i] << " " ;
      }
      cout << endl ;
    } else {
    cout << -1 << endl ;
    }

    
  }
  return 0;
}
