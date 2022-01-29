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
    while(t--) {
      int n, m, r, c ;
      cin >> n >> m >> r >> c ;
      char matrix[n][m] ;
      bool check = false ;
      for(int i = 0 ; i < n ; i++) {
        for(int j = 0;j < m; j++) {
          cin >> matrix[i][j] ;
          if(matrix[i][j] == 'B') {
            check = true ;
          }
        }
      }

      if(!check) {
        cout << -1 << endl; 
        continue ;
      }

      if(matrix[r-1][c-1] == 'B') {
        cout << 0 << endl ;
        continue ;
      }
      check = false ;
      for(int i = 0; i < m; i++) {
        if(matrix[r-1][i] == 'B') {
          cout << 1 << endl ;
          check = true ;
          break ;
        }
      }

      if(check) {
        continue ;
      }
      check = false ;
      for(int i = 0; i < n; i++) {
        if(matrix[i][c-1] == 'B') {
          cout << 1 << endl;
          check = true ;
          break ;
        }
      }

      if(check) {continue ;}

      cout << 2 << endl ;
    }
 return 0;
}