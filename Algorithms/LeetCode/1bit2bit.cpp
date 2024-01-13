
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()>1 && bits[bits.size()-2] == 0) return true ;
        else {
            bool flag = true ;int i ;
            for(i = 0;i<bits.size()-1;i++) {
                if(bits[i] == 1) i++ ;
            }
            if(i == bits.size()-1) return true ;
            else return false ;
        }
        
    }
};
