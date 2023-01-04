class Solution
{
public:
  int minimumRounds(vector<int> &tasks)
  {
    unordered_map<int, int> difficultyWiseTasks;
    int numTasks = tasks.size();
    for (int i = 0; i < numTasks; i++)
    {
      difficultyWiseTasks[tasks[i]]++;
    }

    int ans = 0;

    for (auto p : difficultyWiseTasks)
    {
      if (p.second == 1)
        return -1;
      if (p.second % 3 == 0)
      {
        ans += p.second / 3;
        continue;
      }
      else
      {
        ans += (p.second / 3) + 1;
      }
    }
    return ans;
  }
};