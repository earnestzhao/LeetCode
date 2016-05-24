class Solution
{
public:

    vector<vector<string>> groupAnagrams(vector<string> & strs)
    {
        sort(strs.begin(), strs.end());
        
        unordered_map<string, vector<string>> hmapSymbolToStrList;
        
        for (int iIndex = 0; iIndex < strs.size(); iIndex ++)
        {
            string strSymbol = strs[iIndex];
            
            sort(strSymbol.begin(), strSymbol.end());
            
            unordered_map<string, vector<string>>::iterator hmapIterator = hmapSymbolToStrList.find(strSymbol);
            
            if (hmapIterator != hmapSymbolToStrList.end())
            {
                hmapIterator -> second.push_back(strs[iIndex]);
            }
            else
            {
                hmapSymbolToStrList[strSymbol] = vector<string>(1, strs[iIndex]);
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

Not completely understanding the main topic of the question, so the first submittion is wrong.

Correct algorithm:

1. Get each string's symbol by sorting.

2. For each symbol, keep a list of strings which has this symbol.

3. Finally, output them.

There must be better solutions. Research it later.

*/
