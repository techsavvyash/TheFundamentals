#include <bits/stdc++.h>
#include <functional>
#include <iostream>
using namespace std;

/*
 * What is topological sort?
 * It is a linear ordering of the vertices of the graph
 * such that the vertices are ordered in terms of their in degree.
 * A topological sort is only possible for Directed Acyclic Graphs (DAGs)
 * They are used when we need to show dependencies of one thing over the other
 * and need an ordering where we need to find a point which is least dependent.
 *
 * What do we need to do ?
 * We basically need to calculate the indegree of every vertex and
 * then arrange the vertices in increasing order of the indegree
 *
 * NOTE: In-Degree of a node refers to the number of directed edges that have
 * the node as destination.
 *
 * To calculate the indegrees we can simply use a traversal, traverse over the
 * graph and calculate the indegree .
 */

int main() {

  unordered_map<int, list<int>> adjList;
  map<int, int> indegrees;
  int edges;
  cout << "Enter the number of edges in the graph: ";
  cin >> edges;

  for (int i = 0; i < edges; i++) {
    cout << "Enter src -> dest : ";
    int src, dest;
    cin >> src >> dest;

    adjList[src].push_back(dest); // only one push since the graph is Directed
    indegrees[dest]++;

    if(indegrees.find(src) == indegrees.end()) {
      indegrees[src] = 0;
    }
  }
  // pair<indegree, vertex>
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      heap;

  for (auto vertex : indegrees) {
    heap.push({vertex.second, vertex.first});
  }

  cout << "The topological sort for the given DAG is: ";

  while (!heap.empty()) {
    cout << heap.top().second << " ";
    heap.pop();
  }
  cout << endl;

  return 0;
}
