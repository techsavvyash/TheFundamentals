#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        unsigned long long int n ;
        cin >> n;
        string str = to_string(n) ; ll ops = 0 ;
        ll lastIdx = -1, firstIdx = -1;
        for(int i = str.length() - 1 ; i > 0 ; i--) {
           if(str[i] == '5' || str[i] == '0') {
             lastIdx = i ;
             break ;
          }
        }
        if(str[lastIdx] == '0') {
          for(ll i = lastIdx-1; i >= 0; i--) {
            if(str[i] == '5' || str[i] == '0') {
              firstIdx = i ;
              break ;
            }
          } 
        }

        if(str[lastIdx] == '5') {
          for(ll i = lastIdx - 1; i >= 0; i--) {
            if(str[i] == '2' || str[i] == '7') {
              firstIdx = i ;
              break ;
            }
          } 
        }
        cout << "n: " << n << endl ;
        cout << "lastIdx: " << lastIdx << endl ;
        cout << "firstIdx: " << firstIdx << endl ;
        cout << (lastIdx - firstIdx + str.length() - lastIdx - 2) << endl ;
    }

    return 0;
}
