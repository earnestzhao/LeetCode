class Solution
{
public:

    int rob(vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        if (nums.size() == 1)
        {
            return nums[0];
        }
        
        if (nums.size() == 2)
        {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        
        return max(max(robSub(nums, 2, nums.size() - 2) + nums[0], robSub(nums, 1, nums.size() - 3) + nums[nums.size() - 1]), robSub(nums, 1, nums.size() - 2));
    }
    
private:

    int robSub(const vector<int> & vecNumList, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return 0;
        }
        
        vector<int> vecRobOnIndex;
        vector<int> vecNoRobOnIndex;
        
        vecRobOnIndex.push_back(vecNumList[iStartIndex]);
        vecNoRobOnIndex.push_back(0);
        
        for (int iIndex = iStartIndex + 1; iIndex <= iEndIndex; iIndex ++)
        {
            vecRobOnIndex.push_back(vecNoRobOnIndex[iIndex - iStartIndex - 1] + vecNumList[iIndex]);
            vecNoRobOnIndex.push_back(max(vecNoRobOnIndex[iIndex - iStartIndex - 1], vecRobOnIndex[iIndex - iStartIndex - 1]));
        }
        
        return max(vecRobOnIndex[vecRobOnIndex.size() - 1], vecNoRobOnIndex[vecNoRobOnIndex.size() - 1]);
    }
    
    int max(int iOper1, int iOper2)
    {
        return iOper1 > iOper2 ? iOper1 : iOper2;
    }
};

/*

Thinking is wrong at first, and is right at last. There is a bug on index after the right thinking.

Dynamic programming. The recursive relation can be found in Leetcode_198.cpp.

Define robSub(i, j) is the sub-range solution of Problem 198, then, the result of this problem is:

max { robSub(2, nums.size() - 2) + nums[0], robSub(1, nums.size() - 3) + nums[1], robSub(1, nums.size() - 2) }

*/
