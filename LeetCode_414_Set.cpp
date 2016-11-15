class Solution
{
public:

    int thirdMax(vector<int> & nums)
    {
        set<int> setMaxValues;
        
        for (int iIndex = 1; iIndex <= 3; iIndex ++)
        {
            int iMaxValue = INT_MIN;
            
            bool bCanInsert = false;
            
            for (int jIndex = 0; jIndex < nums.size(); jIndex ++)
            {
                if (setMaxValues.find(nums[jIndex]) == setMaxValues.end() && iMaxValue <= nums[jIndex])
                {
                    iMaxValue  = nums[jIndex];
                    bCanInsert = true;
                }
            }
            
            if (bCanInsert)
            {
                setMaxValues.insert(iMaxValue);
            }
        }
        
        if (setMaxValues.size() == 3)
        {
            return *setMaxValues.begin();
        }
        
        return *setMaxValues.rbegin();
    }
};
