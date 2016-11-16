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
        
        unordered_map<string *, vector<string *>> hmapBFSPrev;
        queue<string *> queueTraversal;
        queueTraversal.push(&beginWord);
        
        while (!queueTraversal.empty())
        {
            string * pstrCurrent = queueTraversal.front();
            string strNext       = *pstrCurrent;
            queueTraversal.pop();
            
            for (int iIndex = 0; iIndex < pstrCurrent -> length(); iIndex ++)
            {
                unordered_set<char>::iterator hsetIterator = vecLetterOnIndex[iIndex].begin();
                
                for (; hsetIterator != vecLetterOnIndex[iIndex].end(); hsetIterator ++)
                {
                    char cCurrentIndex = strNext[iIndex];
                    strNext[iIndex]    = (*hsetIterator);
                    
                    if (wordList.find(strNext) != wordList.end())
                    {
                        string * pstrNext = &wordList[strNext];
                        hmapBFSPrev[pstrNext] = pstrCurrent;
                        queueTraversal.push(pstrNext);
                    }
                }
            }
        }
    }
};
