#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int graph[6][6] = {0} ;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;
    graph[2][5] = 1;
    int distance[6] ;
    bool visited[6] ;
    for(int i=0;i<6;i++) {
        visited[i] = false;
        distance[i] = INT_MAX ;
    }
    visited[1] = true ;
    distance[1] = 0;
    
    queue<int> bfsQ;
    bfsQ.push(1);

    while(!bfsQ.empty()) {
        int first = bfsQ.front();
        cout << first << " ";
        bfsQ.pop();

        for(int i=1;i<6;i++){
            if(graph[first][i] == 1) {
                if(visited[i] == false) {
                    visited[i] = true ;
                    bfsQ.push(i);
                    if (distance[i] > distance[first] + 1) {
                        distance[i] = distance[first] + 1 ;
                    }
                }
            }
        }
    }
    cout << endl << "Distances are: " << endl;
    for(int i=1;i<6;i++) {
        cout << i << ": " << distance[i] << endl;
    }

    return 0;
}