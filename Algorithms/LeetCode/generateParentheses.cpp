// problem link: https://leetcode.com/problems/generate-parentheses/

class Solution
{
public:
    void solve(vector<string> &strs, int open, int close, string str, int n)
    {
        if (str.length() == 2 * n)
        {
            strs.push_back(str);
            str = "";
            return;
        }

        if (open < n)
        {
            str += '(';
            solve(strs, open + 1, close, str, n);
            str.pop_back();
        }

        if (close < open)
        {
            str += ')';
            solve(strs, open, close + 1, str, n);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> strs;
        string str = "";
        solve(strs, 0, 0, str, n);
        return strs;
    }
};