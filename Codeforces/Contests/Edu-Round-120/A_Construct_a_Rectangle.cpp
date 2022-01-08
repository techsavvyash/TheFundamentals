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
        ll l1, l2, l3 ;
        cin >> l1 >> l2 >>l3 ;
        if(l1 != l2 && l2 != l3 && l1 != l3) {
            if((l1 + l2 == l3) || (l1 + l3 == l2) || (l2 + l3 == l1)) {
                cout << "YES" << endl;
                continue ;
            } else {
                cout << "NO" << endl;
                continue ;
            } 
        } else {
            if((l1 + l2 + l3)%2 == 0) {
                cout << "YES" << endl ;
            } else cout << "NO" << endl ;
        }
    }
 return 0;
}