#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;
    long long int count = 0;
    for(int i = 0;i<str.length() - 1;i++) {
        if(count >= 6) {
            cout << "YES" << endl;
            return 0;
        }
        if(str[i] == str[i+1]) count++ ;
        else count = 0;
    }

    if(count >= 6) cout << "YES" << endl;
    else cout << "NO" << endl;




    return 0;
} 