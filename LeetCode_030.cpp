class Solution
{
public:

    vector<int> findSubstring(string s, vector<string> & words)
    {
        vector<int> vecResult;
        
        if (s.empty() || words.size() <= 0)
        {
            return vecResult;
        }
        
        unordered_map<string, int> hmapWordsCount;
        
        for (int iIndex = 0; iIndex < words.size(); iIndex ++)
        {
            unordered_map<string, int>::iterator hmapIterator = hmapWordsCount.find(words[iIndex]);
            
            if (hmapIterator != hmapWordsCount.end())
            {
                hmapIterator -> second ++;
            }
            else
            {
                hmapWordsCount[words[iIndex]] = 1;
            }
        }
        
        int iWordsTotalLength = words[0].length() * words.size();
        
        for (int iIndex = 0; iIndex <= s.length() - iWordsTotalLength; iIndex ++)
        {
            for (int jIndex = iIndex + words[0].length(); jIndex - iIndex <= iWordsTotalLength; jIndex += words[0].length())
            {
                unordered_map<string, int>::iterator hmapIterator = hmapWordsCount.find(s.substr(iIndex, jIndex - iIndex));
                
                if (hmapIterator != hmapWordsCount.end())
                {
                    
                }
                else
                {
                    break;
                }
            }
        }
    }
};
