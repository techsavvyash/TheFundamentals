class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     priority_queue<int> pq ;
        int len = stones.size() ;
        for(int i = 0; i < len; i++) {
            pq.push(stones[i]);
        }
        
        while(pq.size() > 1) {
            int x = pq.top() ; pq.pop() ;
            int y = pq.top() ; pq.pop() ;
            
            if(y == x) {
                continue ;
            } else {
                pq.push(abs(y-x)) ;
            }
        }
        
        return (pq.empty() ? 0 : pq.top()) ;
    }
};
