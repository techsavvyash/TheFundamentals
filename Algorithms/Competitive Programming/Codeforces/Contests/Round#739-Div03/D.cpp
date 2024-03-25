#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long 

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; 
  cin >> t;
  while(t--) {
    ll n ;
    cin >> n ;
    string sn = to_string(n);
    int ans = INT_MAX, steps = 0 ;
    unsigned long long int power = 1 ;
    for(int i = 0;i <= 60; i++) {
      string sx = to_string(power) ; int taken = 0;
      for(int j = 0, k = 0; j < sn.length() && k < sx.length(); ) {
        if(sn[j] == sx[k]) {k++ ; taken++; }
        j++ ;
      }
      steps = sn.length() - taken + sx.length() - taken ;
      ans = min(ans, steps) ;
      power *= 2 ;
    }

    cout << ans << endl ;
  }

  return 0;
}
