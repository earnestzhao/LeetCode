class Solution
{
public:

    vector<vector<string>> groupAnagrams(vector<string> & strs)
    {
        sort(strs.begin(), strs.end());
        
        unordered_map<string, vector<string>> hmapSymbolToStrList;
        
        for (int iIndex = 0; iIndex < strs.size(); iIndex ++)
        {
            vector<int> vecSymbol(26, 0);
            
            for (int jIndex = 0; jIndex < strs[iIndex].size(); jIndex ++)
            {
                vecSymbol[(int)(strs[iIndex][jIndex] - 'a')] ++;
            }
            
            ostringstream ossSymbol;
            
            for (int jIndex = 0; jIndex < vecSymbol.size(); jIndex ++)
            {
                if (vecSymbol[jIndex] > 0)
                {
                    ossSymbol << (char)('a' + jIndex) << vecSymbol[jIndex];
                }
            }
            
            unordered_map<string, vector<string>>::iterator hmapIterator = hmapSymbolToStrList.find(ossSymbol.str());
            
            if (hmapIterator != hmapSymbolToStrList.end())
            {
                hmapIterator -> second.push_back(strs[iIndex]);
            }
            else
            {
                hmapSymbolToStrList[ossSymbol.str()] = vector<string>(1, strs[iIndex]);
            }
        }
        
        vector<vector<string>> vecResult;
        
        unordered_map<string, vector<string>>::iterator hmapIterator = hmapSymbolToStrList.begin();
        
        for (; hmapIterator != hmapSymbolToStrList.end(); hmapIterator ++)
        {
            vecResult.push_back(hmapIterator -> second);
        }
        
        return vecResult;
    }
};

/*

Another calculation of symbol. The calculation's time complex: O(n)

The strings are short, so the runtime is more than sorting calculation, although the time complex is better.

*/
