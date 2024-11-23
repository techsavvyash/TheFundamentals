
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;


void solve() {
  
  ll n, d ;
  cin >> n ;
  map<ll, bool> visited ;
  vector<int> ans ;
  ll i = 1, j = 2 ;
  if(n == 1) {
    cout << 1 << endl ;
    cout << 1 << endl ;
    return ;
  }
  cout << 2 << endl ;
  while(ans.size() < n && j <= n) {
    if(i <= n) {
      ans.push_back(i) ;
      if(!visited[i]) cout << i << " " ;
      visited[i] = true ;
      i *= 2 ;
    } else {
      while(visited[j]) j++ ;
      i = j ;
    }
  }

  cout << endl ;
} 


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; cin >> t ;
  while(t--) {
    solve() ;
  }

  return 0;
}
