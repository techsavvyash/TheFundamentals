#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t; cin >> t ;
  while(t--) {
    ll l, r, ans = 0 ; cin >> l >> r ;
    /*unoptimised soln
    while(l != r) {
      if(l%10 == 9) {
        ll temp = l, len = 0 ; 
        while(temp%10 == 9) {
          len++ ;
          temp /= 10 ;
        }
        l++; ans += (len + 1) ;
      } else {
        l++ ; ans += 1 ;
      }
    } */
    ans = 0 ; ll diff = (r - l) ;
    for(ll i =10; l > 0 || r > 0; i = i*10) {
      diff = (r - l) ;
      r /= 10; l /= 10 ;
      ans += (diff);
    }
    cout << ans << endl ;
    
  }
  return 0;
}
