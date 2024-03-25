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
        ll m, n;
        cin >> m >> n;

        if(m <= n-1) {
            priority_queue<ll> pq;
            for(ll i = 0;i<m*n;i++) {
                ll e;
                cin >> e;
                pq.push(e);
            }

            for(ll i = 0;i<n-1;i++) {
                pq.pop() ;
            }
            cout << pq.top() << endl;
            continue ;
        } else {
            map<ll, pair<ll, ll>, greater<ll> > tops ;
            for(ll row = 0;row<m;row++) {
                priority_queue<ll> pq ;
                for(ll col = 0;col < n ; col++) {
                    ll e;
                    cin >> e ;
                    pq.push(e) ;
                }
                ll e1 = pq.top() ; pq.pop() ; ll e2 = pq.top(); pq.pop();
                tops[e1] = make_pair(row, e2) ;
            }
            ll i = 0 ; priority_queue<ll> pq ;
            for(auto key: tops) {
                if(i > n-1) {
                    break ;
                }
                pq.push(key.first);
                pq.push(key.second.second) ;
                i++ ;
            }

            for(ll i = 0;i<n-1;i++) {
                pq.pop() ;
            }
            cout << pq.top() << endl;
            
        }

    }
 return 0;
}