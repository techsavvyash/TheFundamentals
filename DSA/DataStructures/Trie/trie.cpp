#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

class Node {
  // class representing a single node of a trie
  char ch;// the actual character to be stored at a node
  unordered_map<char, Node*> children ; // a hashmap to store the address of its children
  bool isTerminal ; // a flag to store if a given node is terminal or not
  public:
    Node() {
      // default constructor
    }

    Node(char ch) {
      // parametarised constructor
      this->ch = ch;
      this->isTerminal = false ;
    }

    friend class Trie ;
};

class Trie {
 // class representing a trie
 Node *root ;
  public:
    Trie() {
      // default constrctur ;
      root = new Node('\0');
      //the constructor simply creates a null node for the trie root
    }

    void insertKey(string str) {
      Node* temp = this->root ;
      for(auto ch: str) {
        if(temp->children.find(ch) == temp->children.end()) {
          // this is the case when the particular character does not exist 
          // as a child of the particular trie node

          temp->children[ch] = new Node(ch) ;
        }
        temp = temp->children[ch] ; // updating temp go downwards in the trie
      }
    }

    bool findKey(string str) {
      Node* temp = this->root ;
      for(auto ch: str) {
        if(temp->children.find(ch) == temp->children.end()) return false ;
        temp = temp->children[ch] ;
      }

      return temp->isTerminal ;
    }
};

int main() {
  string yash = "yash" ;
  string kirti = "kirti" ;
  Trie* newTrie = new Trie() ;

  newTrie->insertKey(yash);

  cout << (newTrie->findKey(yash) ? "key present" : "key not present") << endl ;

  cout << (newTrie->findKey(kirti) ? "key present" : "key not present" ) << endl ;


  return 0;
}
