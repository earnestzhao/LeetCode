class Solution
{
public:

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> & wordList)
    {
        vector<unordered_set<char>> vecLetterOnIndex;
        
        for (unordered_set<string>::iterator hsetIterator = wordList.begin(); hsetIterator != wordList.end(); hsetIterator ++)
        {
            for (int iIndex = 0; iIndex < (*hsetIterator).length(); iIndex ++)
            {
                if (vecLetterOnIndex.size() <= iIndex)
                {
                    vecLetterOnIndex.push_back(unordered_set<char>());
                }
                
                vecLetterOnIndex[iIndex].insert((*hsetIterator)[iIndex]);
            }
        }
        
        vector<string> vecLadder;
        vecLadder.push_back(beginWord);
        
        unordered_set<string> hsetWordUsed;
        hsetWordUsed.insert(beginWord);
        
        int iMinLength = wordList.size() + 2;
        vector<vector<string>> vecResult;
        
        findLadders(endWord, vecLetterOnIndex, wordList, vecLadder, vecResult, hsetWordUsed, iMinLength);
        return vecResult;
    }
    
private:

    void findLadders(const string & strEndWord, const vector<unordered_set<char>> & vecLetterOnIndex, const unordered_set<string> & hsetWordList,
                     vector<string> & vecLadder, vector<vector<string>> & vecResult, unordered_set<string> & hsetWordUsed, int & iMinLength)
    {
        if (vecLadder.size() > iMinLength)
        {
            return;
        }
        
        if (strEndWord == vecLadder[vecLadder.size() - 1])
        {
            if (vecLadder.size() < iMinLength)
            {
                iMinLength = vecLadder.size();
                vecResult.clear();
            }
            
            vecResult.push_back(vecLadder);
            return;
        }
        
        string strCurrent = vecLadder[vecLadder.size() - 1];
        
        for (int iIndex = 0; iIndex < strCurrent.length(); iIndex ++)
        {
            unordered_set<char>::const_iterator hsetIterator = vecLetterOnIndex[iIndex].begin();
            
            for (; hsetIterator != vecLetterOnIndex[iIndex].end(); hsetIterator ++)
            {
                char cCurrentIndex = strCurrent[iIndex];
                strCurrent[iIndex] = *hsetIterator;
                
                if (hsetWordList.find(strCurrent) != hsetWordList.end() && hsetWordUsed.find(strCurrent) == hsetWordUsed.end())
                {
                    vecLadder.push_back(strCurrent);
                    hsetWordUsed.insert(strCurrent);
                    findLadders(strEndWord, vecLetterOnIndex, hsetWordList, vecLadder, vecResult, hsetWordUsed, iMinLength);
                    hsetWordUsed.erase(strCurrent);
                    vecLadder.pop_back();
                }
                
                strCurrent[iIndex] = cCurrentIndex;
            }
        }
    }
};
