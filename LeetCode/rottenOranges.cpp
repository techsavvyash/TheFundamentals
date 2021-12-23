class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> distances ;
        vector<bool> visited ;
        int src;
        for(int i=0;i<grid.size();i++) {
            if(grid[i].size() != 0) {
                src = i ;
                distances[i] = INT_MAX ;
                visited[i] = false;
            }
        }
        distances[src] = 0 ;
        visited[src] = true ;
        int max = INT_MIN ;
        /*for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(!visited[j] && (distances[j] > distances[i] + 1)) {
                    distances[j] > distances[i] + 1 ;
                    visited[j] = true ;
                    max = (max > distances[j] ? max : distances[j]) ;
                } 
            }
        }*/
        
        return max ;
    }
};