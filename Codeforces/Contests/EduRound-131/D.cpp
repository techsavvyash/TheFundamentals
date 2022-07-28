#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;


void solve() {

  int n; cin >> n ;
  vector<int> arr(n + 1) ;
  vector<int> ans(n + 1, -1) ;
  map<int, bool> used ;
  for(int i = 1 ;i <= n; i++) {
    cin >> arr[i] ;
    if(arr[i] == 1) { ans[i] = i ; used[i] = true; }
    else used[i] = false ;
  }
  
  // formula was floor(i/ai) ;
  // if arr[i] < 0 ==> ai > i 
  // if arr[i] == 1 ==> ai = i 
  // if arr[i] > 1 ==> ai < i
  
  for(int i = 0)


}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; cin >> t ;
  while(t--) {
    solve() ;
  }

  return 0;
}

