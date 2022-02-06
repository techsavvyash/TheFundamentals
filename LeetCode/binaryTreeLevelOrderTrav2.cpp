/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        /*
        Create a queue with level order traversal
        reverse the queue
        print the queue
        */
        if(root == NULL) {
            cout << "running root" << endl ;
            vector<vector<int>> ans ;
            
            return ans ;
        }
        
        queue<TreeNode*> order ;
        order.push(root) ;
        order.push(NULL) ;
        vector<vector<int>> ans ;
        vector<int> v ;
        while(!order.empty()) {
            TreeNode* temp = order.front() ;
            order.pop() ;
            if(temp == NULL) {
                if(!order.empty()) order.push(NULL) ;
                ans.push_back(v) ;
                v.clear() ;
            } else {
            
                if(temp) v.push_back(temp->val) ;
            
                if(temp && temp->left) {
                    order.push(temp->left) ;
                }
                
                if(temp && temp->right) {
                    order.push(temp->right) ;
                }
            }
        }
        //ans.push_back(v) ;
        reverse(ans.begin(), ans.end()) ;
        return ans ;
        
        
    }
};
