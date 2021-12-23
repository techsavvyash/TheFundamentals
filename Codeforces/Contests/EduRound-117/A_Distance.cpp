#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long int t;
    cin >> t;
    while(t--) {
        long long int x, y;
        cin >> x >> y;
        if((x + y)%2) {
            cout << -1 << " " << -1 << endl;
            continue ;
        }
        cout << floor(x/2) << " " << ceil(y*1.0/2) << endl ;

    }
    return 0;
}