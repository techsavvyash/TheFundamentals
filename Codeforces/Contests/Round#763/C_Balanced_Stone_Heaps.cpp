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
    for(ll it=1;it<=t;it++) {
        ll n;
        cin >> n;
        vector<ll> v(n) ;
        for(ll i = 0;i<n;i++) {
            cin >> v[i] ;
        }

        for(int i = 2;i<n;i++) {
            if((v[i]/3) > 0) {
                //we need maximum stones in the smallest heap, hence we'll move least possible
                //number and always get best ans, greedy approach
                v[i] -= 3 ;
                v[i-1] += 1 ;
                v[i-2] += 2 ;
            }
        }

        sort(v.begin(), v.end()) ;

        cout << v[0] << endl;
    }
 return 0;
}