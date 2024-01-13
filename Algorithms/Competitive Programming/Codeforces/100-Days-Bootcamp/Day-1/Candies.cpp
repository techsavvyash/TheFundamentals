#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, a, b;
    cin >> n;
    long long int *arr = new long long int[n] ;
    for(long long int i=0;i<n;i++) {
        cin >> arr[i] ;
    }
    cin >> a >> b;
    long long int sum = 0;
    for(long long int i = a ; i<=b;i++) {
        sum += arr[i] ;
    }
    cout << sum << endl;

    return 0;
}