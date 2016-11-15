class Solution
{
public:

    int thirdMax(vector<int> & nums)
    {
        unordered_map<int, vector<int>> hmapValueIndexes;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            unordered_map<int, vector<int>>::iterator hmapIterator = hmapValueIndexes.find(nums[iIndex]);
            
            if (hmapIterator != hmapValueIndexes.end())
            {
                hmapIterator -> second.push_back(iIndex);
            }
            else
            {
                hmapValueIndexes[nums[iIndex]] = vector<int>(1, iIndex);
            }
        }
        
        vector<int> vecMaxValueSortIndex(nums.size(), 0);
        
        for (int iIndex = 1; iIndex <= 3; iIndex ++)
        {
            int iMaxValue = INT_MIN;
            
            for (int jIndex = 0; jIndex < nums.size(); jIndex ++)
            {
                if (vecMaxValueSortIndex[jIndex] == 0 && iMaxValue < nums[jIndex])
                {
                    iMaxValue = nums[jIndex];
                }
            }
            
            unordered_map<int, vector<int>>::iterator hmapIterator = hmapValueIndexes.find(iMaxValue);
            
            if (hmapIterator != hmapValueIndexes.end())
            {
                for (int jIndex = 0; jIndex < hmapIterator -> second.size(); jIndex ++)
                {
                    if (vecMaxValueSortIndex[hmapIterator -> second[jIndex]] == 0)
                    {
                        vecMaxValueSortIndex[hmapIterator -> second[jIndex]] = iIndex;
                    }
                }
            }
        }
        
        for (int iIndex = 0; iIndex < vecMaxValueSortIndex.size(); iIndex ++)
        {
            if (vecMaxValueSortIndex[iIndex] == 3)
            {
                return nums[iIndex];
            }
        }
        
        for (int iIndex = 0; iIndex < vecMaxValueSortIndex.size(); iIndex ++)
        {
            if (vecMaxValueSortIndex[iIndex] == 1)
            {
                return nums[iIndex];
            }
        }
        
        return INT_MIN;
    }
};
