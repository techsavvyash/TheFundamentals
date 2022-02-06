#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t ;
  while(t--) {
    int n; cin >> n ; string str ; cin >> str;
    for(int i = 0; i < str.length();i++) {
      if(str[i] == 'L' || str[i] == 'R') {
        cout << str[i] ;
      } else if(str[i] == 'U') {
        cout << 'D' ;
      } else if(str[i] == 'D') {
        cout << 'U' ;
      }
    }
    cout << endl;

  }
  return 0 ;
}
