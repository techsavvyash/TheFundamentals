// problem link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n);
        int maxEl = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            maxEl = max(maxEl, dp[i]);
        }

        return maxEl;
    }
};