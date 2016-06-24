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
        
        for (int iIndex = 0; iIndex <= (int)(s.length()) - iWordsTotalLength; iIndex ++)
        {
            int iCurrWordsCount = 0;
            bool bMatchFailed = false;
            unordered_map<string, int> hmapCurrent;
            
            for (int jIndex = iIndex + words[0].length(); jIndex - iIndex <= iWordsTotalLength; jIndex += words[0].length())
            {
                unordered_map<string, int>::iterator hmitWordsCount = hmapWordsCount.find(s.substr(jIndex - words[0].length(), words[0].length()));
                
                if (hmitWordsCount != hmapWordsCount.end())
                {
                    unordered_map<string, int>::iterator hmitCurrent = hmapCurrent.find(hmitWordsCount -> first);
                    
                    if (hmitCurrent != hmapCurrent.end())
                    {
                        hmitCurrent -> second ++;
                        
                        if (hmitCurrent -> second > hmitWordsCount -> second)
                        {
                            bMatchFailed = true;
                            break;
                        }
                    }
                    else
                    {
                        hmapCurrent[hmitWordsCount -> first] = 1;
                    }
                    
                    iCurrWordsCount ++;
                }
                else
                {
                    bMatchFailed = true;
                    break;
                }
            }
            
            if (!bMatchFailed && iCurrWordsCount == words.size() && hmapCurrent.size() == hmapWordsCount.size())
            {
                vecResult.push_back(iIndex);
            }
        }
        
        return vecResult;
    }
};

/*

Thinking is right, but small bugs occured.

Normal algorithm. Using unordered_map to optimize runtime.

There must be better solutions. Research it later.

*/
