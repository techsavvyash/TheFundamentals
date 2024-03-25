#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#include <ostream>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;

  ll t ;  
  cin >> t ;
  while(t--) {
    ll n, *p, *q ; string str ;
    cin >> n ;
    q = new ll[n] ; p = new ll[n] ;
    memset(q, -1, sizeof(q)/sizeof(int)) ;

    for(ll i = 0; i < n ;i++) {
      cin >> p[i] ;
    }

    cin >> str ;

    set<pair<ll, ll>> dislike, like ;

    for(ll i = 0; i < str.length(); i++) {
      if(str[i] == '0') dislike.insert({p[i], i}) ;
      else like.insert({p[i], i}) ;
    }

    if(dislike.size() == 0 || like.size() == 0 || *(--dislike.end()) < *(like.begin())) {
      for(ll i = 0; i < n; i++) {
        cout << p[i] << " " ; 
      }
      cout << endl ;
      continue;
    }

    set<pair<ll, ll>>:: iterator disItr = --dislike.end(), likItr = like.begin();

    while(disItr != --dislike.begin() && likItr != like.end() && *disItr > *likItr) {
      if(disItr->first > likItr->first ) {
        q[likItr->second] = disItr->first ;
        q[disItr->second] = likItr->first ;
        disItr--; likItr++ ;
      }
    }

    for(ll i = 0;i < n;i++) {
      if(q[i] != -1) { cout << q[i] << " " ; continue ; }
      cout << p[i] << " " ;
    }
    cout << endl ;

    /*ll ans = 0 ;

    for(ll i = 0; i < n;i++) {
      ans += abs(p[i] - q[i]) ;
    }

    cout << ans << endl ;
*/

  }

  return 0 ;
}
