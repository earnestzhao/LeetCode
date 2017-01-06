class Solution
{
public:

    string longestCommonPrefix(vector<string> & strs)
    {
        return longestCommonPrefix(strs, 0, static_cast<int>(strs.size()) - 1);
    }
    
private:

    string longestCommonPrefix(vector<string> & vecStrList, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex > iEndIndex)
        {
            return "";
        }
        
        if (iStartIndex == iEndIndex)
        {
            return vecStrList[iStartIndex];
        }
        
        int iMidIndex   = (iStartIndex + iEndIndex) / 2;
        string strLeft  = longestCommonPrefix(vecStrList, iStartIndex,   iMidIndex);
        string strRight = longestCommonPrefix(vecStrList, iMidIndex + 1, iEndIndex);
        
        int iMinLength    = strLeft.length() < strRight.length() ? strLeft.length() : strRight.length();
        int iResultLength = iMinLength;
        
        for (int iIndex = 0; iIndex < iMinLength; iIndex ++)
        {
            if (strLeft[iIndex] != strRight[iIndex])
            {
                iResultLength = iIndex;
                break;
            }
        }
        
        return strLeft.substr(0, iResultLength);
    }
};
