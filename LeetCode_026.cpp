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
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            if (nums[iIndex] != nums[iResultLength])
            {
                nums[++ iResultLength] = nums[iIndex];
            }
        }
        
        iResultLength ++;
        
        while (nums.size() > iResultLength)
        {
            nums.pop_back();
        }
        
        return iResultLength;
    }
};

/*

Normal method. Easy.

*/
