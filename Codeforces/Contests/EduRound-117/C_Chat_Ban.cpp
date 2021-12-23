#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    
    while(t--) {
        long long int k, x;
        cin >> k >> x;
        if(((k-1) * (k)) + k <= x) {
            cout << (2*k - 1) << endl;
            continue;
        }  

        if((k*(k+1))/2 > x) {
            int sum = 0, count = 0;
            while(sum < x) {
                sum += count + 1;
                count++ ;
            }
            cout << count << endl;
        } else {
            int count = 0;
            x -= (k*(k+1))/2;
            while(x > 0) {
                x -= k - count - 1 ;
                count++;
            } 
            cout << k + count << endl;
        }
    }


    return 0;
}