bool smallerThan(const vector<int> &range1, const vector<int> &range2)
{
    return range1[0] < range2[0];
}

bool overlap(const vector<int> &range1, const vector<int> &range2)
{
    return range1[1] >= range2[0];
}

void merge(vector<int> &range1, const vector<int> &range2)
{
    range1[1] = (range1[1] > range2[1] ? range1[1] : range2[1]);
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
        {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), smallerThan);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (overlap(result[result.size() - 1], intervals[i]))
            {
                ::merge(result[result.size() - 1], intervals[i]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};

