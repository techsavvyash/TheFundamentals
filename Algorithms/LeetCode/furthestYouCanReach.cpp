// link to the prob: https://leetcode.com/problems/furthest-building-you-can-reach/submissions/

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        // basically we need to keep track of where we have used
        // maximum bricks till now and in case we run out of bricks replace
        // these maximum bricks used with a ladder
        // we can keep track of the maximum number of
        // bricks ever used in a scenario using
        // a priority queue

        priority_queue<int> maxBricks;
        int i;
        for (i = 0; i < heights.size() - 1; i++)
        {
            // case when we need to move to a shorter building
            if (heights[i] >= heights[i + 1])
            {
                continue;
            }

            // in case of a taller building
            int heightDiff = heights[i + 1] - heights[i];
            bricks -= heightDiff;
            maxBricks.push(heightDiff);

            if (bricks < 0)
            {
                bricks += maxBricks.top();
                maxBricks.pop();
                ladders--;
            }

            if (ladders < 0)
            {
                return i;
            }
        }

        return heights.size() - 1; // -1 because zero based indexing
    }
};