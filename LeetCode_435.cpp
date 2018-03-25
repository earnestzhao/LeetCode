/**
 * Definition for an interval.
 * struct Interval
 * {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
public:
        
    int eraseOverlapIntervals(vector<Interval> & intervals)
    {
        if (intervals.size() <= 1)
        {
            return 0;
        }

        vector<Interval> vecIntervals = intervals;
        bool IntervalSmaller(const Interval & operandLeft, const Interval & operandRight);
        sort(vecIntervals.begin(), vecIntervals.end(), IntervalSmaller);

        int iNonOverlapCount = 1;
        for (int iPrev = 0, iCurrent = 1; iCurrent < vecIntervals.size(); iCurrent ++)
        {
            if (vecIntervals[iPrev].end <= vecIntervals[iCurrent].start)
            {
                iPrev = iCurrent;
                iNonOverlapCount ++;
            }
        }

        return vecIntervals.size() - iNonOverlapCount;
    }
};

bool IntervalSmaller(const Interval & operandLeft, const Interval & operandRight)
{
    return operandLeft.end < operandRight.end;
}


/*

Greedy !!! I had the right intuition but the wrong greedy policy.

From the min(interval.end), which must be in the non-overlap group.

Or, none of the intervals could be in non-overlap group.

*/

