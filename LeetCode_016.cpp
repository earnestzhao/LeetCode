class Solution
{
public:

    int threeSumClosest(vector<int> & nums, int target)
    {
        int iFinalResult = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for (int iIndex = 0; iIndex <= nums.size() - 3; iIndex ++)
        {
            int iCurrentResult = INT_MAX;
            
            for (int jIndex = iIndex + 1, kIndex = nums.size() - 1; jIndex < kIndex;)
            {
                int iTestVal = nums[iIndex] + nums[jIndex] + nums[kIndex];
                
                if (iTestVal == target)
                {
                    return target;
                }
                
                if (iCurrentResult == INT_MAX)
                {
                    iCurrentResult = iTestVal;
                }
                else
                {
                    iCurrentResult = abs(iCurrentResult - target) > abs(iTestVal - target) ? iTestVal : iCurrentResult;
                }
                
                if (iTestVal > target)
                {
                    kIndex --;
                }
                else
                {
                    jIndex ++;
                }
            }
            
            if (iFinalResult == INT_MAX || abs(iFinalResult - target) > abs(iCurrentResult - target))
            {
                iFinalResult = iCurrentResult;
            }
        }
        
        return iFinalResult;
    }
};

/*

Bug free once, but a too late solution.

Two Pointer algorithm:

0. Sort the Array num by ascending order.

1. Using a variety i scanning from 0 to nums.size() - 3

2. Using a variety j start from i

3. Using a variety k start from nums.size() - 1

4. Let iTestVal = nums[i] + nums[j] + nums[k]. If iTestVal == target, then return target immediately.

5. If iTestVal > target, then, k = k - 1.

6. If iTestVal < target, then, j = j + 1.

7. Compare each iTestVal result in each inner loop.

*/
