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
        ll n, k, *arr;
        cin >> n >> k;
        arr = new ll[n];
        ll max = INT_MIN ;
        ll maxIdx = 0;
        for(int i = 0;i<n;i++) {
            cin >> arr[i] ;
            if(arr[i] > max) {
                max = arr[i] ;
                maxIdx = i;
            }
        }

        if(n - maxIdx < k/2) {
            
        }

    }
 return 0;
}