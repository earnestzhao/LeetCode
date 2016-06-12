class Solution
{
public:

    int ladderLength(string beginWord, string endWord, unordered_set<string> & wordList)
    {
        queue<string> queueTravesal;
        queueTravesal.push(beginWord);
        queueTravesal.push(";");
        wordList.insert(endWord);
        
        int iFinalResult = 1;
        
        while (!queueTravesal.empty())
        {
            string strCurrElem = queueTravesal.front();
            queueTravesal.pop();
            
            if (strCurrElem == ";")
            {
                if (queueTravesal.empty())
                {
                    return 0;
                }
                
                iFinalResult ++;
                queueTravesal.push(";");
            }
            else
            {
                if (strCurrElem == endWord)
                {
                    return iFinalResult;
                }
                
                vector<string> vecNextElem;
                
                for (unordered_set<string>::iterator hsetIterator = wordList.begin(); hsetIterator != wordList.end(); hsetIterator ++)
                {
                    if (isAdjust(strCurrElem, *hsetIterator))
                    {
                        queueTravesal.push(*hsetIterator);
                        vecNextElem.push_back(*hsetIterator);
                    }
                }
                
                for (int iIndex = 0; iIndex < vecNextElem.size(); iIndex ++)
                {
                    wordList.erase(vecNextElem[iIndex]);
                }
            }
        }
        
        return 0;
    }
    
private:

    bool isAdjust(const string & strWord1, const string & strWord2)
    {
        int iDiffCount = 0;
        
        for (int iIndex = 0; iIndex < strWord1.size() && iDiffCount <= 1; iIndex ++)
        {
            if (strWord1[iIndex] != strWord2[iIndex])
            {
                iDiffCount ++;
            }
        }
        
        return iDiffCount == 1;
    }
};

/*

Thinking is right, but a compile bug and a small bug.

Breadth-first search, using string compare each time.

1. Add adjust elements into queue, and delete them from word list.

2. Increase the final result variety once a level.

3. Return the final result if travesal to 'endWord', otherwise, return 0.

There must exist better solutions. This solution cost run-time more than 1s, too slow.

*/
