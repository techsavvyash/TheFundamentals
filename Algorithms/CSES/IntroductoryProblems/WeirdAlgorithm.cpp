
#include <iostream>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n ;
    while(n != 1) {
    cout << n << " ";
        if(n%2 == 0) {
            n = n/2; 
        } else {
            n = 3*n + 1;
        }
    } 
    cout << 1 << endl;
    return 0;
}