#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; cin >> t ;
  while(t--) {
    int n; cin >> n;
    string str ; cin >> str ;
    map<char, int> frq ;
    for(int i= 0; i < str.length();i++) {
      frq[str[i]]++ ;
    }
    ll ans = 0 ;
    for(auto key:frq) {
      ans += ((key.second/2) + (key.second%2)) ; 
    }

    cout << ans << endl;
  }
}
