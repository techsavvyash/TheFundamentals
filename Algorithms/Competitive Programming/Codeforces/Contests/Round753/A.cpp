#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int i = 0;
        string keyBoard, s;
        cin >> keyBoard ;
        cin >> s;
        unordered_map<char, int> board ;
        for(int i=0,j=0;keyBoard[i]!='\0';i++) {
            board[keyBoard[i]] = ++j ;
        }
        //calculating time
        int time = 0;
        for(int i=1;s[i];i++) {
            if(s[i]!=s[i-1]) {
                time += abs(board[s[i]]-board[s[i-1]]);
            }
        }

        cout << time << endl;
    }
}