
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;

    long long int t;
    cin>>t;
    while(t--) {
        long long int n;
        cin>>n;
        long long int *arr = new long long int[n];
        for(long long int i=0;i<n;i++) {
            cin>>arr[i];
        }

        long long int answer = 0;
        for(long long int i=0;i<n;i++){
            long long int minimum = arr[i];
            long long int maximum = arr[i];
            
            set<long long int> s;
            
            for(long long int j=i;j<n;j++){
                s.insert(arr[j]);
                maximum = max(maximum,arr[j]);
                minimum = min(minimum,arr[j]);
                if(j-i<2) continue;
                long long int b = 0;
                auto posn = s.lower_bound((maximum+minimum)/2);
                if(posn != s.end()){
                    b = max(b,(maximum-(*posn))*((*posn)-minimum));
                }

                if(posn!=s.begin()){
                    posn--;
                    b=max(b,(maximum-(*posn))*((*posn)-minimum));
                }

                answer += b;
            }

        }
        cout<<answer<<endl;
    }

    return 0;
}