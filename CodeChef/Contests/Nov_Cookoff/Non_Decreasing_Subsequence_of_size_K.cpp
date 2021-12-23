#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, k;
        cin >> n >> k;
        long long int *arr = new long long int[n] ;
        priority_queue<long long int> pq ;
        for(int i=0;i<n;i++) {
            cin >> arr[i] ;
            pq.push(arr[i]);
        }
        arr[k-1] = pq.top(); pq.pop() ;
        

        for(int i = k;i<n;i++) {
            arr[i] = pq.top() ;
            pq.pop();
        }

        for(int i=k-2;i>=0;i--) {
            arr[i] = pq.top(); 
            pq.pop() ;
        }

        bool flag = true ;
        long long int len = 0;
        long long int repeating;
        for(int i=k;i<n-1;i++) {
            if(len>=k) {
                flag = false ;
                break ;
            }
            if(arr[i] <= arr[i+1]) {
                len++ ;
                if(len >=k) {
                    flag = false;
                    repeating = i;
                    break;
                }
            } else {
                len = 0;
            }
        }
        if(len >= k && flag) flag = false ;
        
        if(flag) {
            for(int i=0;i<n;i++) {
                cout << arr[i] << " ";
            }
            cout << endl ;
        } else cout << -1 << endl ;
        
    }


    return 0;
}