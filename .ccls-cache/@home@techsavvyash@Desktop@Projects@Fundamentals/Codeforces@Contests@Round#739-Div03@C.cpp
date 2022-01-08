#include <iostream>
#include <math.h>
#define ll long long 
using namespace std ;

int main() {
  ll t ;
  cin >> t ;
  while(t--) {
    ll k ;
    cin >> k;
    ll f =  floor(sqrt(k)) ;
    ll c = ceil(sqrt(k)) ;
    if(f == c ) {
      cout << f << " " << 1 << endl ;
      continue ;
    } else {
      ll m = k - (f*f) ;
      if(m == c) {
        cout << c << " " << c << endl ;
      } else if(m <= (c-1)) {
        cout << m << " " << c << endl ;
      } else if(m >= (c-1)) {
        cout << c << " " << (2*c) - m << endl ;
      }
    }
  }
  return 0;
}
