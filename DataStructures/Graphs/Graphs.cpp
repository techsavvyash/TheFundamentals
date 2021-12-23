#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    unordered_map<int, list<int> > adj;
public:
    void addEdge(int src, int dest) {
        adj[src].push_back(dest) ;
        adj[dest].push_back(src) ;
    }

    void bfs(int src) {
        unordered_map<int, int> distance ;
        unordered_map<int, bool> visited ;
        for(auto node: adj) {
            visited[node.first] = false;
            distance[node.first] = INT_MAX ;
        }
        visited[src] = true ;
        distance[src] = 0;
        queue<int> bfsQ ;

        bfsQ.push(src) ;

        while(!bfsQ.empty()) {
            int first = bfsQ.front() ;
            cout << first << " ";
            bfsQ.pop() ;

            for(auto nbr: adj[first]) {
                if(!visited[nbr]) {
                    bfsQ.push(nbr);
                    visited[nbr] = true ;
                    if(distance[nbr] > distance[first] + 1) {
                        distance[nbr] = distance[first] + 1 ;
                    }
                }
            }
        }
        cout << endl << "Distances are: " << endl;
        for(auto node: distance) {
            cout << node.first << ": " << node.second << endl;
        }
    }

};


int main() {
    Graph g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.bfs(1) ;

    return 0;
}