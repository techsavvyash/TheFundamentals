#include <iostream>
#include <string>
#include <stack>
#include <set>
using namespace std;


void generateParenthesis(char *output, int n, int currentIdx, int countOpen, int countClose, set<string> &patterns) {
    //base case
    if(currentIdx == 2*n) {
        output[currentIdx] = '\0';
        string s = output;
        patterns.insert(s);
        return;
    }

    //recursive casse

    if(countOpen < n) {
        output[currentIdx] = '(';
        generateParenthesis(output, n, currentIdx+1, countOpen+1, countClose, patterns);
    }

    if(countClose < countOpen) {
        output[currentIdx] = ')';
        generateParenthesis(output, n, currentIdx+1, countOpen, countClose+1, patterns);
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        int n, i=0;
        cin>>n;
        char output[1000];
        set<string> patterns;
        set<string>::iterator it = patterns.begin();
        generateParenthesis(output, n, 0, 0, 0, patterns);
        for(int i=0;i<n;i++) {
            cout << (*it) << endl;
            it++;
        }    
    }
    
    return 0;
}