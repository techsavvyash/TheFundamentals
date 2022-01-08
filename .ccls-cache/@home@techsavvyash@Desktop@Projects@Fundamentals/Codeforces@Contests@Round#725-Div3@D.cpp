#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

ll primeFactors(ll n) { 
    // Print the number of 2s that divide n 
    vector<ll> factors ; bool flag = false ;
    while (n % 2 == 0) { 
        //cout << 2 << " "; 
        if(!flag){
          factors.push_back(2) ;
          flag = false ;
        }
        n = n/2; 
    } 

    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (ll i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            factors.push_back(i) ; 
            n = n/i; 
        } 
    } 

    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) factors.push_back(n) ;

    return factors.size() ;
} 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t;
  cin >> t ;
  while(t--) {
    ll a, b, k ;
    cin >> a >> b >> k ;
    if(k >=2) {
      cout << "YES" << endl ;
      continue ;
    }

    if(k ==1) {
      if((a%b ==0 || b%a == 0) && a != b) {
        cout << "Yes" << endl ;
      } else {
        cout << "NO" << endl ;
      }
      continue ;
    }

    if(k == 0 && a == b) {
      cout << "Yes" << endl ;
      continue;
    } else {
      cout << "No" << endl ;
      continue ;
    }

    cout << "No" << endl;
  }

  return 0;
}
