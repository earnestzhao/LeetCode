class Solution
{
public:

    int search(vector<int> & nums, int target)
    {
        if (nums.size() <= 0)
        {
            return -1;
        }
        
        if (nums.size() == 1)
        {
            return target == nums[0] ? 0 : -1;
        }
        
        int iSeqStartIndex = 0;
        int iSeqEndIndex   = 0;
        
        if (nums[0] < nums[nums.size() - 1])
        {
            iSeqStartIndex = 0;
            iSeqEndIndex   = nums.size() - 1;
        }
        else
        {
            int iStartIndex = 0;
            int iEndIndex   = nums.size() - 1;
            bool bSeqStartIndexFound = false;
            
            while (iEndIndex - iStartIndex > 1)
            {
                iSeqStartIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
                
                if ((iSeqStartIndex < 1 || nums[iSeqStartIndex] < nums[iSeqStartIndex - 1]) && (iSeqStartIndex + 1 >= nums.size() || nums[iSeqStartIndex] < nums[iSeqStartIndex + 1]))
                {
                    bSeqStartIndexFound = true;
                    break;
                }
                
                if (nums[iStartIndex] < nums[iSeqStartIndex])
                {
                    iStartIndex = iSeqStartIndex + 1;
                }
                
                if (nums[iSeqStartIndex] < nums[iEndIndex])
                {
                    iEndIndex = iSeqStartIndex - 1;
                }
            }
            
            if (!bSeqStartIndexFound)
            {
                iSeqStartIndex = nums[iStartIndex] < nums[iEndIndex] ? iStartIndex : iEndIndex;
            }
            
            iSeqEndIndex = iSeqStartIndex > 0 ? iSeqStartIndex - 1 : nums.size() - 1;
        }
        
        int iStartIndex = 0;
        int iEndIndex   = nums.size() - 1;
        
        while (iStartIndex <= iEndIndex)
        {
            int iMidIndex     = iStartIndex + (iEndIndex - iStartIndex) / 2;
            int iRealMidIndex = (iMidIndex + iSeqStartIndex) % nums.size();
            
            if (nums[iRealMidIndex] == target)
            {
                return iRealMidIndex;
            }
            
            if (target < nums[iRealMidIndex])
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

/*

Thinking is right, and almost bug free, except the condition which raw list is sorted.

1. Using binary search to find the index of sorted beginning element (the minimum element).

2. Using binary search to find the target.

Time complex: O(logn + logn) = O(logn)

*/
