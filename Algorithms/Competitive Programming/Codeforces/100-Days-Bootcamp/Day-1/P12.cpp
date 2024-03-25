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

/**
 * Algo used is: 
 * 1. We check for the first element where the non-decreasing sequence becomes decreasing
 * 2. We find the end index upto which the sequence remains decreasing 
 * 
 */

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1 ; it <= t; it++) {
        ll n, *arr ;
        cin >> n ;
        arr = new ll[n] ;
        ll start = INT_MIN, end = INT_MIN;
        bool flag = false, ans = false ;
        
        cin >> arr[0] ;
        for(ll i = 1 ; i < n ; i++) {
            cin >> arr[i] ;

            if(flag && arr[i] > arr[i-1]) {
                flag = false ;
                end = i-1 ; 
            }

            if(arr[i] < arr[i-1] && !flag) {
                flag = true ;
                if(start == INT_MIN) {
                    start = i-1 ;
                } else if(end != INT_MIN) {
                    ans = true;
                }
            }
        }
        //cout << "start: " << start << " end: " << end << endl;
        if(ans) cout << "no" << endl ;
        else {
            if(end == INT_MIN) cout << "yes" << endl;
            else {
                if(arr[(end+1 < n) ? end + 1 : n] > arr[(start - 1 < 0 ? 0 : start - 1)]) {
                    cout << "no" << endl;
                } else {
                    cout << "yes" << endl;
                }
            }
        }
        

    }
    return 0;
} 