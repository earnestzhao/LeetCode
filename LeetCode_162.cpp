class Solution
{
public:

    int findPeakElement(vector<int> & nums)
    {
        int iStartIndex = 0;
        int iEndIndex   = nums.size() - 1;
        
        while (iStartIndex <= iEndIndex)
        {
            int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
            
            if ((iMidIndex - 1 <  0           || nums[iMidIndex] > nums[iMidIndex - 1])
             && (iMidIndex + 1 >= nums.size() || nums[iMidIndex] > nums[iMidIndex + 1]))
            {
                return iMidIndex;
            }
            
            if (iMidIndex - 1 >= 0 && nums[iMidIndex] < nums[iMidIndex - 1])
            {
                iEndIndex = iMidIndex - 1;
            }
            else
            {
                iStartIndex = iMidIndex + 1;
            }
        }
        
        return -1;
    }
};
