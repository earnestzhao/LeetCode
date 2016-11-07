class Solution
{
public:

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> vecResult;
        
        if (p.length() > s.length())
        {
            return vecResult;
        }
        
        int aiLetterCountP[26] = { 0 };
        int aiLetterCountS[26] = { 0 };
        
        for (int iIndex = 0; iIndex < p.length(); iIndex ++)
        {
            aiLetterCountP[p[iIndex] - 'a'] ++;
            aiLetterCountS[s[iIndex] - 'a'] ++;
        }
        
        for (int iIndex = p.length(); iIndex <= s.length(); iIndex ++)
        {
            int iCompareIndex  = 0;
            int iStrStartIndex = iIndex - p.length();
            
            for (; iCompareIndex < 26; iCompareIndex ++)
            {
                if (aiLetterCountP[iCompareIndex] != aiLetterCountS[iCompareIndex])
                {
                    break;
                }
            }
            
            if (iCompareIndex >= 26)
            {
                vecResult.push_back(iStrStartIndex);
            }
            
            if (iIndex < s.length())
            {
                aiLetterCountS[s[iIndex] - 'a'] ++;
                aiLetterCountS[s[iStrStartIndex] - 'a'] --;
            }
        }
        
        return vecResult;
    }
};
