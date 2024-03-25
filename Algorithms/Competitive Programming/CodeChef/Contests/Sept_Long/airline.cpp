#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b, c, d, e;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d>>e;
        if(a+b+c > d+e) {
            cout<<"No"<<endl;
            continue;
        } else if((a+b > d && c > e) || (a+c > d && b > e) || (b+c > d && a > e) ){
            cout << "Yes" <<endl;
        } else {
            cout << "Yes" << endl;
        }

    }
    
    return 0;
}