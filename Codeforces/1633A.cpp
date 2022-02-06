#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std; 


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t ;
  while(t--) {
    int n ; cin >> n ;
    int rem = n%7 ;
    if(rem == 0) {
      cout << n << endl ;
      continue ;
    } else {
      if(n%10 - rem > 0) {
        cout << n - rem << endl ;
      } else if(n%10 + (7-rem) < 10){
        cout << n + 7 - rem << endl ;
      } else {
        string str = to_string(n);
        if(str.length() == 2) {
          for(int i = 1; i < 10; i++) {
            str[0] = '0' + i ;
            int temp = atoi(str.c_str());
            if(temp%7==0) {
              cout << temp << endl ;
            }
          }
        } else if(str.length() == 3) {
          bool flag = true ;
          for(int i = 1; i < 10; i++) {
            str[0] = '0' + i ;
            int temp = atoi(str.c_str());
            if(temp%7==0) {
              cout << temp << endl ;
              flag = false ;
              break ;
            }
          }
          if(flag){
          for(int i = 0; i < 10; i++) {
            str[1] = '0' + i ;
            int temp = atoi(str.c_str());
            if(temp%7==0) {
              cout << temp << endl ;
            }
          }}
        }
      }
    }
  }
  return 0;
}
