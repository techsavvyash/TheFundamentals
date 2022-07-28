#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;


void solve() {
  ll n, m;
  cin >> n >> m ;
  vector<pair<ll, ll>> arr ;
  map<ll, ll> mmap ;

  for(ll i = 0; i < m; i++) {
    ll x, y; cin >> x >> y ;
    if(mmap.find(x) == mmap.end()) {
      mmap[x] = y ;
    } 
    mmap[x] = min(mmap[x], y) ;
    mmap[x] = min(mmap[x], n) ;
    // arr[i] = {x, mmap[x]} ;
  }

  for(auto key: mmap) {
    arr.push_back({key.second, key.first}) ;
  }

  sort(arr.begin(), arr.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
      return a.first < b.first ;
      });

  unordered_map<ll, bool> visited ;

  vector<int> ans(n + 1, 0) ;
  
  for(auto key: arr) {
    ll val = key.second;
    bool flag = true ;
    for(ll i = key.first; i <= val; i++) {
      if(ans[i] == 0) {
        ans[i] = key.first ;
        flag = false;
        visited[key.first] = true ;
        break ;
      }
    }

    if(flag) {
      for(ll i = key.first - 1; i > 0; i--) {
        if(ans[i] == 0) {
          ans[i] = key.first ;
          flag = false ;
          visited[key.first] = true ;
          break ;
        }
      }
    }

    /*for(ll i = val; i > 0; i--) {
      if(ans[i] == 0) {
        ans[i] = key.first ;
        flag = false ;
        visited[key.first] = true ;
        break ;
      }
    }*/

    if(flag) {
      cout << -1 << endl ;
      return ;
    }
  }
  
  for(ll i = 1, j = 1; i <= n && j <= n; i++) {
    if(visited[i]) continue; 
    else {
      while(ans[j] != 0) j++ ; 
    }
    ans[j] = i ;
  }

  for(ll i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  } cout << endl ;
  



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
