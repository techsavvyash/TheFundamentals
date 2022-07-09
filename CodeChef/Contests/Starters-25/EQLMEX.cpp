#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n ;
    vector<int> arr(2*n) ;
    map<int, int> f ;
    for(int i = 0;i < (2*n); i++) {
      cin >> arr[i] ;
      f[arr[i]]++ ;
    }
    bool ans = true ;

    int mex ;
    for(int i = 0; i <= n + 1; i++) {
      if(f[i] == 0) {
        mex = i ;
        break ;
      }
    }

    for(int i = 0; i < mex; i++) {
      if(f[i] < 2) {
        ans = false ;
        break ;
      }
    }

    cout << (ans ? "Yes" : "No") << endl ;


  }
  return 0 ;
} 
