class Solution
{
public:

    int removeDuplicates(vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        int iResultLength = 0;
        int iCurrentCount = 1;
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            if (nums[iIndex] != nums[iResultLength])
            {
                nums[++ iResultLength] = nums[iIndex];
                iCurrentCount = 1;
                continue;
            }
            
            if (nums[iIndex] == nums[iResultLength] && iCurrentCount < 2)
            {
                nums[++ iResultLength] = nums[iIndex];
                iCurrentCount ++;
                continue;
            }
        }
        
        return iResultLength + 1;
    }
};

/*

Thinking is right, but not bug free. Bugs ocurred on edge and condition judgement.

Normal algorithm. Use iCurrentCount to record current element number.

*/
