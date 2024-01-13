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
        ll x ; cin >> x ;
        string str = to_string(x) ;
        string present = "" ;
        vector<int> digs ;
        ll temp = x ;
        while(temp != 0) {
            digs.push_back(temp%10) ;
            temp /= 10 ;
        }
        //reverse(digs.begin(), digs.end()) ;
        int n = digs.size() ;
        n -= 1 ; ll maxSoFar = x ;
        int sum = digs[n] + digs[n-1] ;
        present = to_string(sum) + str.substr(2) ;
        int y = atoi(present.c_str()) ;
        maxSoFar = y ;
        n-- ;
        //cout << maxSoFar << endl ;
        for(int i = n, j = 1; i > 0 ; i--, j++) {
            sum = digs[i] + digs[i-1] ;
            present = str.substr(0, j) + to_string(sum) + str.substr(j+2) ;
            y = atoi(present.c_str()) ;
            //cout << y << endl ;
            if(y > maxSoFar) {
                maxSoFar = y ;
            }
        }

        cout << maxSoFar << endl ;
    }
 return 0;
} 