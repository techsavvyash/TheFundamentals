
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ; cin >> t ;
  while(t--) {
    string str ; cin >> str ;
    int len = str.length() ;
    int l = str.find('a') ;
    
    if(l == string::npos) {
      cout << "No" <<  endl ;
      continue ;
    }

    int r = l ; bool flag = true ;
    for(int i = 1; i < len; i++) {
      int pos = str.find('a' + i) ;
      if(pos == string::npos || (pos != l-1 && pos != r + 1)) {
        flag = false ; break ;
      } else {
        l = min(l, pos) ;
        r = max(r, pos) ;
      }
    }

    if(flag) {
      cout << "Yes" << endl ;
    } 
    else {
    cout << "No" <<  endl ;
    }
    
  }
  return 0;
}
