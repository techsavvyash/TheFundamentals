#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

/*vector<ll>spf(1000000000);

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve(ll m) {
    spf[1] = 1;
    for (ll i=2; i < m ; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4 ; i < m; i+=2)
        spf[i] = 2;

    for (int i = 3; i*i < m; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j < m; j+=i)

                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
ll getFactorization(ll x) {
    set<ll> ret;
    while (x != 1) {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret.size();
}*/

ll primeFactors(ll n, ll m) { 
    // Print the number of 2s that divide n 
    set<ll> factors ; bool flag = false ;
    while (n % 2 == 0) { 
        //cout << 2 << " "; 
        if(!flag){
          factors.insert(2) ;
          flag = false ;
        }
        n = n/2; 
    } 

    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (ll i = 3; i <= sqrt(n) && i <= m; i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            factors.insert(i) ; 
            n = n/i; 
        } 
    } 

    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) factors.insert(n) ;

    return factors.size() ;
} 
// driver program for above function
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    // precalculating Smallest Prime Factor
    ll n, m ;
    cin >> n >> m ;
    ll numFactors = primeFactors(m, n) ;
    //cout << "numFactors: " << numFactors << endl ;
    if(numFactors == 0) {
      cout << 0 << endl ;
      continue ;
    }
    for(ll i = numFactors; i >=0;i--) {
      if(n % i == 0) {
        cout << i << endl ;
        break ;
      }
    }
  }
    return 0;
}
