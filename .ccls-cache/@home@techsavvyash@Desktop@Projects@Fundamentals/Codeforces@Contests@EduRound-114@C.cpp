/*#include <algorithm>
#include <climits>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n, m, sw = INT_MIN;
  unsigned long long int *drag, *y, ts = 0 ;
  cin >> n ; vector<unsigned long long int> arr ;
  for(ll i = 0; i < n ; i++) {
    unsigned long long int e;
    cin >> e ;
    arr.push_back(e) ;
    ts += e ;
  }

  sort(arr.begin(), arr.end()) ;
  sw = arr[n - 1] ;
  cin >> m ; drag = new unsigned long long int[m] ; y = new unsigned long long int[m] ;
  for(ll i = 0;i < m; i++) {
    cin >> drag[i] ;
    cin >> y[i] ;
  }

  for(ll i = 0; i < m; i++) {
    ll coin = 0 ;
    if(sw >= drag[i] && (ts - sw)  >= y[i]) {cout << 0 << endl ; continue ;}
    if(sw < drag[i]) {
      coin += (drag[i] - sw) ;
      if((ts - sw) < y[i]) coin += (y[i] - ts + sw) ;
      cout << coin << endl ;
      continue ;
    }
    if(arr[0] >= drag[i]) {
      //cout << "used in testcase: " << i+1 << endl ;
      //cout << "coin initially " << coin << endl ;
      if(y[i] > (ts - arr[0])) {
        //cout << "if executed " << endl ;
        //cout << "y[i] : " << y[i] << endl ;
        //cout << "ts: " << ts << endl ;
        //cout << "arr[0]: " << arr[0] << endl ;
        //cout << "y[i] - ts + arr[0] : " << y[i] - ts + arr[0] << endl ;  
        coin += (y[i] - ts + arr[0]) ;
        //cout << "coin after " << coin << endl;
      }
      cout << coin << endl ;
      continue;
    }
    //i more cases ;
    if(sw >= drag[i] && (ts - sw) < y[i]) {
      bool flag = false ; coin = y[i] - ts + sw ;
      for(ll i = n - 2 ; i > 0 ; i--) {
        if(arr[i] >= drag[i] && (ts - arr[i]) >= y[i]) {
          coin = 0;
          flag = true ;
          break ;
        }
        if(arr[i] >= drag[i] && (ts - arr[i]) < y[i]) coin = coin < (y[i] - ts + arr[i]) ? coin  : (y[i] - ts + arr[i]) ;
        else if()
       }
ll i ;
      for(i = 0;i<n-1;i++) {
        if(arr[i] > drag[i]) break ;
      }

      coin = y[i] - ts + arr[i] ;
      cout << coin << endl ;
    }

    if(sw >= drag[i] &&  (ts - sw) < y[i]) {
      ll l = 0, r = n-1, pos = -1 ;
      while(l <= r) {
        ll mid = (l+r)/2 ;
        if(arr[mid] >= drag[i]) {
          pos = mid ;
          r = mid - 1 ;
        } else l = mid + 1 ;
      } 
      if(pos != -1) {
      ll fi = 0 > (drag[i] - arr[pos]) ? 0 : (drag[i] - arr[pos]) ;
      ll si = 0 > (y[i] - ts + arr[pos]) ? 0 : (y[i] - ts + arr[pos]) ;
      coin = fi + si ;
      }
      //cout << coin << endl ;
      l = 0, r = n-1, pos = -1 ;
      while(l <=r) {
        ll mid = (l+r)/2 ;
        if(arr[mid] <= drag[i]) {
          pos = mid ;
          l = mid + 1 ;
        } else r = mid - 1 ;
      }
      if(pos != -1 ) {
      ll fi = 0 > (drag[i] - arr[pos]) ? 0 : (drag[i] - arr[pos]) ;
      ll si = 0 > (y[i] - ts + arr[pos]) ? 0 : (y[i] - ts + arr[pos]) ;
      ll sec = 0 > (fi + si) ? 0 : (fi + si) ;
      coin = max(coin, sec) ;
      }
      cout << coin << endl ;
      ll idx = lower_bound(arr.begin() , arr.end(), drag[i]) - arr.begin() ;
      ll a = 0, b = 0 ;
      if(arr[idx] < drag[i]) {
        a += (drag[i] - arr[idx]) ;
      }
      if(y[i] - ts + arr[idx] > 0) {
        a += (y[i] - ts + arr[idx]) ;
      }

      if(arr[idx - 1] < drag[i]) {
        b += (drag[i] - arr[idx - 1]) ;
      }

      if(y[i] - ts + arr[idx - 1] > 0) {
        b += (y[i] - ts + arr[idx - 1]) ;
      }

      coin = min(a, b) ;
      cout << coin << endl ;
    }

  }


  return 0;
}  */


#include <algorithm>
#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll n ;
  cin >> n ;
  vector<ll> arr(n) ; ll sum = 0 ;
  for(ll i = 0;i < n ; i++) {
    cin >> arr[i] ;
    sum += arr[i] ;
  }

  sort(arr.begin(), arr.end()) ;
  ll m; 
  cin >> m ;
  for(ll i = 0;i < m;i++) {
    ll x, y ;
    cin >> x >> y ;
    ll coins = 0;
    ll in = lower_bound(arr.begin(), arr.end(), x) - arr.begin() ;
    if(in == 0) {
      if (y > (sum - arr[in])) coins += (y - (sum - arr[in])) ;
    } else if(in != n) {
    ll a = 0, b = 0 ;
    if(arr[in] < x) a += x - arr[in] ;
    if(y > (sum - arr[in])) a += (y - (sum - arr[in])) ;
    if(arr[in-1] < x) b += x - arr[in - 1] ;
    if(y > (sum - arr[in-1])) b += (y - (sum - arr[in-1])) ;
    coins = min(a, b) ;
    } else {
    ll b = 0;
    if(arr[in-1] < x) b += x - arr[in-1] ;
    if(y > (sum - arr[in - 1])) b += (y - (sum - arr[in - 1])) ;
    coins = b ;
    }

    cout << coins << endl ;
  }
  return 0;
}
