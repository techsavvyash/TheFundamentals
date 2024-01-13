#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    char ans[100];
    cin >> str;
    
    int count = 0;
    for(int i=0;i<str.length();i++) {
        if(tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u' || tolower(str[i]) == 'Y') {
            continue;
        } else {
            ans[count++] = '.' ;
            ans[count++] = tolower(str[i]);
        }
    }
    ans[count] = '\0' ;
    cout << ans ;
    return 0;
}