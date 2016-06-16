class Solution
{
public:

    int findMin(vector<int> & nums)
    {
        int iStartIndex = 0;
        int iEndIndex   = nums.size() - 1;
        
        while (nums[iStartIndex] > nums[iEndIndex])
        {
            int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
            
            if (nums[iMidIndex] >= nums[iStartIndex])
            {
                iStartIndex = iMidIndex + 1;
            }
            else
            {
                iEndIndex = iMidIndex;
            }
        }
        
        return nums[iStartIndex];
    }
};

/*

Thinking is right, but it is hard to make it simple and exactly correct.

Binary search. Take care of loop end and binary search conditions !!!

*/
