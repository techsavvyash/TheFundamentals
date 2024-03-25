#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll s, a ; string ss, sa ;
    cin >> a >> s ;
    ss = to_string(s) ;
    sa = to_string(a) ;
    //cout << "sa.length(): " << sa.length() << endl ;
    //cout << "ss.length(): " << ss.length() << endl ;
    if(sa.length() > ss.length()) {
      /*cout << "sa: " << sa << endl ;
      cout << "ss: " << ss << endl ;*/
      cout << -1 << endl ;
    }
    int i, j ; string b = "" ; bool flag = false ; 
    for(i = sa.length() - 1, j = ss.length() - 1; i >= 0 && j >= 0; i--, j--) {
      //cout << "sa: " << sa << endl ;
      //cout << "ss: " << ss << endl ;
      if(ss[j] < sa[i]) {
        j-- ;
        int d = ((int)(ss[j] - '0'))*10 + ((int)(ss[j+1] - '0')) ;
        int n = (int)(sa[i] - '0') ;
        //cout << "d: " << d << " n: " << n << endl ;
        if(d < 10 || d > 18) {
          cout << -1 << endl ;
          flag = true ;
          break ;
        }
        d = d - n ;
        //cout << "d: " << d << endl ;
        b = to_string(d) + b ;
        //cout << "b: " << b << endl ;
      } else {
        int d = (int)(ss[j] - '0') ; int n = (int)(sa[i] - '0') ;
        d = d - n ;
        //cout << "d: " << d << endl ;
        b = to_string(d) + b ;
        //cout << "b: " << b << endl ;
      }
    }
    if(flag) continue; 
    if(j >= 0 ) b = ss.substr(0, j+1) + b ;
    string check = "" ;
    for(i = sa.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--) {
      int x = (int)(sa[i] - '0') + (int)(b[j] - '0') ;
      check = to_string(x) + check ;
    }
    if(i >= 0) check = sa.substr(0, i+1) + check ;
    if(j >= 0) check = b.substr(0, j+1) + check ;
    //cout << "b: " << b << endl ;
    //cout << "check: " << check << endl ;
    
    if(check == ss && i < 0) {
      int i;
      for(i = 0; i < b.length() - 2; i++) {
        if(b[i] != '0') break ;
      }
      b = b.substr(i) ;
      cout <<  b << endl ;
    } else {
      cout <<  -1 << endl ; 
    }
  }
  return 0;
}
