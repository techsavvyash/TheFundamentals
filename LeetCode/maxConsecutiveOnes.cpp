//problem link: https://leetcode.com/problems/max-consecutive-ones
#include <climits>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int numNow = 0, maxNum = INT_MIN ;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == 1) {
                numNow++ ;
            } else if(nums[i] == 0) {
                maxNum = (maxNum > numNow) ? maxNum : numNow ;
                numNow = 0;
            }
        }
        maxNum = (maxNum > numNow) ? maxNum : numNow ;
        return maxNum ;
    }
};