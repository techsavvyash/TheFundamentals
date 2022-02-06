#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std ;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t ; cin >> t ;
  while(t--) {
    int n ; cin >> n; 
    string strs[n] ;
    for(int i = 0 ;i < n - 2; i++) {
      cin >> strs[i] ;
    }
    string ans = strs[0] ;

    for(int i = 1; i < n-2; i++) {
      if(strs[i][0] != strs[i-1][1]) {
        ans += (strs[i][0]) ;
      }
      ans += strs[i][1] ;
    }

    if(ans.length() == n) {
      cout << ans << endl;
    } else {
      ans += ans[ans.length()-1] ;
      cout << ans << endl ;
    }
  }
  return 0;
}
