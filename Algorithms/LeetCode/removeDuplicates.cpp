//problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, k = 0;
        if(nums.size() == 0) {
            return k ;
        }
        for(i = 0, k = 0;i < nums.size() - 1 ; i++) {
            if(nums[i] != nums[i+1]) {
                nums[k++] = nums[i] ;
            }
        }
        
        if(nums.size() > 0) { nums[k++] = nums[nums.size()-1] ; } ;
        
        return k ;
    }
};