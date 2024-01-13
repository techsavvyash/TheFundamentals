#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  
  while(t--) {
    string str ; cin >> str ;
    int count0 = 0, count1 = 0 ;
    for(int i = 0;i < str.length(); i++) {
      if(str[i] == '0') count0++ ;
      if(str[i] == '1') count1++ ;
    }

    if(count0 != count1) {
      cout << min(count0, count1) << endl ;
    } else {
      cout << count0 - 1 << endl ;
    }
  }
  
  
  return 0 ;
}
