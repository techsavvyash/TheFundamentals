#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std ;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t ; cin >> t ;
  while(t--) {
    int a, b, c ;
    cin >> a >> b >> c ;
    int total_time = a + (2*b) + (3*c) ;
    cout << total_time%2 << endl ;
  }
  return 0 ;
}
