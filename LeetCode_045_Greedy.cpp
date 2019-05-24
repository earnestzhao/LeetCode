class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        
        int iCurrentMinPath = 0;
        int iCurrentMinEnd  = 0;
        int iNextMinEnd     = iCurrentMinEnd;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + nums[i] >= nums.size() - 1)
            {
                return iCurrentMinPath + 1;
            }
            
            if (i + nums[i] > iNextMinEnd)
            {
                iNextMinEnd = i + nums[i];
            }
            
            if (i == iCurrentMinEnd)
            {
                iCurrentMinPath ++;
                iCurrentMinEnd = iNextMinEnd;
            }
        }
        
        return nums.size() - 1;
    }
};

/*
 * 1. Think out by myself.
 *
 * 2. Greedy: each minimun length has an area, which the end index of the current area is the farthest index from last area by one step.
 *
 * 3. Complex: O(n)
 *
 */

