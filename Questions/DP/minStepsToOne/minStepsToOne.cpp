#include <iostream>
#include <bits/stdc++.h>
using namespace std ;


/**What is the question? We are given a number and we can perform
the following operations:
1. Divide the number by 3
or 
2. divide the number by 2 
or 
3. subtract one from the number
*/

int minSteps(int n, int *dp) {
  if(n == 1) {
    return dp[n] = 0 ;
  }

  if(dp[n] != -1) {
    return dp[n] ;
  }


  int op1 = n%3 ? INT_MAX : (minSteps(n/3, dp)) ;
  int op2 = n%2 ? INT_MAX : (minSteps(n/2, dp)) ;
  int op3 = minSteps(n-1, dp) ;

  return dp[n] = min(op1, min(op2, op3)) + 1 ;
}

int minStepsBtmUp(int n) {
  vector<int> dp2(n) ;
  fill(dp2.begin(), dp2.end(), -1) ;
  dp2[1] = 0 ;

  for(int i  = 2; i <= n; i++) {
    
    int op1 = i%3 ? INT_MAX : dp2[i/3] ;
    int op2 = i%2 ? INT_MAX : dp2[i/2] ;
    int op3 = dp2[i - 1] ;
    dp2[i] = min(op1, min(op2, op3)) + 1 ;
  }
  
  return dp2[n] ;
}

int main() {
  int n ; cin >> n ;
  int *dp = new int[n] ;
  memset(dp, -1, n) ;
  dp[1] = 0 ;

  cout << "TopDown: " << minSteps(n , dp) << endl ;
    cout << "Bottom Up: " << minStepsBtmUp(n) << endl; 
  


  return 0;
}
