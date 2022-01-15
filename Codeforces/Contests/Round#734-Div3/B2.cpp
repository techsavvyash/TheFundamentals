#include <climits>
#include <iostream>
#include <bits/stdc++.h>
#define ll int 
using namespace std;


void solve() {
  ll n, k, moreThanOne = 0, equalToOne = 0; 
  cin >> n >> k; vector<ll> a(n); 
  ll *ans = new ll[n] ; map<ll, ll> f;  
  map<ll, list<ll>> pos;
  
  memset(ans, 0, n) ;

  for(ll i = 0;i < n;i++) {
    cin >> a[i] ;
    f[a[i]] = (f[a[i]] + 1 > k) ? ((f[a[i]] + 1)%k) : (f[a[i]] + 1) ;
    //maxFreq = max(maxFreq, a[i]) ;
    pos[a[i]].push_back(i) ;
  }

  for(auto key: f) {
    if(key.second > k) moreThanOne++ ;
    if(key.second <= k) equalToOne++ ;
  }
  
  ll colors = 1 ;

  for(auto key:pos) {
    if(key.second.size() > k) {
      key.second.resize(k) ;
      for(auto posn: key.second) {
        cout << "colors: " << colors << endl ;
        ans[posn] = colors ;
        colors = colors%k + 1 ; 
      }
    } else if(key.second.size() < k) {
      for(auto posn: key.second) {
        cout << "colors: " << colors << endl ;
        ans[posn] = colors ;
        colors = colors%k + 1 ;
      }
    }
  }

  if(colors != 1) for(ll i = (n/k)*k; i < n; i++) ans[i] = 0 ;

  for(ll i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl ;
 
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t; cin >> t ;
  while(t--) {
    solve() ;
  }

  return 0;
} 
