class Solution
{
public:

    int lengthOfLIS(vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        if (nums.size() == 1)
        {
            return 1;
        }
        
        vector<int> vecLisCurrentIncludedList;
        vecLisCurrentIncludedList.push_back(1);
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            int iMaxLisCurrentIncluded = 1;
            
            for (int jIndex = 0; jIndex < iIndex; jIndex ++)
            {
                if (nums[jIndex] < nums[iIndex] && iMaxLisCurrentIncluded < vecLisCurrentIncludedList[jIndex] + 1)
                {
                    iMaxLisCurrentIncluded = vecLisCurrentIncludedList[jIndex] + 1;
                }
            }
            
            vecLisCurrentIncludedList.push_back(iMaxLisCurrentIncluded);
        }
        
        int iFinalResult = 0;
        
        for (int iIndex = 0; iIndex < vecLisCurrentIncludedList.size(); iIndex ++)
        {
            if (iFinalResult < vecLisCurrentIncludedList[iIndex])
            {
                iFinalResult = vecLisCurrentIncludedList[iIndex];
            }
        }
        
        return iFinalResult;
    }
};

/*

思路上还是不行，看了 Tag 再想才想出来，最后提交前还有个 Compile Error，该打啊！

动态规划的思路，时间复杂度 O(n^2)，空间复杂度 O(n)

设含有元素 nums[i] 为截止元素的最大递增序列长度为 minc[i]，则有

minc[i] = max(0 <= j < i, nums[j] < nums[i]) { minc[j] + 1 }

貌似还有优化之后的 O(nlogn) 算法，另开辟一个文件搞定！

*/
