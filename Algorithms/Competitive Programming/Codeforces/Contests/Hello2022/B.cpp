
#include <ios>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
  ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) { 
    ll n, *l, *r, *c ;
    cin >> n;
    
    l = new ll[n] ;
    r = new ll[n] ;
    c = new ll[n] ;
    
    for(ll i = 0 ; i<n;i++) {
      cin >> l[i] >> r[i] >> c[i] ;
    }

    ll L = l[0], R = r[0], C = c[0], size = r[0] - l[0] ;
    vector<pair<ll, ll>> taken ;
    for(ll i = 1;i < n;i ++) {
      cout << C << endl ;
      if(r[i] - l[i] > size) {
        C = c[i] ;
        size = r[i] - l[i] ;
        R = r[i] ; L = l[i] ; taken.clear() ;
        taken.push_back({L, R}) ;
      } else if (r[i] - l[i] == size && C > c[i]) {
        C = c[i] ; L = l[i]; R = r[i] ; taken.clear() ;
        taken.push_back({L, R}) ;
      } else if (r[i] - l[i] < size || ((R < l[i]) || (L > r[i])))  {
        bool flag = true ;
        for(int k = 0; k < taken.size(); k++) {
          if((taken[k].first <= l[i] && taken[k].second >= r[i])) {
            flag = false ;
            break ;
          } 
        }

        if(flag) {
           C += c[i]; taken.push_back({l[i], r[i]}); size += (r[i] - l[i]) ;
        }
      }
    }
    cout << C << endl ;
    /*for(ll i = 1; i < n; i++) {
      cout << C << endl ;
      if((r[i] - l[i]) == (R - L)) continue ;
      if((l[i] < L && r[i] > R) || (l[i] == L && r[i] > R) || (l[i] < L && r[i] == R)) {
        C = c[i] ; L = l[i] ; R = r[i] ;
      } else if(l[i] < L || r[i] > R) {
        C += c[i] ;
        L = l[i] < L ? l[i] : L ;
        R = r[i] > R ? r[i] : R ;
      }
    }
    cout << C << endl ;*/

  }

  return 0;
} 
