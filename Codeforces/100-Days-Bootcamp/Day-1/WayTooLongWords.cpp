#include <iostream>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n;
    cin >> n;
    string *s = new string[n] ;

    for(long long int i=0;i<n;i++) {
        cin >> s[i];
    }

    for(long long int i = 0; i< n;i++) {
        if(s[i].length() > 10) {
            string str = s[i];
            s[i] = str[0] + to_string(str.length()-2) + str[s[i].length()-1] ;
        }
    }

    for(long long int i=0;i<n;i++) {
        cout << s[i] << endl;
    }

    return 0;
} 