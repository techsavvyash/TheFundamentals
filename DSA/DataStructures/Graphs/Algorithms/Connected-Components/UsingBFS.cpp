#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;

void bfs(unordered_map<int, list<int>> adjList,
         unordered_map<int, bool> &visited, int src) {
  queue<int> bfsQ;
  bfsQ.push(src);

  while (!bfsQ.empty()) {
    int vertex = bfsQ.front();
    bfsQ.pop();

    visited[vertex] = true;

    for (auto nbr : adjList[vertex]) {
      if (!visited[nbr]) {
        visited[nbr] = true;
        bfsQ.push(nbr);
      }
    }
  }
}

int main() {

  unordered_map<int, list<int>> adjList; // adjacency list of graph
  unordered_map<int, bool>
      visited; // map that stores the visited status of a vertex
  cout << "Enter the number of edges in your graph: ";
  int edges;
  cin >> edges;

  // getting the graph input
  for (int i = 0; i < edges; i++) {
    int src, dest;
    cout << "Enter src -> dest separated by white space: ";
    cin >> src >> dest;

    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
    visited[src] = false;
    visited[dest] = false;
  }

  // iterating over the map to find the unvisited nodes
  int numComponents = 0;

  for (auto vertex : visited) {
    if (!vertex.second) {
      numComponents++;
      bfs(adjList, visited, vertex.first);
    }
  }

  cout << "Number of connected components in the graph is: " << numComponents
       << endl;

  return 0;
}
