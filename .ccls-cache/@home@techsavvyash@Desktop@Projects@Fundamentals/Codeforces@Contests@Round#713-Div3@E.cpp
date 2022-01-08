#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n; string str ;
    cin >> n; 
    cin >> str ;
    vector<int> pos ;
    pos.push_back(-1); 
    for(int i = 0; i < str.length(); i++) {
      if(str[i] == '*') {
        pos.push_back(i+1) ;
      }
    }

    ll numSheep = pos.size() - 1 ;
    //we need to make every sheep move to the middle sheep
    ll ans = 0 ;
    ll k = ceil((numSheep*1.0)/2) ;
    ll posMid = pos[k] ;
    /*cout << "numSheep: " << numSheep << endl;
    cout << "posMid: " << posMid << endl ;
    */for(ll i = 1; i <= numSheep; i++) {
      if(i == k) continue;
      ll val = abs(pos[i] - posMid - i + k);
      /*cout << "i: " << i << " pos[i]: " << pos[i] << endl;
      cout << "val: " << val << endl;
      */ans += val ;
    }

    cout << ans << endl ;


  }

  return 0;
}
