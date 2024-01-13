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
    
    ll n, *arr, count = 0;
    cin >> n;
    arr = new ll[n];
    for(ll i = 0; i < n; i++) {
        cin >> arr[i] ;
    }
    ll i ;
    for(i = 0;i<n;i++) {
        if(arr[i+1] < (2*arr[i])) {
            count++ ;
        } else {
            if(count >= 1) {
                break ;
            } 
        }
    }
    
        cout << count + 1 << endl ;
    
    return 0;
}