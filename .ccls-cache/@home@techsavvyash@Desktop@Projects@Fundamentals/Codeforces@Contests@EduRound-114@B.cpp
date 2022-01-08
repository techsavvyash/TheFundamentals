#include <iostream>
#include <bits/stdc++.h>
#define ll long long 

using namespace std;


int main() {
  ll t ;
  cin >> t;
  while(t--) {
    ll a, b, c, m, maxPairs, minPairs;
    cin >> a >> b >> c >> m ;
    maxPairs = (a+b+c - 3) ;
    /*ll n = min(a, min(b, c)) ;
    a -= n ;
    b -= n ;
    c -= n ;
    if(a == 0) {
      n = min(b, c) ;
      b -= n; c -= n ;
      if(b > 0) minPairs = b - 1 ; else minPairs = c - 1 ;
    } else if(b == 0) {
      n = min(a, c) ;
      a -= n; c -= n ;
      if(a > 0) minPairs = a - 1; else minPairs = c - 1 ; 
    } else {
      n = min(a, b) ;
      a -= n; b -= n;
      if(a > 0) minPairs = a - 1; else minPairs = b - 1 ;
    }*/
    
    vector<ll> nums ;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    sort(nums.begin(), nums.end()) ;
    /*nums[2] -= nums[0] ;
    if(nums[1] > nums[2]) {
      nums[1] -= nums[2] ;
      minPairs = nums[1] - 1;
    } else {
    nums[2] -= nums[1] ;
    minPairs = nums[2] - 1 ;
    }*/
    nums[2] -= nums[0] ;
    nums[1] -= nums[0] ;
    nums[2] -= nums[1] ;
    minPairs = nums[2] ;
    if(m >= minPairs /*(2*nums[2] - (a+b+c+1))*/ && m <= maxPairs) cout << "YES" << endl;
    else cout << "NO" << endl ;
  }
  return 0;
}
