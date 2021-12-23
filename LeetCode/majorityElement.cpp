//problem link: https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m ;
        for(int i = 0;i<nums.size();i++) {
            m[nums[i]]++ ;
        }
        int maj ;
        for(auto entry: m) {
            if(entry.second > floor(nums.size()/2)) {
                maj = entry.first ;
            }
        }
        
        return maj ;
    }
};