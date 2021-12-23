#include <iostream>
#include <string>
using namespace std;

long long int countV(char *subStr) {
    long long int count = 0;

    for(int i=0;subStr[i];i++) {
        if(subStr[i] == 'a' || subStr[i] == 'e' || subStr[i] == 'i' || subStr[i] == 'o' || subStr[i] == 'u'  ) count++ ;
    }

    return count ;
}


long long int findSubStr(string word, char *outPut, long long int wIdx, long long int outIdx, long long int &count) {
    if(word[wIdx] == '\0') {
        outPut[outIdx++] = '\0' ;
        return count + countV(outPut);
    }

    //include
    outPut[outIdx++] = word[wIdx++] ;
    findSubStr(word, outPut, wIdx+1, outIdx + 1, count);
    //don't include
    findSubStr(word, outPut, wIdx+1, outIdx, count);
    return count ;
}



long long int countVowels(string word) {
    long long int count = 0;
    char *outPut ;
    return findSubStr(word, outPut, 0, 0, count) ;
}




int main() {
    string str;
    cin >> str;
    cout << countVowels(str) << endl ;
    return 0;
}