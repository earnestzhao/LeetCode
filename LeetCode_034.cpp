class Solution
{
public:

    vector<int> searchRange(vector<int> & nums, int target)
    {
        return searchRange(nums, target, 0, nums.size() - 1);
    }
    
private:

    vector<int> searchRange(vector<int> & vecNumList, int iTarget, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return vector<int>(2, -1);
        }
        
        if (vecNumList[iStartIndex] == vecNumList[iEndIndex])
        {
            if (vecNumList[iStartIndex] == iTarget)
            {
                vector<int> vecResult;
                vecResult.push_back(iStartIndex);
                vecResult.push_back(iEndIndex);
                return vecResult;
            }
            else
            {
                return vector<int>(2, -1);
            }
        }
        
        int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
        
        if (vecNumList[iMidIndex] == iTarget)
        {
            vector<int> vecResultLeft  = searchRange(vecNumList, iTarget, iStartIndex,   iMidIndex);
            vector<int> vecResultRight = searchRange(vecNumList, iTarget, iMidIndex + 1, iEndIndex);
            
            if (vecResultLeft[0] < 0)
            {
                return vecResultRight;
            }
            
            if (vecResultRight[0] < 0)
            {
                return vecResultLeft;
            }
            
            vector<int> vecResult;
            vecResult.push_back(vecResultLeft[0]);
            vecResult.push_back(vecResultRight[1]);
            return vecResult;
        }
        
        if (iTarget > vecNumList[iMidIndex])
        {
            return searchRange(vecNumList, iTarget, iMidIndex + 1, iEndIndex);
        }
        else
        {
            return searchRange(vecNumList, iTarget, iStartIndex, iMidIndex - 1);
        }
    }
};

/*

There is a understanding error at first. Then, a right thinking, but not bug free on exit condition.

Divide and conquer like binary search.

1. Exit condition.

2. Get middle index (iMidIndex), then, compare target and nums[iMidIndex].

3. If target == nums[iMidIndex], then, recurse on both left and right, and combine them.

4. If target < nums[iMidIndex], then, recurse on left.

5. If target > nums[iMidIndex], then, recurse on right.

Average Time Complex: O(logn)

Best Time Complex: O(logn)

Worst Time Complex: O(n)

Are there any worst time complex O(n) algorithms exist? Research it later.

*/
