#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(unordered_map<int, list<int>> adjList,
         unordered_map<int, bool> &visited, int src) {
  stack<int> dfsStack;
  dfsStack.push(src);

  while (!dfsStack.empty()) {
    int vertex = dfsStack.top();
    dfsStack.pop();
    visited[vertex] = true;

    for (auto nbr : adjList[vertex]) {
      if (!visited[nbr]) {
        visited[nbr] = true;
        dfsStack.push(nbr);
      }
    }
  }
}

int main() {
  unordered_map<int, list<int>> adjList;
  unordered_map<int, bool> visited;
  int edges;
  cout << "Enter the number of edges in your graph: ";
  cin >> edges;

  for (int i = 0; i < edges; i++) {
    cout << "Enter src->dest separated by white spaces: ";
    int src, dest;
    cin >> src >> dest;

    // creating the adjList
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);

    // initialising the visited map
    visited[src] = false;
    visited[dest] = false;
  }

  int numComponents = 0;

  for (auto vertex : visited) {
    if (!vertex.second) {
      numComponents++;
      dfs(adjList, visited, vertex.first);
    }
  }

  cout << "Number of connected components are: " << numComponents << endl;

  return 0;
}
