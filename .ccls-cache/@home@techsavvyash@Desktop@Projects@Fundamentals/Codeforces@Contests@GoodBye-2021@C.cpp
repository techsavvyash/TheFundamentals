/*
#include <iostream>
#include <bits/stdc++.h> 
#include <istream>
using namespace std;
#define ll long long 
//we need to make sure that the array is an AP!
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t ;
  cin >> t ;
  
  while(t--) {
    ll n, *arr, maxDiff = INT_MIN, d;
    map<ll, ll> diff ;
    cin >> n ;
    arr = new ll[n] ;
    cin >> arr[0] ;
    for(ll i = 1;i<n;i++) {
      cin >> arr[i] ;
      diff[(arr[i] - arr[i-1])]++ ;
      if(maxDiff < diff[(arr[i] - arr[i-1])]) {
        maxDiff = diff[(arr[i] - arr[i-1])] ;
        d = (arr[i] - arr[i-1]) ;
      }
    }

    if(n == 1) {cout << 0 << endl ; continue; }
    cout << "Testcase: " << t << endl ; 
    cout << "d: " << d << endl ;
    cout << "maxDiff: " << maxDiff << endl ;
    //now we have 'D' and also the freq of max 
    ll pos, ops = 0 ;
    for(ll i = 1;i < n; i++) {
      if(arr[i] - arr[i-1] == d) {pos =   i ; break ;} 
    }
    if(pos == 1) {
      for(ll i = 2;i<n;i++) {
        if(arr[i] != (arr[0] + i*d)) {
          ops++ ;
          arr[i] = (arr[0] + i*d) ;
        }
      }
    } else  {
      for(ll i = pos - 2, j = 2;i>=0;i--, j++) {
        if(arr[i] != (arr[pos] - j*d)) {
          ops++ ; arr[i] = (arr[pos] - j*d) ;
        }
      }
      for(ll i = pos + 1; i < n ;i++) {
        if(arr[i] != (arr[0] + i*d)) {
          ops++ ;
          arr[i] = arr[0] + i*d ;
        }
      }
    }

    cout << ops << endl ;
    cout << "//-------------- End Test case: " << t << " --------------//" << endl ;
  
  }
  return 0;
} */

#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
#define lld long double
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n;
    cin >> n;
    vector<lld> arr(n) ;
    for(ll i = 0;i < n;i++) {
      cin >> arr[i] ;
    }
    lld d; ll c = 0, ans = 0 ;
    if(n == 1 || n == 2) {
      cout << 0 << endl ; continue ;
    }
    for(ll i = 0;i < n ; i++) {
      for(ll j = 0; j < n ; j++) {
        if(j == i) continue ;
        else {
          d = (arr[j] - arr[i])/(j - i) ;
          lld a = arr[i] - (i)*d ;
          for(int k = 0 ; k < n ; k++) {
            if(arr[k] == (a + (k*d))) c++ ;
          }
          ans = max(ans, c) ;
          c = 0 ;
        }
      }
    }

    cout << n - ans << endl ;


  }

  return 0;
}
