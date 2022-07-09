#include <iostream>
#include "trie.h"


int main() {
  string yash = "yash" ;
  string kirti = "kirti" ;
  Trie* newTrie = new Trie() ;

  newTrie->insertKey(yash);

  cout << (newTrie->findKey(yash) ? "key present" : "key not present") << endl ;

  cout << (newTrie->findKey(kirti) ? "key present" : "key not present" ) << end; ;


  return 0;
}
