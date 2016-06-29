class Solution
{
public:

    int lengthOfLongestSubstring(string s)
    {
        int iFinalResult = 0, aiCharLastIndex[256];
        
        memset((char *)aiCharLastIndex, 0x80, sizeof(aiCharLastIndex));
        
        for (int iIndex = 0, iPrevResult = 0, iCurrResult = 0; iIndex < s.length(); iIndex ++, iPrevResult = iCurrResult)
        {
            iCurrResult = min(iIndex - aiCharLastIndex[s[iIndex]], iPrevResult + 1);
            
            if (iFinalResult < iCurrResult)
            {
                iFinalResult = iCurrResult;
            }
            
            aiCharLastIndex[s[iIndex]] = iIndex;
        }
        
        return iFinalResult;
    }
    
private:

    int min(int iOper1, int iOper2)
    {
        return iOper1 < iOper2 ? iOper1 : iOper2;
    }
};

/*

Dynamic Programming.

Define nrls[i] as the length of the longest substring without repeating whose last character is s[i].

Then, the recursive relation is --> nrls[i] = min { nrls[i-1] + 1, i - lastIndex(s[i]) }, lastIndex(s[i]) = max (j < i, s[j] = s[i]) { j }.

The final result is max { nrls[i] }.

----------------------------------------

Optimization:

1. Change unordered_map to a whole character set indexed array.

2. Change initial value of the set indexed array to reduce judgement once a loop.

*/
