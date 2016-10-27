class Solution
{
public:

    int longestSubstring(string s, int k)
    {
        if (k <= 0)
        {
            return s.length();
        }
        
        return longestSubstring(s, k, 0, s.length() - 1);
    }
    
private:

    int longestSubstring(string & strSrc, int iKTimes, int iStartIndex, int iEndIndex)
    {
        if (iEndIndex < iStartIndex)
        {
            return 0;
        }
        
        int iLength = iEndIndex - iStartIndex + 1;
        
        if (iLength < iKTimes)
        {
            return 0;
        }
        
        vector<vector<int>> vecLetterIndexes(26, vector<int>());
        
        for (int iIndex = iStartIndex; iIndex <= iEndIndex; iIndex ++)
        {
            vecLetterIndexes[strSrc[iIndex] - 'a'].push_back(iIndex);
        }
        
        bool bNoLessThanK = true;
        
        vector<int> vecLTKLetterPosition(iLength, 0);
        
        for (int iIndex = 0; iIndex < 26; iIndex ++)
        {
            if (vecLetterIndexes[iIndex].size() > 0 && vecLetterIndexes[iIndex].size() < iKTimes)
            {
                for (int jIndex = 0; jIndex < vecLetterIndexes[iIndex].size(); jIndex ++)
                {
                    vecLTKLetterPosition[vecLetterIndexes[iIndex][jIndex] - iStartIndex] = 1;
                }
                
                bNoLessThanK = false;
            }
        }
        
        if (bNoLessThanK)
        {
            return iLength;
        }
        
        int iMaxLength = 0;
        
        for (int iIndex = 0, iSegStartIndex = 0; iIndex < iLength + 1; iIndex ++)
        {
            if (iIndex == iLength || vecLTKLetterPosition[iIndex] == 1)
            {
                if (iSegStartIndex < iIndex)
                {
                    int iCurrentLength = longestSubstring(strSrc, iKTimes, iStartIndex + iSegStartIndex, iStartIndex + iIndex - 1);
                    
                    if (iMaxLength < iCurrentLength)
                    {
                        iMaxLength = iCurrentLength;
                    }
                }
                
                iSegStartIndex = iIndex + 1;
            }
        }
        
        return iMaxLength;
    }
};

/*

Divide and conquer.

1. Travesal the list, find the letters which appear less than K times, then, record their indices.

2. Divide the list by the indices into indices.size() + 1 parts.

3. Recurision on each part.

4. Return the maximum result of each part.

Time complexity: O(nlogn)

*/
