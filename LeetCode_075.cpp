class Solution
{
public:

    void sortColors(vector<int> & nums)
    {
        int aiColorNum[3] = { 0 };
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            aiColorNum[nums[iIndex]] ++;
        }
        
        nums.clear();
        
        for (int iIndex = 0; iIndex < 3; iIndex ++)
        {
            while (aiColorNum[iIndex] --)
            {
                nums.push_back(iIndex);
            }
        }
    }
};

/*

Bug free once.

Count each color number, and combine them.

*/
