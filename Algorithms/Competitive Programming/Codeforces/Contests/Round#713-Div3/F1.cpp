#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll n, t, k, sum, numZeros, mid, left, right;
  cin >> n >> t >> k ;
  left = 1; right = n ;
  while(left != right) {
    if(left == right) {
      cout << "! " << left << endl ;
      break;
    }
    mid = (left+right)/2 ;
    cout << "? " << left << " " << mid << endl ;
    int sum ; cin >> sum ;
    if((mid - left + 1) - sum >= k) right = mid ;
    else {
      left = mid + 1 ;
      k =  k - (mid - left + 1) + sum;
    }
  }
  cout << "! " << left << endl;  

  return 0;
}
