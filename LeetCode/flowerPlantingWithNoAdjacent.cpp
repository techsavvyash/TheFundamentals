
/*This is just simple graph coloring*/

class Solution {
public:
    map<int, int> colors ;
    map<int, list<int>> adj ;
    
    bool canBeColoured(int vertex, int color) {
        for(auto nbr: adj[vertex]) {
            if(colors[nbr] == color) {
                return false ;
            }
        }
        
        return true ;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //this is the simple graph colouring problem
        //I either need to use backtracking or implement the algorithm I made
        
        if(paths.size() == 0) {
            vector<int> ans ;
            for(int i = 0; i < n; i++) ans.push_back(1) ;
            return ans ;
        }
        
        int len = paths.size() ;
        for(int i = 0; i < len ; i++) {
            adj[paths[i][0]].push_back(paths[i][1]) ;
            adj[paths[i][1]].push_back(paths[i][0]) ;
        }
        
        for(auto node: adj) {
            for(int i = 1; i < 5; i++) {
                if(canBeColoured(node.first, i)) {
                    colors[node.first] = i ;
                    break ;
                }
            }
        }
        
        
        vector<int> ans(n) ;
        
        for(auto node: colors) {
            ans[node.first - 1] = node.second ;
        }
        
        for(int i = 0; i < n; i++) {
            if(ans[i] == 0) {
                ans[i] = 1 ;
            }
        }
        
        return ans ;
        
        
    }
};
