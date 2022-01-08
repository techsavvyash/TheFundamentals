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
        ll n, *l, *r;
        map<ll, ll> freq ;
        cin >> n;
        l = new ll[n] ;
        r = new ll[n] ;
        //vector<pair<ll, ll> > v;
        for(ll i = 0;i<n;i++) {
            cin >> l[i] >> r[i] ;
            //v.push_back({l, r}) ;
            freq[l[i]]++ ;
            freq[r[i]]++ ;
        }
        set<pair<ll,ll>>  f2 ;
        ll start = 1, end = n, nu;
        for(auto key: freq) {
            f2.insert(key.second, key.first) ;
            if(key.second == 0) nu = key.first ;
        } 

        while(!f2.empty()) {
            auto num = *(f2.begin());
            cout << start << " " << end << " " << num.second << endl ;
            f2.erase(num);
            f2.erase(f2.find({freq[end]--, end})) ;
            f2.erase(f2.find({freq[start]--, start})) ;
            f2.insert({freq[start], start}) ;
            f2.insert({freq[end], end}) ;
            

        }

        for(auto key: f2) {
            
        }

        //for(auto entry: v) {
        //    if(entry.first == entry.second) cout << entry.first << " " << entry.second << " " << entry.second << endl ;
        //    else {
        //        
        //    }        
        //
        //}
    }
 return 0;
}