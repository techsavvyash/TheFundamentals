//problem link: https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0, carry = 1; bool flag = true ;
        vector<int> res ;
        for(int i = digits.size() - 1 ; i >= 0 ; i--) {
            sum = digits[i] + carry ;
            if(sum < 10) {
                digits[i] = sum ;
                flag = false ;
                break ;
            } else {
                digits[i] = (sum % 10) ;
                carry = (sum / 10) ;
            }
        }
        if(flag) {
            res.push_back(carry) ;
        }
            for(int i = 0;i<digits.size();i++){
                res.push_back(digits[i]);
            }
        
        return res ;
    }
};