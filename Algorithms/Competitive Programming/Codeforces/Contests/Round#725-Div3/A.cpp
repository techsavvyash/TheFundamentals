#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main() {
  ios_base:: sync_with_stdio(false) ; cin.tie(NULL); cout.tie(NULL);
  ll t ;
  cin >> t ;
  while(t--) {
    ll n, mini = INT_MAX, maxi =INT_MIN, minPos = -1, maxPos = -1 ; 
    cin >> n ;
    vector<ll> arr(n+1) ; arr[0] = -1 ;
    for(ll i = 1;i <= n;i++) {
      cin >> arr[i] ;
      if(arr[i] < mini) {
        mini = arr[i] ;
        minPos = i;
      }
      if(arr[i] > maxi) {
        maxi = arr[i] ;
        maxPos = i ;
      }
    }
    ll distBwPos = abs(minPos - maxPos) ;
    ll distFromFront = min(minPos, maxPos) ;
    ll distFromBack = n - max(minPos, maxPos) + 1 ;

    ll ans; 
    if(distFromFront > distFromBack) {
      ans = distFromBack + min(distFromFront, distBwPos) ;
    } else {
      ans = distFromFront + min(distFromBack, distBwPos) ;

    }

    cout << ans << endl ;


  }
  return 0;
}
