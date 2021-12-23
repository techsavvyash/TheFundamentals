#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long int t;
    cin >> t;
    while(t--) {
        long long int n, *arr;
        cin >> n;
        arr = new long long int[n+1];
        unordered_map<int, list<int> > tree ;
        for(int i=0;i<n;i++) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b) ;
        }
        arr[0] = 1 ;
        for(int i=1;i<=n;i++) {
            cin >> arr[i] ;
        }
        unordered_map<int, bool> visited ;
        queue<int> q;
        q.push(1);
        visited[1] = true ;        
        long long int yield = 1;
        while(!q.empty()) {
            long long int src = q.front();
            // cout << src << " ";
            yield = max(yield, (yield*arr[src])) ;
            q.pop();
            visited[src]  = true;
            for(auto nbr : tree[src] ) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        cout << yield%(1000000000+7) << endl;
    }
    return 0;
}