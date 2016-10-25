class Solution
{
public:

    bool isSubsequence(string s, string t)
    {
        if (s.empty())
        {
            return true;
        }
        
        if (s.length() > t.length())
        {
            return false;
        }
        
        for (int iMainIndex = 0, iSubIndex = 0; iMainIndex < t.length(); iMainIndex ++)
        {
            if (s[iSubIndex] == t[iMainIndex])
            {
                iSubIndex ++;
                
                if (iSubIndex >= s.length())
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
