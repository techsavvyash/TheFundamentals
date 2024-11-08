//problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //in this we basically need to sum all the differences
        int maxProfit = 0 ;
        for(int i = 1;i<prices.size();i++) {
            if(prices[i] > prices[i-1]) {
                maxProfit += (prices[i] - prices[i-1]) ;
            }
        }
        
        return maxProfit ;
    }
};