class Solution
{
public:

    string longestCommonPrefix(vector<string> & strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        
        return strs[0].substr(0, LCPLength(strs, 0, strs.size() - 1));
    }
    
private:

    int LCPLength(vector<string> & vecStrList, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex == iEndIndex)
        {
            return vecStrList[iStartIndex].length();
        }
        
        int iMidIndex    = (iStartIndex + iEndIndex) / 2;
        int iLeftLength  = LCPLength(vecStrList, iStartIndex,   iMidIndex);
        int iRightLength = LCPLength(vecStrList, iMidIndex + 1, iEndIndex);
        
        int iMinLength    = iLeftLength < iRightLength ? iLeftLength : iRightLength;
        int iResultLength = iMinLength;
        
        for (int iIndex = 0; iIndex < iMinLength; iIndex ++)
        {
            if (vecStrList[iStartIndex][iIndex] != vecStrList[iEndIndex][iIndex])
            {
                iResultLength = iIndex;
                break;
            }
        }
        
        return iResultLength;
    }
};
