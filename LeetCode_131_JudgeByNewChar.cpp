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
        
        unordered_set<char> hsetCharCount;
        hsetCharCount.insert(strSrc[iStartIndex]);
        
        for (int iIndex = iStartIndex + 1, iPossibleIndex = iIndex; iIndex < strSrc.size() && iPossibleIndex < strSrc.size(); iIndex ++)
        {
            int iCurrCharNum = iIndex - iStartIndex + 1;
            
            unordered_set<char>::iterator hsetIterator = hsetCharCount.find(strSrc[iIndex]);
            
            if (hsetIterator == hsetCharCount.end())
            {
                hsetCharCount.insert(strSrc[iIndex]);
                iPossibleIndex = iIndex + iCurrCharNum - 1;
                continue;
            }
            
            if (hsetCharCount.size() == 1 || isPalindrome(strSrc, iStartIndex, iIndex))
            {
                vecSubResult.push_back(strSrc.substr(iStartIndex, iCurrCharNum));
                partition(strSrc, iIndex + 1, vecSubResult, vecResult);
                vecSubResult.pop_back();
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

Thinking is right, but a big bug which on index calculation and storing.

Normal backtracking.

Using new character to reduce the times of palindrome judgement.

If current character (define index as 'i') is a new character,

the sub-string from beginning (define index as 's') to i + i - s is impossible to be a palindrome.

*/
