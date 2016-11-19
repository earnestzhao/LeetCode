
/*

259. 3Sum Smaller

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n

that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2: [-2, 0, 1], [-2, 0, 3]

*/

class Solution
{
public:

    int threeSumSmaller(vector<int> & nums, int target)
    {
        int iResult = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            for (int iHeadIndex = iIndex + 1, iRearIndex = nums.size() - 1; iHeadIndex < iRearIndex;)
            {
                if (nums[iIndex] + nums[iHeadIndex] + nums[iRearIndex] >= target)
                {
                    iRearIndex --;
                }
                else
                {
                    iResult += iRearIndex - iHeadIndex;
                    iHeadIndex ++;
                }
            }
        }
        
        return iResult;
    }
};
