#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph {
  unordered_map<int, list<int>> adjList;

public:
  Graph() { /*default constructor*/
  }

  bool addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);

    return true;
  }

  unordered_map<int, int> findDistances(int src) {

    unordered_map<int, int> distances;
    queue<int> vertexQ;

    // setting initial distances are infinity
    for (auto node : adjList) {
      distances[node.first] = INT_MAX;
    }

    vertexQ.push(src);
    distances[src] = 0;

    while (!vertexQ.empty()) {
      int node = vertexQ.front();
      vertexQ.pop();

      for (auto nbr : adjList[node]) {
        if (distances[nbr] == INT_MAX) {
          // this means that the node has not been visited till now
          distances[nbr] =
              distances[node] + 1; // +1 since it is an undirected graph
          vertexQ.push(nbr);
        }
      }
    }

    return distances;
  }
};

int main() {

  cout << "Enter the graph: " << endl;
  cout << "Enter the number of edges: ";
  int edges;
  cin >> edges;
  Graph *g = new Graph();

  for (int i = 0; i < edges; i++) {
    int src, dest;
    cout << "Enter src -> dest: separated by space: ";
    cin >> src >> dest;
    g->addEdge(src, dest);
  }

  cout << "Enter the source for SSSP: ";
  int src;
  cin >> src;
  unordered_map<int, int> distances = g->findDistances(src);

  for (auto node : distances) {
    cout << "Distance of " << node.first << " from " << src
         << " is: " << node.second << endl;
  }

  return 0;
}
