#include <vector>
using namespace std ;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, pair<int, bool>> m;
        for(int i = 0;i<nums.size();i++) {
            if(m[nums[i]].second && abs(m[nums[i]].first - i)<=k) { return true;}
            
            m[nums[i]] = make_pair(i, true) ;
    
        }
        
        return false ;
    }
};
