#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define ll long long 
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll n ;
  cin >> n ;
  vector<vector<int> > v(n) ;
  for(ll i = 0; i < n ;i++) {
    ll c ; cin >> c ;
    v[i].resize(c) ;
    for(ll j = 0; j < c ; j++) {
      cin >> v[i][j] ;
    }
    ll m;
    cin >> m ;
    

  }
   
  return 0;
}
