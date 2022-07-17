#include <unordered_map>
#include <string>
using namespace std ;
class TrieNode {
  char ch ; //the character stored at this particular node
  unordered_map<char, TrieNode*> children ; // a hasmap that stores the address of the child nodes of this trie
  bool isTerminal ; // a flag to see if the node is terminal or not

public:
  TrieNode() {/*default constructor*/}

  TrieNode(char _ch) {
  /* parameterised constructor with data element as the parameter*/
    this->ch = _ch ;
    this->isTerminal = false ;
  }

  friend class Trie ;
};


class Trie {
  TrieNode* root;

public:
    Trie() {
      /*default constructor*/
      root = new TrieNode('\0') ;
    }


    bool insertKey(string _str) {
      TrieNode* branchNode = root ;
      for(char ch: _str) {
        if(branchNode->children.count(ch) == 0) {
          TrieNode* newNode = new TrieNode(ch) ;
          branchNode->children[ch] = newNode ;
        }
        branchNode = branchNode->children[ch] ;
      }


      return true ;
    }


    bool findKey(string _str) {
      TrieNode* branchNode = root ;
      int length = _str.length();
      for(int i = 0; i < length; i++) {
        if(branchNode->children.count(_str[i]) == 0) {
          return false ;
        }

        if(i == length-1 && !branchNode->children[_str[i]]->isTerminal ) return false ;
        branchNode = branchNode->children[_str[i]] ;
      }

      return true ;
    }

};


int main() {

  return 0;
}
