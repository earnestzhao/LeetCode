class Solution
{
public:

    vector<vector<string>> partition(string s)
    {
        vector<string> vecSubResult;
        vector<vector<string>> vecResult;
        partition(s, 0, vecSubResult, vecResult);
        return vecResult;
    }
    
private:

    void partition(const string & strSrc, int iStartIndex, vector<string> & vecSubResult, vector<vector<string>> & vecResult)
    {
        if (iStartIndex >= strSrc.size())
        {
            vecResult.push_back(vecSubResult);
            return;
        }
        
        vecSubResult.push_back(string(1, strSrc[iStartIndex]));
        partition(strSrc, iStartIndex + 1, vecSubResult, vecResult);
        vecSubResult.pop_back();
        
        int iAppearOddCharCount = 1;
        unordered_map<char, int> hmapCharCount;
        hmapCharCount[strSrc[iStartIndex]] = 1;
        
        for (int iIndex = iStartIndex + 1; iIndex < strSrc.size(); iIndex ++)
        {
            int iCurrCharNum = iIndex - iStartIndex + 1;
            
            unordered_map<char, int>::iterator hmapIterator = hmapCharCount.find(strSrc[iIndex]);
            
            if (hmapIterator != hmapCharCount.end())
            {
                hmapIterator -> second ++;
            }
            else
            {
                hmapCharCount[strSrc[iIndex]] = 1;
            }
            
            if (hmapCharCount[strSrc[iIndex]] % 2)
            {
                iAppearOddCharCount ++;
            }
            else
            {
                iAppearOddCharCount --;
            }
            
            if (hmapCharCount.size() == 1)
            {
                vecSubResult.push_back(strSrc.substr(iStartIndex, iCurrCharNum));
                partition(strSrc, iIndex + 1, vecSubResult, vecResult);
                vecSubResult.pop_back();
                continue;
            }
            
            if ((iCurrCharNum % 2 == 1 && iAppearOddCharCount == 1) || (iCurrCharNum % 2 == 0 && iAppearOddCharCount == 0))
            {
                if (isPalindrome(strSrc, iStartIndex, iIndex))
                {
                    vecSubResult.push_back(strSrc.substr(iStartIndex, iCurrCharNum));
                    partition(strSrc, iIndex + 1, vecSubResult, vecResult);
                    vecSubResult.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(const string & strSrc, int iStartIndex, int iEndIndex)
    {
        while (iStartIndex < iEndIndex)
        {
            if (strSrc[iStartIndex] != strSrc[iEndIndex])
            {
                return false;
            }
            
            iStartIndex ++;
            iEndIndex   --;
        }
        
        return true;
    }
};

/*

Thinking is right, almost bug free, but it has a long run-time.

Normal backtracking.

Using count of charactor to reduce the times of palindrome judgement.

*/
