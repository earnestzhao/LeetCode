class Solution
{
public:

    int firstUniqChar(string s)
    {
        int aiLetterCount[26] = { 0 };
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            aiLetterCount[static_cast<int>(s[iIndex] - 'a')] ++;
        }
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            if (aiLetterCount[static_cast<int>(s[iIndex] - 'a')] == 1)
            {
                return iIndex;
            }
        }
        
        return -1;
    }
};
