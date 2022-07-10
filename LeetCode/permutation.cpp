// problem link: https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void getPermutations(vector<vector<int>> &res, vector<int> nums, int currentIdx)
    {
        // base case
        if (currentIdx == nums.size())
        {
            res.push_back(nums);
            return;
        }

        // recursive case
        for (int i = currentIdx; i < nums.size(); i++)
        {
            swap(nums[i], nums[currentIdx]);
            getPermutations(res, nums, currentIdx + 1);
            swap(nums[i], nums[currentIdx]); //  backtracking step
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;

        getPermutations(res, nums, 0);

        return res;
    }
};