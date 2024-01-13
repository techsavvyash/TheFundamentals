#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

#define MAXN   1000000000

// stores smallest prime factor for every number
ll *spf = new ll[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve() {
    spf[1] = 1;
    for (ll i=2; i < MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (ll i = 4; i < MAXN; i+=2)
        spf[i] = 2;

    for (ll i = 3; i*i < MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (ll j=i*i; j < MAXN; j+=i)

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
    vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret.size();
}

// driver program for above function
/*int main(int argc, char const *argv[]) {
    // precalculating Smallest Prime Factor
    sieve();
    int x = 12246;
    cout << "prime factorization for " << x << " : ";

    // calling getFactorization function
    vector <int> p = getFactorization(x);

    for (int i=0; i<p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}*/
/*ll primeFactors(ll n) { 
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
} */
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  sieve() ;
  ll t;
  cin >> t ;
  while(t--) {
    ll a, b, k ;
    cin >> a >> b >> k ;
    ll factA = getFactorization(a) ;
    ll factB = getFactorization(b) ;
    ll maxK = factA + factB ;
    int minK ;
    if(a == b) {
      minK = 0 ;
      if(k == 1) {
        cout << "No" <<  endl ;
        continue ;
      }
    }
    else if(a%b == 0 || b%a == 0) minK = 1 ;
    else minK = 2 ;
    
    if( k <= maxK && k >= minK) {
      cout << "Yes" << endl ;
    } else {
      cout << "No" << endl ;
    }
  }
  return 0;
}
