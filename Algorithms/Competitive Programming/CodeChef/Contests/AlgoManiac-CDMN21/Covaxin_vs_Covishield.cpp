#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main() {
    int I, i=1;
    scanf("%d", &I);
    unsigned long long int x, a, b, c, d, p , q, r, s , m, shield = 0, vaxin = 0, ans = 0, pShield, pVaxin, minimum, mini;
    long long int t;
    scanf("%llu %llu %llu %llu %llu %llu %llu %llu %llu %lld %llu", &x, &a ,&b, &c, &d, &p, &q, &r, &s, &t, &m);
    for(i =1; i <= I;i++) {
        mini = x;
        if(i > 1) {
            a = (a + ans*t)%m + p;
            b = (b + ans*t)%m + q;
            c = (c + ans*t)%m + r;
            d = (d + ans*t)%m + s;
            shield = vaxin = ans =0;
        }
        while(mini > 0){
            pShield = a + (shield)*b ;
            pVaxin = c + (vaxin)*d ; 
            std::pair<unsigned long long int, int> p = (pShield > pVaxin) ? std::make_pair(pVaxin, 1)  : std::make_pair(pShield, 0) ;
            if(mini >= p.first) {
                mini -= p.first;
                ans++;
                p.second ? vaxin++ : shield++ ;
            } else break;
        }
        printf("%llu\n", ans);
    }

    return 0;
}

