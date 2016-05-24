class Solution
{
public:

    int maxSubArray(vector<int> & nums)
    {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
    
private:

    int maxSubArray(vector<int> & nums, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex < 0 || iStartIndex >= nums.size())
        {
            return INT_MIN;
        }
        
        if (iEndIndex < 0 || iEndIndex >= nums.size())
        {
            return INT_MIN;
        }
        
        if (iStartIndex > iEndIndex)
        {
            return INT_MIN;
        }
        
        if (iStartIndex == iEndIndex)
        {
            return nums[iStartIndex];
        }
        
        int iMidIndex    = iStartIndex + (iEndIndex - iStartIndex) / 2;
        int iMaxSubLeft  = maxSubArray(nums, iStartIndex,   iMidIndex);
        int iMaxSubRight = maxSubArray(nums, iMidIndex + 1, iEndIndex);
        
        int iMaxMidToLeft  = nums[iMidIndex];
        int iMaxMidToRight = nums[iMidIndex + 1];
        
        for (int iIndex = iMidIndex - 1, iSumRange = iMaxMidToLeft; iIndex >= iStartIndex; iIndex --)
        {
            iSumRange += nums[iIndex];
            
            if (iSumRange > iMaxMidToLeft)
            {
                iMaxMidToLeft = iSumRange;
            }
        }
        
        for (int iIndex = iMidIndex + 2, iSumRange = iMaxMidToRight; iIndex <= iEndIndex; iIndex ++)
        {
            iSumRange += nums[iIndex];
            
            if (iSumRange > iMaxMidToRight)
            {
                iMaxMidToRight = iSumRange;
            }
        }
        
        int iFinalResult = iMaxMidToLeft + iMaxMidToRight;
        
        if (iMaxSubLeft > iFinalResult)
        {
            iFinalResult = iMaxSubLeft;
        }
        
        if (iMaxSubRight > iFinalResult)
        {
            iFinalResult = iMaxSubRight;
        }
        
        return iFinalResult;
    }
};

/*

Almost bug free, but a little low compile error!!!

Divide and conquer.

maxSubArray(i, j) = max { maxSubArray(i, mid), maxSubArray(mid + 1, j), max { sum(p...mid) + sum(mid+1...q) } }

The result value is either in left sub array, right sub array, or middle range of the array.

*/
