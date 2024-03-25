/// problem link: https://leetcode.com/problems/insert-interval/submissions/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.size() == 0)
        {
            vector<vector<int>> res;
            res.push_back(newInterval);
            return res;
        }
        else if (intervals.size() == 1)
        {

            if (intervals[0][1] < newInterval[0])
            {
                intervals.push_back(newInterval);
                return intervals;
            }

            if (intervals[0][0] > newInterval[0] && intervals[0][1] < newInterval[0])
            {
                vector<vector<int>> res;
                res.push_back(newInterval);
                res.push_back(intervals[0]);
                return res;
            }

            if (intervals[0][0] > newInterval[0] && intervals[0][1] > newInterval[0])
            {
                intervals[0][0] = newInterval[0];
                return intervals;
            }

            if (intervals[0][1] < newInterval[0])
            {
                intervals.push_back(newInterval);
            }
            else if (intervals[0][1] >= newInterval[0])
            {
                // the interval comes in between
                if (intervals[0][1] < newInterval[1])
                {
                    intervals[0][1] = newInterval[1];
                }
            }

            return intervals;
        }

        int newStart = newInterval[0], newEnd = newInterval[1];

        // find the end idx
        int endIdx = -1;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] >= newEnd)
            {
                endIdx = i;
                break;
            }
        }

        int startIdx = -1;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= newStart)
            {
                startIdx = i;
                break;
            }
        }

        // check equalities

        if (intervals[startIdx][0] > newStart)
        {
            startIdx--;
        }

        bool startInBetween = false;

        if (startIdx != -1 && intervals[startIdx][1] >= newStart)
        {
            startInBetween = true;
        }

        // checking if newEnd falls between the endIdx interval
        bool endInBetween = false;
        if (endIdx != -1 && intervals[endIdx][0] <= newEnd)
        {
            endInBetween = true;
        }

        // handle the cases of startIdx == -1 and endIdx == -1 here

        if (startIdx == -1 && endIdx == -1)
        {
            vector<vector<int>> res;
            res.push_back(newInterval);

            return res;
        }
        else if (startIdx == -1 && endIdx != -1)
        {
            vector<vector<int>> res;
            if (endInBetween)
            {
                newInterval[1] = intervals[endIdx][1];
                res.push_back(newInterval);
                for (int i = endIdx + 1; i < intervals.size(); i++)
                {
                    res.push_back(intervals[i]);
                }
            }
            else
            {
                res.push_back(newInterval);
                for (int i = endIdx; i < intervals.size(); i++)
                {
                    res.push_back(intervals[i]);
                }
            }
            return res;
        }
        else if (startIdx != -1 && endIdx == -1)
        {
            vector<vector<int>> res;
            if (startInBetween)
            {
                newInterval[0] = intervals[startIdx][0];
                for (int i = 0; i < startIdx; i++)
                {
                    res.push_back(intervals[i]);
                }

                res.push_back(newInterval);
            }
            else
            {
                for (int i = 0; i <= startIdx; i++)
                {
                    res.push_back(intervals[i]);
                }

                res.push_back(newInterval);
            }

            return res;
        }

        // [startIdx - endIdx] is the range in which the newInterval spans

        // checking if the newStart falls between the startIdx interval

        // four cases as per the value of
        vector<vector<int>> res; // result to be returned

        if (startInBetween && endInBetween)
        {
            // simply merge all the intervals between startIdx to endIdx

            newInterval[0] = intervals[startIdx][0];
            newInterval[1] = intervals[endIdx][1];
            for (int i = 0; i < startIdx; i++)
            {
                res.push_back(intervals[i]);
            }
            res.push_back(newInterval);

            for (int i = endIdx + 1; i < intervals.size(); i++)
            {
                res.push_back(intervals[i]);
            }
        }
        else if (startInBetween && !endInBetween)
        {
            newInterval[0] = intervals[startIdx][0];

            for (int i = 0; i < startIdx; i++)
            {
                res.push_back(intervals[i]);
            }

            res.push_back(newInterval);

            for (int i = endIdx; i < intervals.size(); i++)
            {
                res.push_back(intervals[i]);
            }
        }
        else if (!startInBetween && endInBetween)
        {
            newInterval[1] = intervals[endIdx][1];

            for (int i = 0; i <= startIdx; i++)
            {
                res.push_back(intervals[i]);
            }

            res.push_back(newInterval);

            for (int i = endIdx + 1; i < intervals.size(); i++)
            {
                res.push_back(intervals[i]);
            }
        }
        else if (!startInBetween && !endInBetween)
        {

            for (int i = 0; i <= startIdx; i++)
            {
                res.push_back(intervals[i]);
            }

            res.push_back(newInterval);

            for (int i = endIdx; i < intervals.size(); i++)
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};