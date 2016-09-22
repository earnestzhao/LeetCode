class Solution
{
public:

    int firstMissingPositive(vector<int> & nums)
    {
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            while (nums[iIndex] > 0 && nums[iIndex] <= nums.size() && nums[nums[iIndex] - 1] != nums[iIndex])
            {
                int iSwapValue          = nums[iIndex];
                int iCurrentValue       = nums[iIndex];
                nums[iIndex]            = nums[iCurrentValue - 1];
                nums[iCurrentValue - 1] = iSwapValue;
            }
        }
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            if (iIndex != nums[iIndex] - 1)
            {
                return iIndex + 1;
            }
        }
        
        return nums.size() + 1;
    }
};

/*

Thinking is not right ...

The right thinking is put the number into its own position.

When the loop ends, the number which is not at its own postion is the final result.

*/
