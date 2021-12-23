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
        if(x%2 == 0) {
            if(x == 0 && y%2 != 0) {
                cout << "NO" << endl;
            } else if(x == 0 && y%2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}