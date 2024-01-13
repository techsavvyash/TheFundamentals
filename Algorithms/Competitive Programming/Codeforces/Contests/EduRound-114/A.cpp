#include <iostream>
#include <bits/stdc++.h>
#define ll long long 

using namespace std;


void genParens(string s, ll n, ll &count, ll open, ll close) {
  //base cases
  if(count == n) return;
  if(close == n && open == n) {
    cout << s << endl; count++ ;
    return ;
  }

// recursive cases
  if(open  < n) {
  genParens(s + "(", n, count, open+1, close) ;}
  if(close  < open) {
  genParens(s + ")", n, count, open, close+1) ;}
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;

  ll t;
  cin >> t;
  while(t--) {
    
    ll n; cin >> n ;  ll count = 0 ;
    string s = "";

    genParens("", n, count, 0, 0) ;

  }
  return 0;
}
