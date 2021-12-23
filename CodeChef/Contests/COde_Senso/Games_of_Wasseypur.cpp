#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        string s;
        long long int n;
        cin >> n;
        cin >> s;
        int idxs = 0 ;
        for(int i=0;s[i]!='\0';i++) {
            if(s[i] != s[i+1]) {
                idxs++;
            }
        }
        //cout << idxs << " " ;
        cout << (idxs&1 ? "SAHID" : "RAMADHIR") << endl;  
    }
    return 0;
}