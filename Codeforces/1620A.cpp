#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std ;

/*
Logic: The number of N should always be strictly greater than 1,
and there is always an array that's possible. 
Think of it like, we have a circular array that has all equal
elements, then let's a pair unequal, if you observe carefully,
you'll see that it is not possible to have only pair that is unequal, at least 
2 pairs are needed, and every other pair afterwards can be added, easily,
the last extereme case when all the elements are unequal is also certainly
possible and in that the elements of the array will be a permutation of
all the nos from 1 to length of the string
*/

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  int t ; cin >> t ;

  while(t--) {
    string str ; cin >> str ;
    int len = str.length() ;

    if(len == 2) {
      bool flag = str[0] == str[1] ;
      cout << (flag ? "Yes" : "No") << endl ;
      continue;
    }
    int numN = 0 ; 
    for(int i = 0; i < len; i++) {
      if(str[i] == 'N') numN++ ;
    } 

    cout << (numN != 1? "Yes" : "No") << endl ;

  }

}
