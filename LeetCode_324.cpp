class Solution
{
public:

    void wiggleSort(vector<int> & nums)
    {
        srand(time(NULL));
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            if (iIndex > 0)
            {
                int iSwapValue = 0;
                
                if (iIndex % 2 != 0)
                {
                    if (nums[iIndex] < nums[iIndex - 1])
                    {
                        iSwapValue = nums[iIndex - 1]; nums[iIndex - 1] = nums[iIndex]; nums[iIndex] = iSwapValue;
                    }
                }
                else
                {
                    if (nums[iIndex] > nums[iIndex - 1])
                    {
                        iSwapValue = nums[iIndex - 1]; nums[iIndex - 1] = nums[iIndex]; nums[iIndex] = iSwapValue;
                    }
                }
            }
        }
    }
};
