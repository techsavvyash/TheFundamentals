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
        string s;
        cin >> s;
        long long int numMoves = 0;
        for(int i = 0;i<s.length()-1;i++){
            //cout << "s at start of iteration " << i+1 <<": " << s << endl;
            //cout << "numMoves at the start of iteration: " << i+1 <<" is: " << numMoves << endl;
            if(s[i] == 'N' && s[i+1] == 'N'){
                s[i+1] = 'P';
                numMoves++ ;
            }
            //cout << "s at end of iteration " << i+1 <<": " << s << endl;
            //cout << "numMoves at the start of iteration: " << i+1 <<" is: " << numMoves << endl;
        }
        if(s[s.length()-1] == 'N') {
            s[s.length()-1] = 'P' ;
            numMoves++ ;        
        }
        //cout << "s: " <<  s << endl;
        long long int countN = 0, countP = 0;
        for(int i = 0;i<s.length();i++) {
            if(s[i] == 'N') countN++ ;
            else countP++ ;
        }
        //cout << "countP: " << countP << " countN: " << countN << endl;
        if(countP == 2*countN) {
            cout << numMoves << endl;
        } else if(countP > 2*countN) {
            while(countP != 2*countN) {
                countP--;
                countN++ ;
                numMoves++ ;
            }
            cout << numMoves << endl;
        } else {
            while(countP != 2*countN) {
                countP++;
                countN--;
                numMoves++ ;
            }
            cout << numMoves << endl;
        }
    }
 return 0;
} 