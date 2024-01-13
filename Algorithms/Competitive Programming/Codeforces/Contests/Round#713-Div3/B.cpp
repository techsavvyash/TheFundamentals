#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#define ll long long 
using namespace std;

void solve() {
  
  ll n; cin >> n ;
  ll ans = 9 ;
  
  if(n < 10 ) {
    cout << n << endl ;
    return ;
  }

  if(n == 10) {
    cout << ans << endl ;
  }

  string str = to_string(n), check = "" ;
  ll m = str.length() ;
  check += str[0] ;
  int y = 0 ;
  /*stringstream converter(check) ;
  converter >> y ;*/
  for(int i = 0; i < m - 2 ; i++) {
    ans += 9 ;
    check += str[0] ;
  } 
  
  check += str[0] ;
  
  stringstream converter(check) ;
  converter >> y ;
  if(y > n) {
    ans += ( str[0] - '0' - 1 ) ;
  } else {
    ans += (str[0] - '0') ;
  }

  cout << ans << endl ;
  return ;
}

void solve2() {
  ll n, ans = 0 ;
  cin >> n ;
  
  for(ll i = 1; i <= n; i =i*10 +1) {
    for(int k = 1; k <=9;k++) {
      if(k*i <=n) ans++ ;
    }
  }

  cout << ans << endl ;
}

int main() {
  ios_base::sync_with_stdio(false) ; cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) { 
    //cout << "************* Start TestCase *****************" << endl ;
    //cout << "************* Answers from solve *****************" << endl ;
    solve() ;
    //cout << "************* Answers from solve2 *****************" << endl ;
    //solve2() ;
    //cout << "************* End TestCase *****************" << endl ;
  }
  return 0;
}
