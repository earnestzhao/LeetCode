class Solution
{
public:

    int majorityElement(vector<int> & nums)
    {
        return majorityElement(nums, 0, nums.size() - 1);
    }
    
private:

    enum { MIN_INT = 0x80000001 };

    int majorityElement(vector<int> & nums, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return MIN_INT;
        }
        
        if (iStartIndex == iEndIndex)
        {
            return nums[iStartIndex];
        }
        
        int iMidIndex   = iStartIndex + (iEndIndex - iStartIndex) / 2;
        int iLeftMElem  = majorityElement(nums, iStartIndex,   iMidIndex);
        int iRightMElem = majorityElement(nums, iMidIndex + 1, iEndIndex);
        
        if (iLeftMElem == MIN_INT)
        {
            return iRightMElem;
        }
        
        if (iRightMElem == MIN_INT)
        {
            return iLeftMElem;
        }
        
        if (iLeftMElem == iRightMElem)
        {
            return iLeftMElem;
        }
        
        int iLeftCount  = 0;
        int iRightCount = 0;
        
        for (int iIndex = iStartIndex; iIndex <= iEndIndex; iIndex ++)
        {
            if (nums[iIndex] == iLeftMElem)
            {
                iLeftCount ++;
            }
            
            if (nums[iIndex] == iRightMElem)
            {
                iRightCount ++;
            }
        }
        
        if (iLeftCount > iRightCount)
        {
            return iLeftMElem;
        }
        
        return iRightMElem;
    }
};

/*

Because of careless, I made 3 mistakes when writing this program.  1. Function Param without type; 2. Recursion Exit Condition Bigger; 3. Return Variety.

Not big mistake, but not bug free. Carefully!!!!!!

Divide and Conquer. Divide number list into 2 halves, recursion on each half, and get 2 results L and R.

If L is equal to R, L or R is the final result. Otherwise, check L or R in the number list, the final result is the bigger count one.

Time Complex: T(n) = T(n/2) + 2n = O(nlogn)

*/
