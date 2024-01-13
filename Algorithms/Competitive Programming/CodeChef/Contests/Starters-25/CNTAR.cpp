#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
#define MOD 1000000000 + 7
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t; cin >> t ;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<int> arr(n) ;
    unsigned long long int ans = 1 ;
    map<int, bool> visited ;
    for(int i = 0;i < n; i++) {
      cin >> arr[i] ;
      if(arr[i] <= m) {
        ans *= (m-1) ;
      } else if(arr[i] > m) {
        ans *= m ;
      }
    }
  }

  return 0 ;
}
