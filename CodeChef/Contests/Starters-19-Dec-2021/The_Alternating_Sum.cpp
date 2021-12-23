#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        long long int *arr = new long long int[n];
        long long int *sums = new long long int[n];
        int mul = 1; long long int sum = 0;
        cin >> arr[0];
        sums[0] = arr[0];
        for(int i = 1;i<n;i++ ) {
            cin >> arr[i] ;
            sums[i] = sums[i-1] + mul*arr[i];
            mul *= -1 ;
        }
        long long int *finalMax = new long long int[n] ;
        int i = 1 ;
        if(n%2) {
            
        } else {

        }
    }
    }
    return 0;
}