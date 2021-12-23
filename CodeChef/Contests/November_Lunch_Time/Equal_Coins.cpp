#include <iostream>
using namespace std;
//prob code: EQUALCOIN
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int x, y;
        cin >> x >> y;
        if(x == 0 && (y%2 == 0)) {
            cout << "YES" << endl;
            continue ;
        } else if(x == 0 && (y%2 == 1)) {
            cout << "NO" << endl;
            continue ;
        }
        if (x%2) {
            cout << "NO" << endl;
        } else if (x == (2*y) ) {
            cout << "YES" << endl; 
        } else if (y%2 == 0) {
            cout << "YES" << endl;
        } else if(((x+2*y)/2) % 2) {
            long long int half = (x+2*y)/2 ;
            if(2*y > half) {
                long long int newY = (half -1)/2;
                newY = y - newY ;
                if((x-1 + 2*newY) == half) {
                    cout << "YES" << endl ;
                } else {
                    cout << "NO" << endl ;
                }
            } else {
                long long int newX = half - 1 - 2*y ;
                newX = x - newX ;
                if(half == (newX - 1)) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl ;
                }
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}