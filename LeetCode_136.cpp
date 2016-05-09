class Solution
{
public:

    int singleNumber(vector<int> & nums)
    {
        int iResultNumber = 0;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            iResultNumber ^= (nums[iIndex]);
        }
        
        return iResultNumber;
    }
};
