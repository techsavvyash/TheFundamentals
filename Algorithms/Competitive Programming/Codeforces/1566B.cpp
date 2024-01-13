#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t; 
  while(t--) {
    string str; cin >> str ;
    int len = str.length();
    if(len == 2) {
      if(str[0] == str[1] && str[0] == '1') {
        cout << 0 << endl ;
      } else {
      cout << 1 << endl ;
      }
      continue ;
    }
    bool flag = false ; int i ;
    for(i = 0; i < len - 1 ;i++) {
      if(str[i] != str[i+1]) {
        flag = true ;
        break ;
      }
    }

    if(!flag) {
      if(str[0] == '0') {
        cout << 1 << endl ;
      } else if(str[0] == '1') {
      cout << 0 << endl ;
      }
    } else {
      for(i = i+1; i < len - 1 ;i++) {
        if(str[i] != str[i+1]) {
          flag = false ;
          break ;
        }
      }
      if(!flag) {
        if(str[i+1] == '0') {
          cout << 2 << endl ;
        } else {
          for(i = i+1; i < len - 1; i++) {
            if(str[i] != str[i+1]) {
              flag = true ;
              break ;
            }
          }
          cout << (flag ? 2 : 1) << endl ;
        }
      }
    }
    

  }
  
  return 0;
}
