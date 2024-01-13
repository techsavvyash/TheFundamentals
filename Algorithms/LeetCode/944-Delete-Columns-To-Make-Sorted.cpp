class Solution
{
public:
  int minDeletionSize(vector<string> &strs)
  {
    int numStrs = strs.size();
    int len = strs[0].size();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
      for (int j = 0; j < numStrs - 1; j++)
      {
        if ((strs[j][i] - strs[j + 1][i]) > 0)
        {
          ans++;
          break;
        }
      }
    }

    return ans;
  }
};