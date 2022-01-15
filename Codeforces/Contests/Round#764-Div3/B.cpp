
#include <iostream>
#include <bits/stdc++.h>
#include <ostream>
#define int long long 
using namespace std ;

void soln() {
  int a, b, c, tempA, tempB, tempC ;
  cin >> a >> b >> c ;
  tempA = a ; tempB = b; tempC = c ;

  //check if multiply 'c' gives an answer 

  if((b + (b - a))%c == 0) {
    tempC = (b + (b - a)) ;
    if(((tempC - b) == (b - a))&&tempC >=c && tempC != 0) {
      cout << "Yes" << endl ;
      return ;
    }
    
  }
  //check if multipling 'a' gives an answer
  if((b - (c - b))%a == 0) {
    tempA = (b - (c - b)) ;
    if((((b - tempA) == (c - b))) && (tempA >= a) && tempA != 0) {
      cout << "Yes" <<  endl ;
      return ;
    }
  }
  
  //check if multiplying 'b' gives an answer

  if((c-a)%2 == 0 && (a + (c-a)/2)%b == 0) {
    tempB = (a + (c-a)/2) ;
    if(((tempB - a) == (c - tempB)) && (tempB >= b) && tempB != 0) {
      cout << "Yes" << endl ;
      return ;
    }
  }
  


  cout << "No" << endl ;


  
  
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t ; cin >> t ;
  while(t--) {
    soln() ;
  }
  return 0;
}
