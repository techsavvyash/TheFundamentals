#include <ios>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr;
        for(ll i = 0;i < n; i++) {
            cin >> arr[i];
        }

        vector<ll> bit(32);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < 32; j++) {
                bit[j] += ((arr[i] & (1 << j)) > 0);
            }
        }
        ll ans = 0;
        for (ll i = 0; i < 32; i++)
        {
            if (bit[i] >= 2)
            {
                ans |= (1 << i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
