#include <iostream>
#include <bits/stdc++.h>
using namespace std ;


void solve() {

    int n; string str ;
    cin >> n ;
    cin >> str ;
    map<char, bool> isDone ;
      
    for(int i = 0; i < 26; i++) {
      isDone[i + 'A'] = false ;
  }
    
    for(int i = 0; i < str.length()-1;i++) {
      if(str[i] != str[i+1]) {
        if(isDone[str[i]]) {
          cout << "NO" << endl ;
          return ;
        } else isDone[str[i]] = true ;
      }
    }
      
    if(isDone[str[str.length()-1]]) cout << "NO" << endl ;
    else cout << "YES" << endl ;
}

int main() {
  int t ;
  cin >> t ;
  while(t--) {
    /*int n; string str ;
    cin >> n ;
    cin >> str ;
    map<char, bool> isDone ;

    for(int i = 0; i < str.length()-1;i++) {
      if(str[i] != str[i+1]) {
        if(isDone[str[i]]) {
          cout << "NO" << endl ;
          break ;
        } else isDone[str[i]] = true ;
      }
    }
      
    if(str[str.length()-1]) cout << "NO" << endl ;
    else cout << "YES" << endl ;
    */
    solve() ;
  }
  return 0;
}
