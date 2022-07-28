#include<iostream>
#include <bits/stdc++.h>
using namespace std ;

class Node {
  public:
    bool isTerminal ;
    char data ;
    unordered_map<char, Node*> h ;

    Node(char ch) {
      data = ch ;
      isTerminal = false ;
    }
};


class Trie {
  Node* root ;

  public:
  Trie() {
    root = new Node('\0');
  }


  void insert(char* word) {
    Node* temp = root ;
    for(int i = 0; i < word[i] != '\0'; i++) {
      char ch = word[i];
      if(temp->h.count(ch)) {
        temp = temp->h[ch];
      } else {
        temp->h[ch] = new Node(ch) ;
        temp = temp->h[ch] ;
      }
    }
    temp->isTerminal = true ;
  }

  bool search(char *word) {
    Node* temp = root ;
    for(int i = 0; word[i] != '\0'; i++) {
      if(temp->h.count(word[i])) {
        temp = temp->h[word[i]] ;
      } else return false ;
    }

    return temp->isTerminal ;
  }
};



int main() {
  char word1[] = "Yash";
  
  char word2[] = "kirti" ;

  Trie *t = new Trie() ;
  t->insert(word1);
  t->insert(word2);

  cout << (t->search(word1) ? "Present" : "Not present") ;
  char word3[] = "jumbo";
 
  cout << (t->search(word3) ? "Present" : "Not present") ;


  return 0;
}
