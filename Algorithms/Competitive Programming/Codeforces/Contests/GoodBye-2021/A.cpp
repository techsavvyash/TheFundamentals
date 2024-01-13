#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <math.h>

#define ll long long 

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t ;
  cin >> t;
  
  while(t--) {
    ll n, *arr, count = 1 ;
    cin >> n;

    arr = new ll[n] ;
    map<int, int> m;
    bool flag = true ;
    cin >> arr[0] ;
    m[arr[0]]++ ;
    for(ll i = 1;i<n;i++) {
      cin >> arr[i] ;
      if(arr[i] != arr[i-1]) flag = false ;
      m[arr[i]]++ ;
      if(m[arr[i]] == 1) count++ ;
      if(m[arr[i]] == 2 && m[(-1)*arr[i]] == 0) {
        count++ ; m[(-1)*arr[i]]++;
      }
    }
    if(n == 1) {
      cout << 1 << endl;
      continue ;
    }
    if(flag) {
      if(arr[0] == 0) cout << 1 << endl;
      else cout << 2 << endl ;
    } else cout << count << endl; 
  }

  return 0 ;
}
