//problem link: https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0] ;
        int count = str.length() ;
        for(int i = 1;i<strs.size();i++) {
            if(count == 0) {
                break ;
            }
            if(strs[i].length() < str.length()) {str = str.substr(0, strs[i].length()); }
            for(int j = 0;j<min(str.length(), strs[i].length());j++) {
                if(str[j] != strs[i][j]) {
                    count = j ;
                    str = str.substr(0, j) ;
                }
            }
        }
        
        return str ;
    }
};