//problem link: https://leetcode.com/problems/valid-parentheses


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk ; bool res = true ;
        for(int i = 0; i < s.length();i++) {
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]) ;
                continue ;
            }
            switch(s[i]) {
                case ')': 
                    if((!stk.empty()) && stk.top() == '(') stk.pop() ;
                    else res = false ;
                    break ;
                case ']': 
                    if((!stk.empty()) && stk.top() == '[') stk.pop() ;
                    else res = false ;
                    break ;
                case '}': 
                    if((!stk.empty()) && stk.top() == '{') stk.pop() ;
                    else res = false ;
                    break ;
            }
            
        }
        
        return (stk.empty() && res) ;
    }
};