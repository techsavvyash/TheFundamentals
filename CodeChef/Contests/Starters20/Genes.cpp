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
    //ll t;
    //cin >> t;
    //for(int it=1;it<=t;it++) {
        char a, b;
        int aW,bW;
        cin >> a >> b;
        char arr[] = {'G', 'B', 'R'};
        if(a == 'R') aW = 3;
        else if(a == 'B') aW = 2 ;
        else if(a == 'G') aW = 1;
        if(b == 'R') bW = 3;
        else if(b == 'B') bW = 2 ;
        else if(b == 'G') bW = 1;
        cout << arr[max(aW, bW) - 1] << endl;
    //}
 return 0;
}