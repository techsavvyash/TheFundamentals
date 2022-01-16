#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int fiboBtmUp(int n) {
    if(n == 0 || n == 1) {
        return n ;
    }
    
    int a = 0, b = 1, c ;
    
    for(int i = 2;i <= n ; i++) {
        c = a + b ;
        a = b ; b = c ;
    }

    return c ;
}

int fiboTopDown(int n, int *dp) {
    //base case
    if(n == 0 || n == 1) {
        return (dp[n] = n) ;
    }

    if(dp[n] != -1) {
        return dp[n] ;
    }

    return (dp[n] = fiboTopDown(n-1, dp) + fiboTopDown(n - 2, dp)) ;
}

int main() { 
    int n; cin >> n ;
    int *dp = new int[n + 2];
    for(int i = 0; i < n + 2;i++) {
        dp[i] = -1 ;
    }
    cout << "Bottom Up: " << fiboBtmUp(n) << endl ;
    cout << "Top Down: " << fiboTopDown(n, dp) << endl ;
    return 0;
}