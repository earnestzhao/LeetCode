class Solution
{
public:

    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        
        vector<int> vecLetterCountT(26, 0);
        vector<int> vecLetterCountS(26, 0);
        
        for (int iIndex = 0; iIndex < t.length(); iIndex ++)
        {
            vecLetterCountT[t[iIndex] - 'a'] ++;
            vecLetterCountS[s[iIndex] - 'a'] ++;
        }
        
        for (int iIndex = 0; iIndex < 26; iIndex ++)
        {
            if (vecLetterCountT[iIndex] != vecLetterCountS[iIndex])
            {
                return false;
            }
        }
        
        return true;
    }
};
