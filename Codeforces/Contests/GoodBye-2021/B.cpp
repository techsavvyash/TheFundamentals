#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t ;
  cin >> t ;
  
  while(t--) {
    ll n ; string str, s ; bool flag = true ;
    cin >> n ;
    cin >> str ;
    if(n == 1) {
      cout << str << str << endl ;
      continue ;
    }

    if(str[0] == str[1]) {
      cout << str[0] << str[0] << endl;
      continue ;
    }
    for(int i = 0;i<str.length()-1;i++) {
      if(str[i+1] > str[i]) {
        s = str.substr(0, i+1) ;
        flag = false ;
        break ;
      }
    }
    if(flag) s = str ;
    cout << s;
    for(int i = s.length()-1;i>=0;i--) {cout << s[i] ;}
    cout << endl; 
    
  }

  return 0;
}


