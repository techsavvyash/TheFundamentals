#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t ; cin >> t ;
  while(t--) {
    int n, s ; cin >> n >> s ;
    int m = ceil((n*1.0)/(2*1.0)) ;
    int leftHalf = ((m - 1) > 0) ? (m-1) : 0 ;
    int rightHalf = n - leftHalf ;
    if(leftHalf < 0) leftHalf = 0 ;
    //cout << "leftHalf: " << leftHalf << " rightHalf:  " << rightHalf << endl ;
    cout << s/rightHalf << endl; 

  }

  return 0 ;
}
