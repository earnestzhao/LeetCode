class Solution
{
public:

    vector<string> restoreIpAddresses(string s)
    {
        if (s.length() < 4 || s.length() > 12)
        {
            return vector<string>();
        }
        
        string strSubResult;
        vector<string> vecResult;
        restoreIpAddresses(s, 0, 0, strSubResult, vecResult);
        return vecResult;
    }
    
private:

    void restoreIpAddresses(const string & vecIpSrc, int iCurrentIndex, int iPointNumber, string & strSubResult, vector<string> & vecResult)
    {
        if (iPointNumber == 3)
        {
            if (validIpSeg(vecIpSrc, iCurrentIndex, vecIpSrc.length() - 1))
            {
                for (int iIndex = iCurrentIndex; iIndex < vecIpSrc.length(); iIndex ++)
                {
                    strSubResult.push_back(vecIpSrc[iIndex]);
                }
                
                vecResult.push_back(strSubResult);
                
                while (strSubResult[strSubResult.length() - 1] != '.')
                {
                    strSubResult.pop_back();
                }
            }
            
            return;
        }
        
        for (int iIndex = iCurrentIndex; iIndex <= iCurrentIndex + 2 && iIndex < vecIpSrc.length(); iIndex ++)
        {
            if (validIpSeg(vecIpSrc, iCurrentIndex, iIndex))
            {
                for (int jIndex = iCurrentIndex; jIndex <= iIndex; jIndex ++)
                {
                    strSubResult.push_back(vecIpSrc[jIndex]);
                }
                
                strSubResult.push_back('.');
                restoreIpAddresses(vecIpSrc, iIndex + 1, iPointNumber + 1, strSubResult, vecResult);
                strSubResult.pop_back();
                
                while (!strSubResult.empty() && strSubResult[strSubResult.length() - 1] != '.')
                {
                    strSubResult.pop_back();
                }
            }
            else
            {
                break;
            }
        }
    }
    
    bool validIpSeg(const string & vecIpSrc, int iStartIndex, int iEndIndex)
    {
        if (iStartIndex == iEndIndex)
        {
            return true;
        }
        
        if (iEndIndex - iStartIndex == 1)
        {
            return vecIpSrc[iStartIndex] != '0';
        }
        
        if (iEndIndex - iStartIndex == 2)
        {
            return vecIpSrc[iStartIndex] == '1' || (vecIpSrc[iStartIndex] == '2' && (vecIpSrc[iStartIndex + 1] < '5' || (vecIpSrc[iStartIndex + 1] == '5' && vecIpSrc[iStartIndex + 2] <= '5')));
        }
        
        return false;
    }
};

/*

Thinking is right, and almost bug free, except a small compile error and a big empty string judgement.

Normal backtracking. If one number valid, two number valid or three number valid, recurse on next.

*/
