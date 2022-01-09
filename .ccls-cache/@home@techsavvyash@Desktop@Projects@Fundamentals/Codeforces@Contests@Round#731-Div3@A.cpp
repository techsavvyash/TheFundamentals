#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll ar, ac, br, bc, fr, fc ;
    cin >> ar >> ac >> br >> bc >> fr >> fc ;
    if( (ar == fr && fr == br && (fc > min(ac, bc) && fc < max(ac, bc))) || (ac == fc && fc == bc && (fr > min(ar, br) && fr < max(ar, br)))) { 
      cout << abs(ar - br) + abs(ac - bc) + 2 << endl ;
    } else {
      cout << abs(ar - br) + abs(ac - bc) << endl ;
    }
  }
  return 0;
}
