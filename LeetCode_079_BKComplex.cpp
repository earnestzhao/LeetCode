class Solution
{
public:

    bool exist(vector<vector<char>> & board, string word)
    {
        if (word.length() <= 0)
        {
            return false;
        }
        
        if (board.size() <= 0)
        {
            return false;
        }
        
        if (board[0].size() <= 0)
        {
            return false;
        }
        
        vector<unordered_set<int>> vecLetterPosition(52, unordered_set<int>());
        
        for (int iIndex = 0; iIndex < board.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < board[iIndex].size(); jIndex ++)
            {
                vecLetterPosition[letterIndex(board[iIndex][jIndex])].insert(iIndex * board[iIndex].size() + jIndex);
            }
        }
        
        vector<int>  vecWordIndex;
        vector<bool> vecPositionVisited(board.size() * board[0].size(), false);
        return exist(board[0].size(), vecLetterPosition, word, vecWordIndex, vecPositionVisited);
    }
    
private:

    bool exist(int iRowElemNum, const vector<unordered_set<int>> & vecLetterPosition, const string & strWord, vector<int> & vecWordIndex, vector<bool> & vecPositionVisited)
    {
        if (vecWordIndex.size() >= strWord.length())
        {
            return true;
        }
        
        const unordered_set<int> & hsetLetterPosition = vecLetterPosition[(int)(letterIndex(strWord[vecWordIndex.size()]))];
        
        if (hsetLetterPosition.size() <= 0)
        {
            return false;
        }
        
        if (vecWordIndex.size() >= 1)
        {
            int iExpectRight = vecWordIndex[vecWordIndex.size() - 1] + 1;
            int iExpectLeft  = vecWordIndex[vecWordIndex.size() - 1] - 1;
            int iExpectDown  = vecWordIndex[vecWordIndex.size() - 1] + iRowElemNum;
            int iExpectUp    = vecWordIndex[vecWordIndex.size() - 1] - iRowElemNum;
            
            bool bRightExist = false;
            bool bLeftExist  = false;
            bool bDownExist  = false;
            bool bUpExist    = false;
            
            if (iExpectRight % iRowElemNum != 0 && hsetLetterPosition.find(iExpectRight) != hsetLetterPosition.end())
            {
                if (!vecPositionVisited[iExpectRight])
                {
                    vecWordIndex.push_back(iExpectRight);
                    vecPositionVisited[iExpectRight] = true;
                    bRightExist = exist(iRowElemNum, vecLetterPosition, strWord, vecWordIndex, vecPositionVisited);
                    vecPositionVisited[iExpectRight] = false;
                    vecWordIndex.pop_back();
                }
                
                if (bRightExist)
                {
                    return true;
                }
            }
            
            if (iExpectLeft % iRowElemNum != iRowElemNum - 1 && hsetLetterPosition.find(iExpectLeft) != hsetLetterPosition.end())
            {
                if (!vecPositionVisited[iExpectLeft])
                {
                    vecWordIndex.push_back(iExpectLeft);
                    vecPositionVisited[iExpectLeft] = true;
                    bLeftExist = exist(iRowElemNum, vecLetterPosition, strWord, vecWordIndex, vecPositionVisited);
                    vecPositionVisited[iExpectLeft] = false;
                    vecWordIndex.pop_back();
                }
                
                if (bLeftExist)
                {
                    return true;
                }
            }
            
            if (hsetLetterPosition.find(iExpectDown) != hsetLetterPosition.end())
            {
                if (!vecPositionVisited[iExpectDown])
                {
                    vecWordIndex.push_back(iExpectDown);
                    vecPositionVisited[iExpectDown] = true;
                    bDownExist = exist(iRowElemNum, vecLetterPosition, strWord, vecWordIndex, vecPositionVisited);
                    vecPositionVisited[iExpectDown] = false;
                    vecWordIndex.pop_back();
                }
                
                if (bDownExist)
                {
                    return true;
                }
            }
            
            if (hsetLetterPosition.find(iExpectUp) != hsetLetterPosition.end())
            {
                if (!vecPositionVisited[iExpectUp])
                {
                    vecWordIndex.push_back(iExpectUp);
                    vecPositionVisited[iExpectUp] = true;
                    bUpExist = exist(iRowElemNum, vecLetterPosition, strWord, vecWordIndex, vecPositionVisited);
                    vecPositionVisited[iExpectUp] = false;
                    vecWordIndex.pop_back();
                }
                
                if (bUpExist)
                {
                    return true;
                }
            }
            
            return false;
        }
        else
        {
            for (unordered_set<int>::const_iterator hsetIterator = hsetLetterPosition.cbegin(); hsetIterator != hsetLetterPosition.cend(); hsetIterator ++)
            {
                vecWordIndex.push_back(*hsetIterator);
                vecPositionVisited[*hsetIterator] = true;
                bool bExist = exist(iRowElemNum, vecLetterPosition, strWord, vecWordIndex, vecPositionVisited);
                vecPositionVisited[*hsetIterator] = false;
                vecWordIndex.pop_back();
                
                if (bExist)
                {
                    return true;
                }
            }
            
            return false;
        }
    }
    
    int letterIndex(char cLetter)
    {
        if (cLetter >= 'A' && cLetter <= 'Z')
        {
            return (int)(cLetter - 'A');
        }
        
        if (cLetter >= 'a' && cLetter <= 'z')
        {
            return (int)(cLetter - 'a') + 26;
        }
        
        return -1;
    }
};

/*

Thinking is right, but many small bugs, including an edge condition.

Normal backtracking, but it is slow and complex.

1. Collect letter positions into an data structure which a position hash table is occupied by each letter.

2. Call exist backtracking method which search for next letter's positions and previous letter's position.

3. If each next letter's position is adjacent with the previous letter, then do the next recursing on them.

There must be easier and less complex methods. Research it later.

*/
