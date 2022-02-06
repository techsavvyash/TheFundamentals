#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std ;


int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t ;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n) ;
    for(int i = 0 ;i < n; i++) {
      cin >> a[i] ;
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i] ;
    }

    vector<pair<int, int>> p(n) ;
    for(int i = 0;i < n; i++) {
      p[i]= {a[i], b[i]} ;
    }

    sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b){
      return a.first < b.first ;
    });

    int initialRam = k;
    if(p[0].first > k) {
      cout << k << endl ;
      continue ;
    }

    for(int i = 0; i < n && initialRam >= p[i].first; i++) {
      initialRam += p[i].second;
    }

    cout << initialRam << endl ;
  }
  return 0 ;
} 
