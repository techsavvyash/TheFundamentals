#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // pair<vertex, weight>
    unordered_map<int, list<pair<int, int>>> adjList;

public:
    Graph()
    { /*default constructor*/
    }

    bool addEdge(int src, int dest, int weight)
    {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});

        return true;
    }

    void dijkstra(int src)
    {
        /*
        Dijkstra is a single source shortest path algorithm based on
        the greedy strategy. At each path we take the least possible
        cost path.
        */
    }
};

int main()
{

    return 0;
}