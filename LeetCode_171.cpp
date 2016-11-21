class Solution
{
public:

    int titleToNumber(string s)
    {
        int iTitleNumber = 0;
        
        for (int iIndex = s.length() - 1, iBaseValue = 1; iIndex >= 0; iIndex --, iBaseValue *= 26)
        {
            iTitleNumber += (s[iIndex] - 'A' + 1) * iBaseValue;
        }
        
        return iTitleNumber;
    }
};
