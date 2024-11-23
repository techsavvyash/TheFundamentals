#include <iostream>
#include <bits/stdc++.h>
using namespace std ;


void DFSRecursive(unordered_map<int, list<int>> adjList, unordered_map<int, bool> &visited, int src) {


  cout << src << " ";
  visited[src] = true ;

  for(auto nbr: adjList[src]) {
    if(!visited[nbr]) {
      DFSRecursive(adjList, visited, nbr);
    }
  }
}

int main() {
  unordered_map<int, list<int>> adjList;
  unordered_map<int, bool> visited;
  int edges;
  cout << "Enter the number of edges in the graph: ";
  cin >> edges;

  for (int i = 0; i < edges; i++) {
    cout << "Enter src -> dest :";
    int src, dest;
    cin >> src >> dest;

    adjList[src].push_back(dest);
    adjList[dest].push_back(src);

    visited[src] = false;
    visited[dest] = false;
  }

  cout << "Enter the starting vertex of traversal: ";
  int start;
  cin >> start;

  cout << "BFS traversal of the components starting with " << start << " is: ";
  DFSRecursive(adjList, visited, start);
  cout << endl ;
  return 0;
}
