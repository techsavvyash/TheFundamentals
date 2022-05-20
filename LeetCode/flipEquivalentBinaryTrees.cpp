/**
 * Problem Link : https://leetcode.com/problems/flip-equivalent-binary-trees
 *
 */
 * Definition for a binary tree node.
 * struct TreeNode
 {
     *int val;
     *TreeNode *left;
     *TreeNode *right;
     *TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                    *
 };
 * /
     class Solution
 {
 public:
     bool ans;
     Solution()
     {
         ans = true;
     }
     bool flipEquiv(TreeNode *root1, TreeNode *root2)
     {
         if (root1 == NULL && root2 == NULL)
         {
             return ans;
         }

         if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
         {
             return false;
         }

         if (root1->val != root2->val)
         {
             return false;
         }
         set<int> t1;
         set<int> t2;
         if (root1->left)
             t1.insert(root1->left->val);
         if (root1->right)
             t1.insert(root1->right->val);
         if (root2->left)
             t2.insert(root2->left->val);
         if (root2->right)
             t2.insert(root2->right->val);

         if (t1.size() != t2.size())
         {
             return false;
         }
         /*if(*t1.begin() != *t2.begin() || *(++t1.begin()) != *(++t2.begin())) {
             return false ;
         }*/
         set<int>::iterator itr1 = t1.begin();
         set<int>::iterator itr2 = t2.begin();
         switch (t1.size())
         {
         case 1:
             if (*itr1 != *itr2)
             {
                 return false;
             }
             if (root1->left == NULL)
             {
                 swap(root1->left, root1->right);
             }
             if (root2->left == NULL)
             {
                 swap(root2->left, root2->right);
             }
             break;
         case 2:
             if (((*itr1) != (*itr2)) || (*(++itr1) != *(++itr2)))
             {
                 return false;
             }
             if (root1->left->val != root2->left->val)
             {
                 swap(root2->left, root2->right);
             }

             break;
         }

         return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
     }
 };