/*
Problem Statement: We have an array in which all the elements have a 
frequency of 2 except for 1, find that number
*/

#include <iostream>
using namespace std ;

int main() {
  int n; cin >> n; int *arr = new int[n] ;

  for(int i = 0; i < n; i++) {
    cin >> arr[i] ;
  }

  int ans = arr[0] ;
  for(int i = 1; i < n; i++) {
    ans ^= arr[i] ;
  }

  cout << ans << endl ;
  return 0;
} 
