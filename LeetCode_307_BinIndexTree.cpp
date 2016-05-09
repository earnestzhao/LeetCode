class NumArray
{
public:
    
    NumArray(vector<int> & nums) 
    {
        m_vecNumList = nums;
        
        for (int iIndex = 0; iIndex < m_vecNumList.size(); iIndex ++)
        {
            m_vecTreeList.push_back(getSumValueOfRange(iIndex - treeSumArea(iIndex + 1) + 1, iIndex - 1) + m_vecNumList[iIndex]);
        }
    }

    void update(int i, int val)
    {
        if (m_vecNumList.size() > 0)
        {
            elemPlusValue(i, val - m_vecNumList[i]);
        }
    }

    int sumRange(int i, int j)
    {
        if (m_vecNumList.size() > 0)
        {
            return getSumValueOfRange(i, j);
        }
        
        return 0;
    }
    
private:

    vector<int> m_vecNumList;
    vector<int> m_vecTreeList;
    
    void elemPlusValue(int iIndex, int iPlusValue)
    {
        m_vecNumList[iIndex] += iPlusValue;
        
        for (int iCurrent = iIndex; iCurrent < m_vecTreeList.size(); iCurrent += treeSumArea(iCurrent + 1))
        {
            m_vecTreeList[iCurrent] += iPlusValue;
        }
    }
    
    int getSumValueOfRange(int iRangeStart, int iRangeEnd)
    {
        return getSumValue(iRangeEnd) - getSumValue(iRangeStart - 1);
    }
    
    int treeSumArea(int iIndex)
    {
        return iIndex & (iIndex ^ (iIndex - 1));
    }
    
    int getSumValue(int iIndex)
    {
        int iSumResult = 0;
        
        for (int iCurrent = iIndex; iCurrent >= 0; iCurrent -= treeSumArea(iCurrent + 1))
        {
            iSumResult += m_vecTreeList[iCurrent];
        }
        
        return iSumResult;
    }
};

/*

这是用树状数组的解法，可能因为没理解太好，写错了几个点，加 1 和减 1 调整也需要注意。

树状数组是满足以下性质的数组：

1. 一个数组 N 表示原有数，另一个数组 T 表示区间和值

2. T[i] = sum( N[i - 2^k + 1],...,N[i] )，其中 k 为 i 中末尾 0 的个数，2^k 可以通过 i&(i^(i-1)) 简单求得（保留末位 1 和所有末位 0）

3. sum(1...i) = T[i] + T[i - 2^k] + ... T[>0]，由于每个 T[i] 记录了前 2^k 个数的和值，因此该等式成立，时间复杂度 O(logi)

4. set(i, delta) = { T[i] += delta, T[i + 2^k] += delta, ..., T[<=n] += delta }，由于 T[i + j * 2^k] 和值中包含 T[i] 的值，因此该等式成立，时间复杂度 O(logi)

写的时候注意边界条件，也要注意领会精神和树的形状

*/
