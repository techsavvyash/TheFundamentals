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
        string *strs = new string[n - 2];

        for(int i = 0;i<n - 2;i++) {
            cin >> strs[i] ;
        }
        string str = strs[0];
        bool flag = false ;
        for(int i = 1;i<n-2;i++) {
            //str += strs[i][1] ;
            if(strs[i-1][1] != strs[i][0]) {
                if()
                str += (strs[i][1] + strs[i+1][0]) ;
                flag = true ;
            } 
        }
        if(!flag) {
            if(strs[0][0] == 'a') {
                str = 'b' + str ;
            } else {
                str = 'a' + str ;
            }
        }
        str += '\0' ;
        cout << str << endl;

    }
 return 0;
}