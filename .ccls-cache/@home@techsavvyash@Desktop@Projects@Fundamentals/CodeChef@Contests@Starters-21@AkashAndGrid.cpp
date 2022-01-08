/*#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n, x, y ;
    cin >> n >> x >> y ;
    if((x == y) || (x >= ((n+1)/2) && y == (n+1) - x) || (y >= ((n+1)/2) && x == n + 1 - y)) {
      cout << 0 << endl ;
      continue ;
    } else if(x == (n+1)/2 ||y == (n+1)/2) {
      if(((n+1)/2)%2 == 1) cout << 0 << endl ;
      else cout << 1 << endl ;
    } else {
      ll diff = abs(x - y) ;
      cout << diff << endl ;
    }
  }
  return 0;
}*/

#include<iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;

  ll t;
  cin>>t ;
  
  while(t--){
    ll n, x, y;
    
    cin >> n >> x >> y;
    
    if((y+x) % 2 == 0){
      cout << 0 << endl;
    }
    else{
      cout << 1 << endl;  
    }      
  }
  return 0;
}
