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
    for(ll it=1;it<=t;it++) {
        unsigned long long int a, s;
        cin >> a ;
        cin >> s ;
        string astr = to_string(a) ;
        string sstr = to_string(s) ;
        if(astr.length() == 1 && sstr.length() == 1) {
            if(s < a) {
                cout << -1 << endl;
            } else {
                cout << s - a << endl;
            }
                continue ;
        }
        if(sstr.length() < astr.length()) {
            //cout << "case1 for invalid " << endl;
            cout << -1 << endl;
            continue ;
        } else {
            ll i = astr.length() - 1, j = sstr.length() - 1 ;
            string b = "" ; bool flag = false;
            while(i >= 0 && j >= 0) {
                int num1 ;
                if(astr[i] > sstr[j]) {
                    num1 = (stoi(sstr.substr(j-1, 2)) - stoi(astr.substr(i, 1))) ;
                    j-- ;
                } else {
                    num1 = stoi(sstr.substr(j, 1)) - stoi(astr.substr(i, 1)) ;
                }
                if(num1 < 0 || num1  > 9) {
                    //cout << "case 2 for invalid with num1: " << num1 << endl ;
                    cout << -1 << endl;
                    flag = true ;
                    break ;
                } 
                //cout << "appending num1 as : " << num1 << endl;
                b = to_string(num1) + b ;
                i-- ;
                j-- ;
            }
            if(flag) {
                continue ;
            }
            //cout << "i: " << i << " and j: " << j << " after loop!" << endl;
            if(j < 0 && i >= 0) {
                //cout << "case 3 for invalid" << endl;
                cout << -1 << endl;
            } else if (j >= 0 && i< 0) {
                //cout << "sstr.substr(1, j + 1) : " << sstr.substr(1, j + 1) << endl; 
                b = sstr.substr(0, j + 1) + b ;
                //cout << "printing from else if" << endl;
                cout << b << endl ;
            } else {
                if(b[0] == '0' && b.length() != 1) cout << b.substr(1) << endl; 
                else cout << b << endl;
            }
        }
    }
 return 0;
} 