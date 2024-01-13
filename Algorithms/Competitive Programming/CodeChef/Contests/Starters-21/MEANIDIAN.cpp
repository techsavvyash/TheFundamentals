#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std ;

ll check(ll *arr, ll n, ll mid) {
  ll sum = accumulate(arr, arr+n, 0LL) ;
  ll meanOps = n*mid - sum ;
  if(meanOps < 0 ) return -1 ;
  ll medianOps = 0 ;
  for(int i = (n-1)/2; i < n; i++) {
    medianOps += max(0LL, mid - arr[i]) ;
  }
  if(medianOps > meanOps) return -1 ;
  return meanOps ;
  
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n, *arr ;
    cin >> n ; arr = new ll[n] ;
    for(int i = 0; i < n ; i++) {
      cin >> arr[i] ;
    }
    
    sort(arr, arr+n) ;
    ll left = arr[(n-1)/2], right = 1e9 + 10, ans = -1 ;
    while(left <= right) {
      ll mid = (left + right)/2 ;
      ll minOps = check(arr, n, mid) ;
      if(minOps != -1) {
        ans = minOps ;
        right = mid - 1; 
      } else {
      left = mid+1 ;
      }
    }
    cout << ans << endl ;

  }
  return 0;
} 
