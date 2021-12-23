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
        ll *arr = new ll[7] ;
        unordered_map<ll, bool> m ;
        for(int i = 0;i<7;i++) {
            cin >> arr[i] ;
            m[arr[i]] = true;
        }

        ll *a = new ll[3];
        a[0] = arr[0];
        int count = 1;
        ll x = arr[6] - arr[0] ;
        ll *arr2 = new ll[7];
        for(int i = 0;i<7 && count <= 2;i++) {
            arr2[i] = arr[i] - a[0] ;
            if(m[arr2[i]] && arr2[i] != x) {
                a[count++] = arr2[i];
            }
        }

        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
 return 0;
}