#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll r, g, b ;
    cin >> r >> g >> b ;
    if(r + g < b) {
      cout << -1 << endl ;
      continue ;
    } 
    map<ll, list<ll> > tree ;
    string ans = "RG" ;
    tree[1].push_back(2) ;
    r--; g-- ; ll node = 3;
    while(g--) {
      ans += 'G' ;
      tree[1].push_back(node++) ;
    }

    while(r--) {
      ans += 'R' ;
      tree[2].push_back(node++) ;
    } 
    ll pairer = 1;
    while(b--) {
      ans += 'B' ;
      tree[pairer++].push_back(node++) ;
    }

    cout << ans << endl;
    for(auto node: tree) {
      for(auto child: node.second) {
        cout << node.first << " " << child << endl ;
      }
    } 

  }
  return 0;
}
