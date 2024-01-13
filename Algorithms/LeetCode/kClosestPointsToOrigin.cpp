class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>> > pq ;
        int n = points.size() ;
        for(int i = 0; i < n; i++){
            pq.push({sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)), points[i]});
        }
        
        while(pq.size() > k) {
            cout << "popping: " << pq.top().first << endl ; 
            pq.pop() ;
        
        }
        vector<vector<int>> ans(k) ;
        for(int i = 0; i < k ;i++) {
            ans[i] = pq.top().second ;
            
            pq.pop() ;
        }
        return ans ;
        
    }
};
