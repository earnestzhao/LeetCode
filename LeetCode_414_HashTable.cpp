class Solution
{
public:

    int thirdMax(vector<int> & nums)
    {
        unordered_set<int> hsetMaxValues;
        
        for (int iIndex = 1; iIndex <= 3; iIndex ++)
        {
            int iMaxValue = INT_MIN;
            
            bool bCanInsert = false;
            
            for (int jIndex = 0; jIndex < nums.size(); jIndex ++)
            {
                if (hsetMaxValues.find(nums[jIndex]) == hsetMaxValues.end() && iMaxValue <= nums[jIndex])
                {
                    iMaxValue  = nums[jIndex];
                    bCanInsert = true;
                }
            }
            
            if (bCanInsert)
            {
                hsetMaxValues.insert(iMaxValue);
            }
        }
        
        int iMinValue = INT_MAX;
        int iMaxValue = INT_MIN;
        
        for (unordered_set<int>::iterator hsetIterator = hsetMaxValues.begin(); hsetIterator != hsetMaxValues.end(); hsetIterator ++)
        {
            if (iMinValue > *hsetIterator)
            {
                iMinValue = *hsetIterator;
            }
            
            if (iMaxValue < *hsetIterator)
            {
                iMaxValue = *hsetIterator;
            }
        }
        
        if (hsetMaxValues.size() == 3)
        {
            return iMinValue;
        }
        
        return iMaxValue;
    }
};
