class Solution
{
public:

    int searchInsert(vector<int> & nums, int target)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        int iStartIndex = 0;
        int iEndIndex   = nums.size() - 1;
        
        while (iStartIndex <= iEndIndex)
        {
            int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
            
            if (nums[iMidIndex] == target)
            {
                return iMidIndex;
            }
            
            if (target > nums[iMidIndex])
            {
                iStartIndex = iMidIndex + 1;
            }
            else
            {
                iEndIndex = iMidIndex - 1;
            }
        }
        
        return iStartIndex;
    }
};

/*

Bug Free Once !!!

Normal Binary Search.

*/
