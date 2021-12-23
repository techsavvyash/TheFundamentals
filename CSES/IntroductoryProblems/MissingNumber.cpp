#include <iostream>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, a;
    cin >> n;
    ll reqSum = (n*(n+1))/2, sum = 0 ;
    for(ll i = 0;i<n-1;i++) {
        cin >> a ;
        sum += a ;
    }
    cout << reqSum - sum << endl;
    return 0;
}