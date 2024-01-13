#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std ;

void soln() {
  vector<int> s; int n, e, m = -1  ;
  cin >> n ;
  for(int i = 0; i < n; i++) {
   cin >> e ; 
   s.push_back(e) ;
   m = max(m, e) ;
  }

  //cout << "max: " << m << endl ;

  int ans = -1 ;

  for(int i = 0 ;i<n;i++) {
    ans = max(ans, abs(m - s[i])) ;
  }

  cout << ans << endl ;




 // cout << *(--(--s.end())) << endl ;
  
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t ; cin >> t ;
  while(t--) {
    soln() ;
  }
  return 0;
}
