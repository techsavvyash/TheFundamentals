#include <bits/stdc++.h>
using namespace std;


bool bfs(int **residualCapacity, int src, int sink, int n, int *parent) {
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    queue<int> que;

    visited[src] = true ;

    que.push(src);

    bool foundAugumentedPath= false;

    while(!que.empty()) {
        int u = que.front();
        que.pop();

        for(int v =0;v <n;v++) {
            if(visited[v] == false && residualCapacity[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                que.push(v);
                if(v == sink) {
                    foundAugumentedPath = true;
                    break;
                }
            }
        }
    }

    return foundAugumentedPath ;
}


void printAugumentedPaths(vector<vector<int> > augumentedPaths) {
    for(int i=0;i<augumentedPaths.size();i++) {
        cout << "Path " << i+1 << ": " << endl;
        for(int j = 0; j<augumentedPaths[i].size() - 1;j++) {
            cout << augumentedPaths[i][j] << " -> " ;
        }
        cout << augumentedPaths[i][augumentedPaths[i].size()-1] << endl ;
    }
}

int maxFlow(int **capacity, int src, int sink, int v) {
    int **residualCapacity = new int*[v];
    for(int i = 0;i<v;i++) {
        residualCapacity[i] = new int[v];
    }

    for(int i = 0;i<v;i++) {
        for(int j = 0;j<v;j++) {
            residualCapacity[i][j] = capacity[i][j];
        }
    }

    int *parent = new int[1000];
    vector<vector<int>> augumentedPaths ;
    int max_flow = 0;

    while(bfs(residualCapacity, src, sink, v, parent)) {
        vector<int> currentAugumentedPath;
        int flow = INT_MAX ; 
        int temp = sink;
        while(temp != src) {
            currentAugumentedPath.push_back(temp);
            int u = parent[temp];
            if(flow > residualCapacity[u][temp]) {
                flow = residualCapacity[u][temp];
            }
            temp = u;
        }
        currentAugumentedPath.push_back(src);
        reverse(currentAugumentedPath.begin(), currentAugumentedPath.end());
        augumentedPaths.push_back(currentAugumentedPath);
        max_flow += flow ;

        temp = sink;
        while(temp != src) {
            int u = parent[temp];
            residualCapacity[u][temp] -= flow ;
            residualCapacity[temp][u] += flow ;
            temp = u ;
        }
    }

    printAugumentedPaths(augumentedPaths);
    return max_flow ;
}

int main() {
    int v, e;
    cin >> v >> e;
    int **capacity = new int*[v] ;

    for(int i=0;i<v;i++) {
        capacity[i] = new int[v];
    }

    for(int i=0;i<e;i++) {
        int u,v ,c;
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }

    cout << maxFlow(capacity, 0, 5, v) << endl;
}