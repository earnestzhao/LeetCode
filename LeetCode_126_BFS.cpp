class Solution
{
public:

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> & wordList)
    {
        wordList.insert(endWord);
        
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
        
        unordered_set<string> hsetBFSAccessed;
        unordered_map<string, vector<string>> hmapBFSPrev;
        
        queue<string> queueTraversal;
        queueTraversal.push(beginWord);
        
        while (!queueTraversal.empty())
        {
            string strCurrent = queueTraversal.front();
            string strNext    = strCurrent;
            queueTraversal.pop();
            
            for (int iIndex = 0; iIndex < strCurrent.length(); iIndex ++)
            {
                unordered_set<char>::iterator hsetIterator = vecLetterOnIndex[iIndex].begin();
                
                for (; hsetIterator != vecLetterOnIndex[iIndex].end(); hsetIterator ++)
                {
                    if (strNext[iIndex] != (*hsetIterator))
                    {
                        strNext[iIndex] = (*hsetIterator);
                        
                        if (wordList.find(strNext) != wordList.end())
                        {
                            if (hsetBFSAccessed.find(strNext) == hsetBFSAccessed.end())
                            {
                                hsetBFSAccessed.insert(strNext);
                                
                                if (hmapBFSPrev.find(strNext) != hmapBFSPrev.end())
                                {
                                    hmapBFSPrev[strNext].push_back(strCurrent);
                                }
                                else
                                {
                                    hmapBFSPrev[strNext] = vector<string>(1, strCurrent);
                                }
                                
                                queueTraversal.push(strNext);
                            }
                        }
                        
                        strNext[iIndex] = strCurrent[iIndex];
                    }
                }
            }
            
            if (hmapBFSPrev.find(endWord) != hmapBFSPrev.end())
            {
                break;
            }
        }
        
        vector<string> vecCurrent;
        vecCurrent.push_back(endWord);
        
        vector<vector<string>> vecResult;
        findPath(beginWord, hmapBFSPrev, vecCurrent, vecResult);
        
        for (int iIndex = 0; iIndex < vecResult.size(); iIndex ++)
        {
            reverse(vecResult[iIndex].begin(), vecResult[iIndex].end());
        }
        
        return vecResult;
    }
    
private:

    void findPath(string & strEnd, unordered_map<string, vector<string>> & hmapBFSPrev, vector<string> & vecCurrent, vector<vector<string>> & vecResult)
    {
        string & strCurrent = vecCurrent[vecCurrent.size() - 1];
        
        if (strCurrent == strEnd)
        {
            vecResult.push_back(vecCurrent);
            return;
        }
        
        vector<string> & vecNextList = hmapBFSPrev[strCurrent];
        
        for (int iIndex = 0; iIndex < vecNextList.size(); iIndex ++)
        {
            vecCurrent.push_back(vecNextList[iIndex]);
            findPath(strEnd, hmapBFSPrev, vecCurrent, vecResult);
            vecCurrent.pop_back();
        }
    }
};
