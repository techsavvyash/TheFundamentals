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

/**Divide and conquer approach*/

class Solution {
public:
    //lets try a d&c approach
    int majdandc(vector<int>& nums, int start, int end) {
        if(start == end) return nums[start] ;
        int mid = (start + end)/2 ;
        int left = majdandc(nums, start, mid) ;
        int right = majdandc(nums, mid + 1, end) ;
        if(left == right) {
            return right ;
        } else {
            int c1 = 0, c2 = 0;
            for(int i = start;i<=mid;i++) {
                if(nums[i] == left) c1++ ;
            }
            for(int i = mid+1;i<=end;i++) {
                if(nums[i] == right) c2++ ;
            }
            return ((c1 > c2) ? left : right);
        }
    }
    int majorityElement(vector<int>& nums) {
        return majdandc(nums, 0, nums.size()-1) ; 
    }
};
