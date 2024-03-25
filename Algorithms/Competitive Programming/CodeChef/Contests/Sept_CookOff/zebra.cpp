#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        int i=1, bit = s[0] - '0', jumps = 0;
        while(s[i + 1] != '\0' && (jumps < k)) {
            if(s[i] == (!bit + '0') && s[i+1] == (bit + '0')) {
                bit = !bit;
                jumps++;
            }
            i++;
        }
        if(i == (s.length()-1) && jumps != k) {
            cout << -1 <<endl;
            continue;
        } 

        int i = s.length()-1;
        if(s[0] == '1') {
            
            if(k&1) {
                while(s[i]!= '0'){
                    i--;
                }
                cout << (i+1) << endl;
            } else {
                while(s[i] != '1') {
                    i--;
                }
                cout << (i+1) << endl;
            }
        } else {
            if(k&1) {
                while(s[i] != '1') {
                    i--;
                }
                cout << (i+1) <<endl;
            } else {
                while(s[i] != '0') {
                    cout << (i+1) << endl;
                }
            }
        }
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    char res = s[0];
    int cnt =0;
    for(int i=1;i<n;i++) {
        if(res != s[i]) {
            cnt++;
            res = s[i];
        }
    }

    if(cnt<k) {
        cout<<-1<<"\n";
        return;
    }
    if(s[0]=='0') {
        if(k%2) {
            for(int i=s.size()-1; i>=0; i--) {
                if(s[i] == '1') {
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
        else {
            for(int i=s.size()-1; i>=0; i--) {
                if(s[i] == '0') {
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
    }
    else {
        if(k%2) {
            for(int i=s.size()-1; i>=0; i--) {
                if(s[i] == '0') {
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
        else {
            for(int i=s.size()-1; i>=0; i--) {
                if(s[i] == '1') {
                    cout<<i+1<<"\n";
                    return;
                }
            }
        }
    }

}
int main()
{
    //fast input and output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}