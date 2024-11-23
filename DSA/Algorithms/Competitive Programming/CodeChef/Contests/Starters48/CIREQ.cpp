#include <climits>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;


void solve() {
  ll n; cin >> n ;
  vector<int> arr(n) ;
  map<int, int> freq ;
  int minFreq = INT_MAX,minFreqEl = -1 ;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i] ;
    freq[arr[i]]++ ;
    if(arr[i] > 0) {
      if(minFreq > freq[arr[i]]) {
        minFreq = freq[arr[i]];
        minFreqEl = arr[i] ;
      }
    }
  }

  sort(arr.begin(), arr.end()) ;
  
  ll start = 0, end = n - 1;
  ll mid ;
  ll ans = INT_MIN ;
  
  for(ll i = 0; i < n; i++) {
    ll temp = (ceil(((i+1)*1.0)/arr[i]));
    ans = temp > ans ? temp : ans ;
  }

  cout << ans << endl ;

  // max num of positive arrays is the total number of postive elements
  // what about min ??? 
  // longest min array would be that of the size of minFreqEl, after that the second largest and so on;

  return ;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t; cin >> t ;
  while(t--) {
    solve() ;
  }
  return 0;
}
