#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  while(t--) {
    int n; cin >> n; string str; cin >> str ;
    int countA = 0, countB = 0, lastIdxB = -1, lastIdxA = -1, firstIdxB = -1, firstIdxA = -1 ;
    for(int i = 0 ;i < str.length();i++) {
      if(str[i] == 'a') {countA++ ; lastIdxB = i ; if(firstIdxB == -1) firstIdxB = i ; }
      if(str[i] == 'b') {countB++ ; lastIdxA = i ; if(firstIdxA == -1) firstIdxA = i ; }
    }
    
    if(countA == 0 || countB == 0) {
      cout << -1 <<" " << -1 << endl;
      continue;
    }

    if(countA == countB) {
      cout << 1 << " " << str.length() << endl ;
      continue;
    }
    
    if(countA < countB) {
      int numElements = lastIdxA - firstIdxA + 1 ;
      int numB = numElements - countA ;
      if(numB > countA) {
        int l = 1 ; countA = 0 ; countB = 0 ;
      
        for(int i = 0; i < str.length(); i++) {
          if(str[i] == 'a') {
            countA++ ;
          }
          if(str[i] == 'b') {
            countB++ ;
          }

          if(countA == countB && countA != 0) {
            cout << l << " " << i + 1 << endl; 
            break ;
          }
        }
      } else {
        if(str.length() - lastIdxA > (countA - numB)) {
          cout << firstIdxA+1 << " " << lastIdxA + (countA-numB) + 1 << endl ;
        } else {
          cout << firstIdxA + 1 - (str.length() - lastIdxA) << " " << str.length() << endl ;
        }
      }
    } else {

      int numElements = lastIdxB - firstIdxB + 1 ;
      int numB = numElements - countB ;
      if(numB > countB) {
        int l = 1 ; countA = 0 ; countB = 0 ;
      
        for(int i = 0; i < str.length(); i++) {
          if(str[i] == 'a') {
            countA++ ;
          }
          if(str[i] == 'b') {
            countB++ ;
          }

          if(countA == countB && countA != 0) {
            cout << l << " " << i + 1 << endl; 
            break ;
          }
        }
      } else {
        if(str.length() - lastIdxB > (countB - numB)) {
          cout << firstIdxB+1 << " " << lastIdxB + (countB-numB) + 1 << endl ;
        } else {
          cout << firstIdxB + 1 - (str.length() - lastIdxB) << " " << str.length() << endl ;
        }
      }
    } 

    
    

    
  }
  return 0;
}
