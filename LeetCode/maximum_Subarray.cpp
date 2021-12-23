//prob link: https://leetcode.com/problems/maximum-subarray/
#include <climits>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //basic implementation of the kaden's algo
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0;i<nums.size();i++) { 
            sum += nums[i];
            if(maxSum < sum) maxSum = sum ;
            if(sum < 0) sum = 0 ;
            
        }
        return maxSum ;
    }
};