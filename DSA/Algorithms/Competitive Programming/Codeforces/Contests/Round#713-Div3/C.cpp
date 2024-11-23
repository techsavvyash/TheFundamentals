#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t ;
  cin >> t ;
  while(t--) {
    ll n; cin >> n ;
    if(n == 1) {
      cout << n << endl ;
      continue ;
    }
    if(n == 2) {
      cout << -1 << endl ;
      continue;
    }
    ll ans[100][100] = {0} ;
    ll cnt = 1, row = 0, col = 0 ;
   
   /* for(ll i = 0;i <n ;i++) {
      for(ll j = 0; j < n ; j++) {
        cout << ans[i][j] << " " ;
      }
      cout << endl ;
    }*/

      //filling the main diagonal
      for(int i = 0; i < n; i++) {
        ans[i][i] = cnt++ ;
      }
     // cout << "filled main diagonal "  << endl ;
      ll offset = 1 ; row = 0, col = 1 ;
    /*for(ll i = 0;i <n ;i++) {
      for(ll j = 0; j < n ; j++) {
        cout << ans[i][j] << " " ;
      }
      cout << endl ;
    }*/
      /*while(!(row == n-1 && col == 0)) {
        ans[row++][col++] = cnt++ ;
        if(row == n-1 || col == n-1) {

        }
        
      }*/

      for(ll i = 1; i < n; i++) {
        //filling the upper diagonal
        col = 0 + i ; row = 0 ;
        for(ll j = 0; j < (n - i); j++) {
          /*cout << "row: " << row << " col: " << col << endl;
          cout << "ans[row][col: " << ans[row][col] << endl;   
          cout << "cnt: " << cnt << endl ;*/
          ans[row++][col++] = cnt ;
          //cout << "ans[row][col: " << ans[row][col] << endl;   
          cnt++ ;
          /*cout << "cnt after: " << cnt << endl ;
          cout << "matrix after \n" ;
    for(ll i = 0;i <n ;i++) {
      for(ll j = 0; j < n ; j++) {
        cout << ans[i][j] << " " ;
      }
      cout << endl ;
    }*/
        }
        //cout << "filled the upper diagonal " << i << "th time\n";
        //filling the lower diagonal
        col = 0 ; row = 0 + i ;
        for(ll j = 0; j < n - i; j++) {
          ans[row++][col++] = cnt++ ;
        }
        /*cout << "filled the lower diagonal " << i << "th time\n";
          cout << "matrix after \n" ;
    for(ll i = 0;i <n ;i++) {
      for(ll j = 0; j < n ; j++) {
        cout << ans[i][j] << " " ;
      }
      cout << endl ;
    }*/
      }

      //cout << "outside before printing" << endl;
      
          //cout << "printing result \n" ;
    for(ll i = 0;i <n ;i++) {
      for(ll j = 0; j < n ; j++) {
        cout << ans[i][j] << " " ;
      }
      cout << endl ;
    }
      //printing the ans
    /*for(int i=0;i<n;i++) {
      for(int j = 0;j<n;i++) {
        cout << ans[i][j] << " ";   
      }
      cout << endl ;
    }*/

  }

  return 0;
}
