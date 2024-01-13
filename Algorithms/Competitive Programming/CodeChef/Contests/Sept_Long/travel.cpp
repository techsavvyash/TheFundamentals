#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>> t;
    while(t--) {
        
        int n, a, b, id = 0, is = 0;
        cin >> n >> a >> b ;

        string s;
        cin >> s;

        for(int i=0;s[i]!='\0';i++) {
            if(s[i] == '0') id++;
            else if(s[i] == '1') is++;
        }
        cout << (a*id + b*is) <<endl;

    }
    
    return 0;
}