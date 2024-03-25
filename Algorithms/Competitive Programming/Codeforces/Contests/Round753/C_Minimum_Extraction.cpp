#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n, *arr ;
    cin >> n ;
    arr = new ll[n] ;
    for(ll i = 0;i < n ;i++) {
      cin >> arr[i] ;
    }

    sort(arr, arr+n) ;
    ll m = arr[0] ;
    for(ll i = 1;i <n ;i++) {
      m = max(m, (arr[i] - arr[i-1])) ;
    }
    cout << m << endl ;
  
  }
  return 0;
}
