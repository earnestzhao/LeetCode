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
        
        vector<int> vecResultNumList;
        vecResultNumList.push_back(nums[0]);
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            if (vecResultNumList[vecResultNumList.size() - 1] < nums[iIndex])
            {
                vecResultNumList.push_back(nums[iIndex]);
            }
            
            if (vecResultNumList[vecResultNumList.size() - 1] > nums[iIndex])
            {
                BinaryReplaceFirstBigger(vecResultNumList, nums[iIndex]);
            }
        }
        
        return vecResultNumList.size();
    }
    
private:

    void BinaryReplaceFirstBigger(vector<int> & vecList, int iValue)
    {
        int iStartIndex = 0;
        int iEndIndex   = vecList.size() - 1;
        
        while (iStartIndex <= iEndIndex)
        {
            int iMidIndex = (iStartIndex + iEndIndex) / 2;
            
            if (iValue > vecList[iMidIndex])
            {
                iStartIndex = iMidIndex + 1;
            }
            else if (iValue < vecList[iMidIndex])
            {
                iEndIndex = iMidIndex - 1;
            }
            else
            {
                iStartIndex = iMidIndex;
                break;
            }
        }
        
        vecList[iStartIndex] = iValue;
    }
};

/*

没想出来，本来想用堆来优化动态规划，结果失败，没有好的方法和数据结构来支持。

个人能力上确实这方面欠缺，想不出一些精巧的方法来。

这个想法非常的巧妙，选用一个数组 vecResultNumList 单纯保存最大递增子序列的长度值，里面的值可能不符合绝对递增的规律，但是符合长度值的变化规律。

先把 nums[0] 放在 vecResultNumList 中，开始遍历原数组，如果遇到某个 nums[i] > vecResultNumList[vecResultNumList.size() - 1]，则把 nums[i] 加入 vecResultNumList 中；

如果出现 nums[i] < vecResultNumList[vecResultNumList.size() - 1] 的情况，则对现有 vecResultNumList 进行二分查找（现有 vecResultNumList 按照前述规则一定有序）；

找到 从 0 到 vecResultNumList.size() - 1 下标变化方向上，第一个大于 nums[i] 的元素的下标，并用 nums[i] 替换它，

直到遍历完数组，所得到的 vecResultNumList.size() 就是最大递增子序列的长度。

这个过程虽然破坏了 vecResultNumList 维持最大递增子序列本身的特性，但并没有破坏长度特性，以下两点可以保证：

1. 如果 vecResultNumList 中当前序列已经是最大递增子序列，则后面的值无论是什么，怎么替换，都无法突破 vecResultNumList 的当前长度

2. 如果 vecResultNumList 中当前序列不是最大递增子序列，则要么出现大值时 vecResultNumList 加长，要么替换掉之前的元素，不影响 vecResultNumList 的长度特性

虽然很难，但是也得总结：在考虑问题的时候不要被纯净数据的思路框住，能够得到最终结果就是 OK 的，同时，还是要考虑结果序列的特性。

本题的思路就是，期望后面的值替换掉前面的值，可以得到更好的序列，如果得不到更好的序列，长度上也不会变得更坏。

*/
