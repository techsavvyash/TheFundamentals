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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        ll n, *k, *h ; cin >> n;
        k = new ll[n]; h = new ll[n] ;

        for(ll i = 0; i < n;i++) {
            cin >> k[i] ;
        }

        for(ll i = 0; i < n;i++) {
            cin >> h[i] ;
        }   
        
        vector<pair<ll, ll>> v(n) ; //pair<time, health> 
        for(int i = 0;i < n;i++) {  
            v[i] = {k[i], h[i]} ;
        }

        sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.first < b.first ;
        }) ;
        int ans = ((v[0].second)*(v[0].second+1))/2 ; ;
        for(int i = 1 ; i < n;i++) {
            if(v[i].second <= ((v[i].first - v[i-1].first -1))) {
                cout << "ans in if: " << ans << endl ;
                ans += ((v[i].second)*(v[i].second + 1))/2 ;
            } else {
                cout << "ans in else: " << ans << endl;
                ans += ((((v[i].second + v[i].first - v[i-1].first)*(v[i].second + v[i].first - v[i-1].first + 1))/2) - ((v[i].second)*(v[i].second+1))/2);
            }
        }

        cout << ans << endl ; 

    }
 return 0;
}