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
        ll r, c, rr, rc, dr, dc, ra = 1, ca = 1 ;
        cin >> r >> c >> rr >> rc >> dr >> dc ;
        ll count = 0 ;
        while(rr != dr && rc != dc) { //&& because even if one is equal the cell is cleaned
            if(rr == r) ra = -ra ;
            if(rc == c) ca = -ca ;
            rr += ra;
            rc += ca ;
            count++ ;
        }
        
        cout << count << endl ; 
    }
 return 0;
}