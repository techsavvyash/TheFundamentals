#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n, l, r ; 
    cin >> n;
    map<ll, ll> freq ;
    vector<pair<ll, ll> > ranges(n) ;
    for(ll i = 0; i < n; i++) {
      cin >> l >> r ;
      ranges[i] = {l, r}  ;
    }
    
    for(ll i=0;i<n;i++) {
      for(ll j = ranges[i].first; j <= ranges[i].second; j++) {
        freq[j]++ ;
      }
    } 

    for(ll i = 0; i < n ;i++) {
      ll best = ranges[i].first ;
      for(ll j = ranges[i].first; j <= ranges[i].second; j++) {
        if(freq[best] > freq[j]) best = j ;
      }

      cout << ranges[i].first << " " << ranges[i].second << " " << best << endl; 
    }
    cout << endl ;
     

  }
  return 0;
}
