class Solution
{
public:
    
    int minSubArrayLen(int s, vector<int> & nums)
    {
        int iResult = minSubArrayLen(s, nums, 0, nums.size() - 1);
        
        if (iResult == INT_MAX)
        {
            iResult = 0;
        }
        
        return iResult;
    }
    
private:

    int minSubArrayLen(int iDstValue, vector<int> & vecNumList, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return INT_MAX;
        }
        
        if (iStartIndex == iEndIndex)
        {
            if (vecNumList[iStartIndex] >= iDstValue)
            {
                return 1;
            }
            else
            {
                return INT_MAX;
            }
        }
        
        int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
        
        int iMidRangeSum = 0, iMidMinSubLen = 0;
        
        int iIndex = 0, jIndex = 1;
        
        while (iMidRangeSum < iDstValue && (iMidIndex - iIndex >= iStartIndex || iMidIndex + jIndex <= iEndIndex))
        {
            int iDstAdd = 0;
            
            if (iMidIndex - iIndex >= iStartIndex && iMidIndex + jIndex <= iEndIndex)
            {
                if (vecNumList[iMidIndex - iIndex] > vecNumList[iMidIndex + jIndex])
                {
                    iDstAdd = vecNumList[iMidIndex - iIndex]; iIndex ++;
                }
                else
                {
                    iDstAdd = vecNumList[iMidIndex + jIndex]; jIndex ++;
                }
            }
            else
            {
                if (iMidIndex - iIndex < iStartIndex)
                {
                    iDstAdd = vecNumList[iMidIndex + jIndex]; jIndex ++;
                }
                else
                {
                    iDstAdd = vecNumList[iMidIndex - iIndex]; iIndex ++;
                }
            }
            
            iMidRangeSum += iDstAdd; iMidMinSubLen ++;
        }
        
        if (iMidRangeSum < iDstValue)
        {
            iMidMinSubLen = INT_MAX;
        }
        
        int iLeftMinSubLen  = minSubArrayLen(iDstValue, vecNumList, iStartIndex,   iMidIndex);
        int iRightMinSubLen = minSubArrayLen(iDstValue, vecNumList, iMidIndex + 1, iEndIndex);
        int iFinalResult    = iMidMinSubLen;
        
        if (iLeftMinSubLen < iFinalResult)
        {
            iFinalResult = iLeftMinSubLen;
        }
        
        if (iRightMinSubLen < iFinalResult)
        {
            iFinalResult = iRightMinSubLen;
        }
        
        return iFinalResult;
    }
};
