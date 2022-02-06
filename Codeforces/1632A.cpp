#include<iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  while(t--) {
    int n; cin >> n ; string str; cin >> str ;
    if(str.length() == 1 || (str.length() == 2 && str[0] != str[1])) {
      cout << "Yes" << endl ;
    } else {
      cout << "No" << endl ;
    }
  }
  return 0 ;
}
