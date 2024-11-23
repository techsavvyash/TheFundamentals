#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t; cin >>t ;
  while(t--) {
    int arr[7] ;
    for(int i = 0; i < 7; i++) {
      cin >> arr[i] ;
    }

    cout << arr[0] << " " << arr[1] << " " << (arr[6] - arr[0] - arr[1]) << endl ;
  }
  return 0;
} 
