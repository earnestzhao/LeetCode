class Solution
{
public:

    void nextPermutation(vector<int> & nums)
    {
        bool bNeedReverse = true;
        
        for (int iIndex = nums.size() - 2; iIndex >= 0; iIndex --)
        {
            if (nums[iIndex] < nums[iIndex + 1])
            {
                for (int jIndex = nums.size() - 1; jIndex >= iIndex + 1; jIndex --)
                {
                    if (nums[jIndex] > nums[iIndex])
                    {
                        int iSwap    = nums[iIndex];
                        nums[iIndex] = nums[jIndex];
                        nums[jIndex] = iSwap;
                        break;
                    }
                }
                
                reverse(nums.begin() + iIndex + 1, nums.end());
                bNeedReverse = false;
                break;
            }
        }
        
        if (bNeedReverse && nums[0] > nums[nums.size() - 1])
        {
            reverse(nums.begin(), nums.end());
        }
    }
};

/*

Thinking is keeping wrong until right...

Normal algorithm:

1. Travesal from end to front, find the first increasing pair, define 'i' as the increasing pair's first index.

2. Find an element which is the minimum one greater than nums[i] from 'i+1' to the end, define 'j' as the destination index.

3. Swap nums[i] and nums[j], and reverse the list from 'i+1' to the end.

4. If the whole list is decreasing, then, reverse it all.

*/
