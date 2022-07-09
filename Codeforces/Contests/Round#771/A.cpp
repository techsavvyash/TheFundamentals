#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t ; cin >> t ;
  while(t--) {
    int n; cin >> n ;
    vector<int> arr(n); bool flag = true ; int idx1 = -1 ;
    cin >> arr[0] ;
    for(int i = 1; i < n; i++) {
      cin >> arr[i] ;
      if(arr[i] < arr[i-1]) flag = false ;
      if(arr[i] == 1) {
        idx1 = i ;
      }
    }

    if(flag) {
      for(int i = 0; i < n; i++) {
        cout << arr[i] << " " ;
      }
      cout << endl ;
    } else {
      if(idx1 == -1) {

      }
    }


  }

  return 0 ;
}
