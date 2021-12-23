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
        ll n;
        cin >> n;
        ll sqr = sqrt(n) ;
        ll cbr = cbrt(n) ;
        unordered_map<int, bool> nums ;
        ll count = sqr ;
        for(int i = 1;i <= sqr ; i++) {
            nums[i*i] = true ;
        }

        for(int i = 2;i<=cbr;i++) {
            if(!nums[i*i*i]) {
                nums[i*i*i] = true ;
                count++ ;
            }
        }

        cout << count << endl;
    }
 return 0;
}