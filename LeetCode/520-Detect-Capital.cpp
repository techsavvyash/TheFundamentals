class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int len = word.size() ;
        int nums = 0 ;
        for(int i = 1; i < len; i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') nums++ ;
        }

        if(word[0] >= 'a' && word[0] <= 'z') {
            return nums == 0;
        }
        
        return (nums + 1 == len || nums == 0) ;
    }
};