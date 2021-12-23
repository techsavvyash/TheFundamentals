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
        ll n, k;
        cin >> n >> k;
        string s, pat;
        cin >> s;
        pat = "";
        for(int i = 0;i<k;i++) {
            pat += '0' ;
        }
        ll count = 0;
        //cout << "pat: " << pat << endl;

        for(int i = 0;i<=(s.length()-pat.length()) ; i++) {
            string str = s.substr(i, k);
            //cout << "str: " << str << endl;
            //cout << "str.compare(pat): " << str.compare(pat) << endl; 
            if(str.compare(pat) == 0) {
                count++ ;
                i = i + k - 1;
            }
        }
        cout << count << endl;
        
    }
 return 0;
}