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
    while(t--) {
        ll n ;
        cin >> n ;
        vector<ll> v ; bool flag = true ;
        ll e; cin >> e ;
        v.push_back(e) ; 
        for(int i = 1;i<n;i++) {
            cin >> e ;
            v.push_back(e) ;
            if(v[i] != v[i-1]) flag = false ;
        }
        if(flag) {
            sort(v.begin(), v.end()) ;
            ll diff = (v[n-1] - v[0]), ans = diff ;
            while(diff >= ans && flag) {
                // v[0]++; v[n-1]--;
                // if(v[0] > v[1]) swap(v[0], v[1]) ;
                // if(v[n-1] < v[n-2]) swap(v[n-1], v[n-2]) ;
                
                for(int i = 0; i < n-1;i++) {
                    v[i]++; v[i+1]--;
                    if(v[i] > v[i+1]) swap(v[i], v[i+1]) ;
                }

                diff = v[n-1] - v[0] ;
                if(diff >= ans) flag = false ;
                else ans = diff ; 

            }      
            //sort(v.begin(), v.end()) ;
            //cout << ((v[n-1] - v[0]) < ans ? (v[n-1] - v[0]) : ans) << endl ;
            cout << ans << endl ;
        } else {
            cout << 0 << endl ;
        }       
    }
    
    return 0;
}