// problem link: https://leetcode.com/problems/unique-binary-search-trees-ii/submissions/
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

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<TreeNode *> helper(int start, int end)
    {
        // this function returns all the possible trees that can be made with node start to end
        vector<TreeNode *> list;
        if (start > end)
        {
            list.push_back(NULL);
            return list;
        }

        if (start == end)
        {
            list.push_back(new TreeNode(start));
            return list;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftTrees = helper(start, i - 1);
            vector<TreeNode *> rightTrees = helper(i + 1, end);
            for (TreeNode *lRoot : leftTrees)
            {
                for (TreeNode *rRoot : rightTrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lRoot;
                    root->right = rRoot;
                    list.push_back(root);
                }
            }
        }

        return list;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }
};