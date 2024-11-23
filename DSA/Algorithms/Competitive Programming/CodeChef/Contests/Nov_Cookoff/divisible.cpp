#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
    long long int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        long long int *arr = new long long int[n];
        long long int arrSum = 0, one = 0, two = 0 ;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arrSum += arr[i];
            if(arr[i]%3 == 1) one++;
            else if(arr[i]%3 == 2) two++;
        }

        if(one == two) {
            cout << one << endl;
        } else if(arrSum % 3 != 0) {
            cout << -1 << endl;
        } else {
            cout << (one+two)/2 << endl;
        }
    
    }
    return 0;
}