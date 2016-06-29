class Solution
{
public:

    int lengthOfLongestSubstring(string s)
    {
        int iFinalResult = 0;
        
        unordered_map<char, int> hmapCharLastIndex;
        
        for (int iIndex = 0, iPrevResult = 0, iCurrResult = 0; iIndex < s.length(); iIndex ++, iPrevResult = iCurrResult)
        {
            unordered_map<char, int>::iterator hmapIterator = hmapCharLastIndex.find(s[iIndex]);
            
            if (hmapIterator != hmapCharLastIndex.end())
            {
                iCurrResult = min(iIndex - hmapIterator -> second, iPrevResult + 1);
            }
            else
            {
                iCurrResult = iPrevResult + 1;
            }
            
            if (iFinalResult < iCurrResult)
            {
                iFinalResult = iCurrResult;
            }
            
            hmapCharLastIndex[s[iIndex]] = iIndex;
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

*/
