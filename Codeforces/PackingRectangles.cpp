#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll w, h, n ;
  cin >> w ;
  cin >> h ;
  cin >> n;
  
  ll start = 0 ;
  ll end = (int)1e12;
  ll mid = (start + end)/2 ; // mid here represents the dimension of the square

  // this is not simple binary search, it is
  // binary search for answer, hence we need a checker fn
  while(end > (start + 1)) {
    mid = (start + end)/2 ;
    if(((mid/w)*(mid/h)) >= n) {
      end = mid;
    } else {
      start = mid;
    } 
  }
    // 1 1 1000000000
  cout << end << endl ;

  return 0;
}
