class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int iCurrentIndex = 0;
        vector<vector<int>> vecResult;
        for (; iCurrentIndex < intervals.size(); iCurrentIndex ++)
        {
            if (intervals[iCurrentIndex][0] < newInterval[0])
            {
                vecResult.push_back(intervals[iCurrentIndex]);
            }
            else
            {
                break;
            }
        }

        if (!vecResult.empty() && overlap(vecResult[vecResult.size() - 1], newInterval))
        {
            merge(vecResult[vecResult.size() - 1], newInterval);
        }
        else
        {
            vecResult.push_back(newInterval);
        }

        for (; iCurrentIndex < intervals.size(); iCurrentIndex ++)
        {
            if (overlap(vecResult[vecResult.size() - 1], intervals[iCurrentIndex]))
            {
                merge(vecResult[vecResult.size() - 1], intervals[iCurrentIndex]);
            }
            else
            {
                break;
            }
        }

        for (; iCurrentIndex < intervals.size(); iCurrentIndex ++)
        {
            vecResult.push_back(intervals[iCurrentIndex]);
        }

        return vecResult;
    }

private:
    bool overlap(const vector<int> &interval1, const vector<int> &interval2)
    {
        return interval1[1] >= interval2[0];
    }

    void merge(vector<int> &interval1, const vector<int> &interval2)
    {
        interval1[1] = (interval1[1] > interval2[1] ? interval1[1] : interval2[1]);
    }
};

/*
 * 1. Thoughts are OK. Complex: O(n)
 *
 * 2. Wrong edge case consideration !!!
 *
 * 3. Should clear about all details !!!
 */

