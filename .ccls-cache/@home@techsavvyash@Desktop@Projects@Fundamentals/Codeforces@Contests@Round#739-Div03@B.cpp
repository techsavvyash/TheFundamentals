#include <iostream>
#include <math.h>
#define ll long long 
using namespace std ;


int main() {
  ios_base::sync_with_stdio(false) ; cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while (t--) {
  ll a, b, c, d1, d2, n ;
    cin >> a >> b >> c ;
    n = 2*abs(a-b) ;
    if(a > n || b > n || c > n) {
      cout << -1 << endl ;
      continue ;
    } else {
      d1 = c + (n/2) ;
      d2 = c - (n/2) ;

      if(d1 > 0 && d1 <= n) {
        cout << d1 << endl ;
      } else if(d2 > 0 && d2 <= n) {
        cout << d2 << endl ;
      } else {
      cout << -1 << endl ;
      }
    }
  }

  return 0;
}
