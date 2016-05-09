class Solution
{
public:
    
    vector<string> summaryRanges(vector<int>& nums)
    {
        summaryRanges(nums, 0, nums.size() - 1);
        
        vector<string> vecResultList;
        
        for (int iIndex = 0; iIndex < m_vecRangeList.size(); iIndex ++)
        {
            ostringstream ossResult;
            
            if (m_vecRangeList[iIndex].first == m_vecRangeList[iIndex].second)
            {
                ossResult << m_vecRangeList[iIndex].first;
            }
            else
            {
                ossResult << m_vecRangeList[iIndex].first << "->";
                ossResult << m_vecRangeList[iIndex].second;
            }
            
            vecResultList.push_back(ossResult.str());
        }
        
        return vecResultList;
    }
    
private:

    void summaryRanges(const vector<int> & vecNumList, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return;
        }
        
        if (iEndIndex - iStartIndex == vecNumList[iEndIndex] - vecNumList[iStartIndex])
        {
            if (m_vecRangeList.size() > 0 && m_vecRangeList[m_vecRangeList.size() - 1].second + 1 == vecNumList[iStartIndex])
            {
                m_vecRangeList[m_vecRangeList.size() - 1].second = vecNumList[iEndIndex];
            }
            else
            {
                m_vecRangeList.push_back(pair<int, int>(vecNumList[iStartIndex], vecNumList[iEndIndex]));
            }
            
            return;
        }
        
        int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
        summaryRanges(vecNumList, iStartIndex,   iMidIndex);
        summaryRanges(vecNumList, iMidIndex + 1, iEndIndex);
    }
    
    vector<pair<int, int>> m_vecRangeList;
};

/*

The method of thinking is exactly right, but not bug free.

There is a bug of presentation error while range start is equal to range end, and a missing element in middle edge.

A direct algorithm's time complexity is O(n) which can be implemented by travesal.

Because of no repeat elements, whether it is a range or not can be judged by a simple calculate.

So, divide and conquer such as binary search method can be used.

1. Divide the list into 2 sub lists.

2. Recurse on each sub lists.

3. If the last element in left part list (LL) is in range, and the first element in right part (RF) is in range, and LL + 1 == RF,

then, a new longer range is the merge of the 2 edge ranges.

4. Other ranges except the edge will be keeped to the final result.

*/

