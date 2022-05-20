// prob link: https://leetcode.com/problems/happy-number/

class Solution {
public:
    map<int, bool> visited ;
    vector<int> getDigits(int n) {
        vector<int> digs; 
        while(n != 0) {
            digs.push_back(n%10);
            n /= 10 ;
        } 
            
        return digs; 
    }
    
    bool isHappy(int n) {
        
        while(n != 1 && visited[n] != true) {
            visited[n] = true ;
            vector<int> digs = getDigits(n);
            n = 0 ;
            for(int i = 0; i< digs.size(); i++) {
                n += digs[i] * digs[i] ;
            }
        }
        
        return n == 1  ;
    }
};
