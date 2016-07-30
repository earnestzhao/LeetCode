class Solution
{
public:

    int combinationSum4(vector<int> & nums, int target)
    {
        vector<int> vecTargetResult(target + 1, -1);
        vecTargetResult[0] = 1;
        
        combinationSum4(nums, target, vecTargetResult);
        return vecTargetResult[target];
    }
    
private:

    void combinationSum4(vector<int> & vecNumList, int iTarget, vector<int> & vecTargetResult)
    {
        if (iTarget <= 0)
        {
            return;
        }
        
        if (vecTargetResult[iTarget] >= 0)
        {
            return;
        }
        
        vecTargetResult[iTarget] = 0;
        
        for (int iIndex = 0; iIndex < vecNumList.size(); iIndex ++)
        {
            int iTargetExceptCurrent = iTarget - vecNumList[iIndex];
            
            if (iTargetExceptCurrent >= 0)
            {
                combinationSum4(vecNumList, iTargetExceptCurrent, vecTargetResult);
                vecTargetResult[iTarget] += vecTargetResult[iTargetExceptCurrent];
            }
        }
    }
};

/*

Thinking is right, but so many bugs...

Normal recursion. Define combinationSum4(nums, t) as the result of target 't'. The recursive relation:

combinationSum4(nums, t) = sigma(0<=i<nums.size()) { combinationSum4(nums, t-nums[i]) }

Optiminzation: Using vecTargetResult to store the middle results which can reduce the times of recursion. 

*/
