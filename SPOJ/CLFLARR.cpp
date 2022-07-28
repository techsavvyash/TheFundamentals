#include<iostream>
#include <bits/stdc++.h>
using namespace std ;

struct triplet {
  int x, y, z ;
};

int main() {
  int n, q ;
  cin >> n >> q ;
  vector<int> arr(n + 1) ;

  stack<triplet> s ;
  map<int, bool> visited ;

  for(int i = 0 ; i < q; i++) {
    int x, y,z ;
    cin >> x >> y >> z ;
    triplet trip = triplet();
    trip.x = x ;
    trip.y = y ;
    trip.z = z ;
    s.push(trip) ;
  }

  while(!s.empty()) {
    triplet query = s.top() ;
    s.pop() ;
  
    int color = query.z ;
    int start = query.x; 
    int end = query.y ;

    if(visited[start] && visited[end]) {continue;}
    if(visited[start]) {
      int i = end ;
      while(!visited[i] && i >= start)  {
        if(!arr[i]) arr[i] = color ;
        visited[i] = true ;
        i-- ;
      }
    }

    if(visited[end]) {
      int i = start ;
      while(!visited[i] && i <= end) {
        if(!arr[i]) arr[i] = color ;
        visited[i] = true ;
        i++ ;
      }
    }

    if(!visited[start] && !visited[end]) {
      for(int i = start;i <= end;i++) {
        if(!arr[i]) arr[i] = color ;
        visited[i] = true ;
      }
    }
    

  
  }
  
  for(int i = 1; i <= n; i++) {
    cout << arr[i] << " " << endl ;
  } 





  return 0 ;
}
