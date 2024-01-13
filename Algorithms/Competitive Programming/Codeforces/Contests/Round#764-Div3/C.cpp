
#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std ;

void soln() {
  int n; cin >> n ; vector<int> a(n) ;
  map<int, bool> visited ;
  //setting initial values to false ;
  for(int i = 1;i <= n; i++) {
    visited[i] = false ;
  }


  for(int i = 0;i < n;i++) {
    cin >> a[i] ;
    if(a[i] <= n) visited[a[i]] = true ;
  }
  
  sort(a.begin(), a.end()) ;

  /*cout << "!!!!initial Map!!!!!" << endl ;
  for(auto key: visited) {

    cout << key.first << " " << (key.second ? "visited" : "not-visited") << endl ;
    //flag = key.second ;
  }*/
 // int idx = upper_bound(a.begin(), a.end(), n) - a.begin() ;
  
  int idx = lower_bound(a.begin(), a.end(), n) - a.begin() + 1;
  if(idx >= n) {
    bool flag = true ;
    for(auto key: visited) {
      flag = key.second ;
    }
    cout << (flag ? "Yes" : "No") << endl ;
    return ;
  }
  cout << "idx: " << idx << endl ;
  /*cout << "******* array after sorting: " << endl ;

  for(int i = 0; i<n;i++) {
    cout << a[i] << " " ;
  }
  cout << endl ;
*/

  for(int i = idx; i < n;i++) {
    //cout << "*****For iteration: " << (i - idx + 1) << endl ;
    int k = a[i] ; bool flag = false ;
    //cout << "***k: " << k << endl ;
    //cout << "***** array in for iteration" << endl ;
    //for(int i = 0; i<n;i++) {
     // cout << a[i] << " " ;
    //}
  //cout << endl ;
    //cout << "!!!!!!!Starting the while loop!!!!!!" << endl ;
    while(k > 0) {
      cout << "K: " << k << endl ;
      k = k/2 ;
      if(k > n){
        continue ;
      }

      if(k > 0 && k <=n && !visited[k]) {
        visited[k] = true ;
        flag = true ;
        break ;
      }
    }
    //if(!flag) {
      //cout << "No at idx: " << i << endl ;
      //cout << "No" <<  endl ;
      //return ;
    //}
    //for(auto key: visited) {
      //cout << key.first << " " << (key.second ? "visited" : "not-visited") << endl ;
    //}
  }

  

  bool flag = true ;
  //cout << "!!!!Final Map!!!!!" << endl ;
  for(auto key: visited) {
    if(!flag) break ;
  //  cout << key.first << " " << (key.second ? "visited" : "not-visited") << endl ;
    
    flag = key.second ;
  }
  cout << (flag ? "Yes" : "No") << endl ;


  
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t ; cin >> t ;
  while(t--) {
    soln() ;
  }
  return 0;
}
