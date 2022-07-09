#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;

    ll t; cin >> t ;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(1, 1);
        k -= n;
        ll curr = 2;
        for (int i = 2; i <= n; i++) {
            if (k < arr.size()) {
                int val = arr[arr.size()- k- 1];
                arr.push_back(val);
                break;
            }
            k -= arr.size();
            arr.push_back(curr);
            curr++;
        }

        while (arr.size() < n) {
            arr.push_back(arr.back());
        }
        
        //printing the array
        for(auto x: arr){
            cout << x << " ";
        }cout << endl;
    }
  return 0;
}
