class Solution
{
public:

    int combinationSum4(vector<int> & nums, int target)
    {
        vector<int> vecResult;
        vecResult.push_back(1);
        
        for (int iIndex = 1; iIndex <= target; iIndex ++)
        {
            int iResultCurrent = 0;
            
            for (int jIndex = 0; jIndex < nums.size(); jIndex ++)
            {
                if (iIndex >= nums[jIndex])
                {
                    iResultCurrent += vecResult[iIndex - nums[jIndex]];
                }
            }
            
            vecResult.push_back(iResultCurrent);
        }
        
        return vecResult[target];
    }
};

/*

Bug free once !!!

Dynamic Programming. Define vecResult[i] as the result of target 'i'. The recursive relation:

vecResult[i] = sigma (0<=j<nums.size(), i>=nums[j]) { vecResult[i-nums[j]] }

The final result is vecResult[target].

*/
