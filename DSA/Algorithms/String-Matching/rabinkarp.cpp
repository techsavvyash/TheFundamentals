#include <iostream>
#include <string>
using namespace std;

const int m = 1e9 + 7 ;
const int prime = 31;
int powr(int a, int b) { //binary exponentiation
    int res = 1;

    while(b) {
        if(b&1ll){
            res *= a;
            res %= m;
        }
        b /= 2;
        a *= a;
        a %= m ;
    }
    return res ;
}


int inv(int a) {
    //a^-1 % m
    return powr(a, m - 2);
}

int poly_hash_string(string s) {
    
    int p_powr = 1;
    int hash = 0;
    for(int i=0;i<s.size();i++) {
        hash += (p_powr * (s[i] - 'a' + 1));
        p_powr *= prime;
        p_powr %= m;
        hash %= m;
    }

    return hash;
}

int main() {
    string text = "ababab", pat = "aba";
    int pat_hash = poly_hash_string(pat);
    int text_size = text.size(), pat_size = pat.size();

    int text_hash = poly_hash_string(text.substr(0, pat_size));
    if(text_hash == pat_hash) {
        cout << 0 << '\n';
    }

    for(int i = 0;i + pat_size <= text_size;i++) {
        int new_hash = poly_hash_string(text.substr(i, i+pat_size));
        cout << "pat_hash: " << pat_hash << " " << "new_hash: " << new_hash << endl;
        if(new_hash == pat_hash) {
            cout << i << endl;
        }
    }

    /*for(int i = 1;i + pat_size <= text_size;i++) {
        int new_hash = text_hash ;
        new_hash = (new_hash - (text[i - 1] - 'a' + 1) + m) % m;

        new_hash *= inv(prime);
        new_hash %= m ;

        new_hash = new_hash + (text[i + pat_size - 1] - 'a' + 1)*powr(prime, pat_size - 1);
        new_hash %= m ;
        //cout << new_hash%m << " " << pat_hash<< endl;
        if(new_hash == pat_hash) {
            cout << i << endl;
        }
        text_hash = new_hash ;
    }*/
    return 0;
}