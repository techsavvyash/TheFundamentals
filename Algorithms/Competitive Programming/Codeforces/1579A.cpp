#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t ; cin >> t ;
  while(t--) {
    string str; cin >> str ;
    int countA = 0, countB = 0, countC = 0 ;

    for(int i =0 ; i < str.length(); i++) {
      switch(str[i]) {
        case 'A':
          countA++ ;
          break ;
        case 'B':
          countB++ ;
          break ;
        case 'C' :
          countC++;
          break; 
          
      }
    }

    if(countB == (countA + countC)) {
      cout << "Yes" << endl ;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
