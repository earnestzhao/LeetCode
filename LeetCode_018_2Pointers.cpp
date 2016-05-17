class Solution
{
public:

    vector<vector<int>> fourSum(vector<int> & nums, int target)
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> vecFinalResult;
        
        if (nums.size() < 4)
        {
            return vecFinalResult;
        }
        
        for (int iIndex = 0; iIndex <= nums.size() - 4;)
        {
            for (int jIndex = iIndex + 1; jIndex <= nums.size() - 3;)
            {
                for (int kIndex = jIndex + 1, lIndex = nums.size() - 1; kIndex < lIndex;)
                {
                    int iTestVal = nums[iIndex] + nums[jIndex] + nums[kIndex] + nums[lIndex];
                    
                    if (iTestVal > target)
                    {
                        lIndex --;
                    }
                    else if (iTestVal < target)
                    {
                        kIndex ++;
                    }
                    else
                    {
                        vector<int> vecSubResult;
                        vecSubResult.push_back(nums[iIndex]);
                        vecSubResult.push_back(nums[jIndex]);
                        vecSubResult.push_back(nums[kIndex]);
                        vecSubResult.push_back(nums[lIndex]);
                        vecFinalResult.push_back(vecSubResult);
                        
                        int iNextKIndex = kIndex + 1;
                        int iNextLIndex = lIndex - 1;
                        
                        while (iNextKIndex < lIndex && nums[iNextKIndex] == nums[kIndex])
                        {
                            iNextKIndex ++;
                        }
                        
                        while (iNextLIndex > kIndex && nums[iNextLIndex] == nums[lIndex])
                        {
                            iNextLIndex --;
                        }
                        
                        kIndex = iNextKIndex;
                        lIndex = iNextLIndex;
                    }
                }
                
                int iNextJIndex = jIndex + 1;
                
                while (iNextJIndex <= nums.size() - 3 && nums[iNextJIndex] == nums[jIndex])
                {
                    iNextJIndex ++;
                }
                
                jIndex = iNextJIndex;
            }
            
            int iNextIIndex = iIndex + 1;
            
            while (iNextIIndex <= nums.size() - 4 && nums[iNextIIndex] == nums[iIndex])
            {
                iNextIIndex ++;
            }
            
            iIndex = iNextIIndex;
        }
        
        return vecFinalResult;
    }
};
