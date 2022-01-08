#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

string removeChar(string s, char c) {
  string str = "";
  for(int i = 0; i < s.length();i++) {
    if(s[i] != c) {
      str += s[i] ;
    }
  }

  return str ;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
  ll t;
  cin >> t ;
  while(t--) {
    string s, t, r, seq = "";
    cin >> s ;
    map<char, int> freq ; int length = 0 ;
    for(int i = s.length();i >= 0;i--) {
      if(freq[s[i]] == 0) {
        seq = s[i] + seq ;
      }
      freq[s[i]]++ ;
    }
    //number of steps = number of distinct alphabets in s
    int seqLen = seq.length() ;
    for(int i = 0; i < seqLen; i++) {
      length += freq[seq[i]]/(seqLen-i) ;
    }
    r = string(s.rbegin(), s.rbegin() + length) ;
    string res = r ;
    for(auto c: seq) {
      string temp ;
      for(auto d: r) {
        if(d != c) {
          temp.push_back(d) ;
          res.push_back(d) ;
        }
        
      }
      r = temp ;
    }
    if(res == s) {
      cout << r << " " << seq << endl ;
    } else {cout << -1 << endl ;}
    /*cout << s.substr(0, length) << " " << seq << endl ;*/
    /*while(r.length() > 0) {
     
      if(floor(freq[r[r.length()-1]]/steps) != ceil((freq[r[r.length()-1]]/steps))) {
        cout << -1 << endl ;
        continue ;
      }
      length += (freq[s[s.length()-1]]/(steps--)) ;
      seq  = r[r.length()-1] + seq ;     
      r = removeChar(r, r[r.length()-1]) ;
    }
    //if we reach here then it means that s was possible and we have the length
    cout << s.substr(0, len gth) << " " << seq << endl ;
    if(floor(freq[s[s.length()-1]]/steps) != ceil((freq[s[s.length()-1]]/steps))) {
      cout << -1 << endl ;
      continue ;
    }
    length += (freq[s[s.length()-1]]/(steps--)) ;*/
  }
  return 0;
}
