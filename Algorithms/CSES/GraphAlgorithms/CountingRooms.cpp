#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std ;

/**
 * Problem link: cses.fi/problemset/task/1192
 * What do we need to find?
 * We need to find the number of rooms that exist in the entered graph
 * How to identify a room?
 * A room is identified as floors enclosed within walls
 *
 * What is the logic behind the problem?
 * We will definitely need to traverse the graph -> i.e. either BFS or DFS
 * consider an example graph shown below!

########
#..#...#
####.#.#
#..#...#
########
  
* In this graph we will have 3 rooms, 
* the first room are the two floors connected 
* together in the second row,
* the second row are the similarly connected floors
* in the fourth row
* and the third room is made by the 
* floors connected from the second row to the forth row
*
* Hence we can see that the problem reduces down to being a problem of finding 
* the number of connected components in a graph, where the only nodes are the 
* ones marked by dots as per the question.
*
* The components can be simply found using BFS or DFS! --> not always kosaraju is required
 **/


void bfs(vector<string> graph) {
  // fn for breadth first traversal of the tree
    
  bool visited[1000][1000] = {0} ;

  queue<int> bfsQ ;
    



  return ;
}


int main() {
  int n, m; 
  cin >> n >> m ;
  
  vector<string> graph ;

  for(int i = 0; i < n; i++) {
    string str; cin >> str ;
    graph.push_back(str) ;
  }

  // traversing the graph for the BFS
  for(int i = 0; i < n; i++) {
    cout << graph[i] << endl ;
  }

  

  

  return 0;
} 
