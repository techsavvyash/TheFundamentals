#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;


void solve() {
  ll n; cin >> n;
  string str ; cin >> str ;
  int zeroCnt = 0, oneCnt = 0;
  for(int i = 0; i < n; i++) {
    if(str[i] == '0') zeroCnt++ ;
    if(str[i] == '1') oneCnt++ ;
  }

  if(zeroCnt > oneCnt) {
    for(int i = 0; i < zeroCnt; i++) cout << "0" ;
    cout << endl ;
    return ;
  } else {

    for(int i = 0; i < oneCnt; i++) cout << "1" ;
    cout << endl ;
    return ;
  }

  return ;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; cin >> t ;
  while(t--) {
    solve() ;
  }
  return 0;
}
