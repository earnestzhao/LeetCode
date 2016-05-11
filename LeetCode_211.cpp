class WordDictionary;


class TrieNode
{
public:
    
    TrieNode() : m_bValidWord(false)
    {
        memset(m_apstNext, NULL, sizeof(m_apstNext));
    }
    
private:

    bool m_bValidWord;
    
    TrieNode * m_apstNext[26];
    
    friend class WordDictionary;
};


class WordDictionary
{
public:

    WordDictionary()
    {
        m_pstRoot = new TrieNode;
    }

    // Adds a word into the data structure.
    void addWord(string word)
    {
        TrieNode * pstCurrent = m_pstRoot;
        
        for (int iIndex = 0; iIndex < word.size(); iIndex ++)
        {
            int iDstIndex = (int)(word[iIndex] - 'a');
            
            if (pstCurrent -> m_apstNext[iDstIndex] == NULL)
            {
                pstCurrent -> m_apstNext[iDstIndex] = new TrieNode;
            }
            
            pstCurrent = pstCurrent -> m_apstNext[iDstIndex];
        }
        
        pstCurrent -> m_bValidWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word)
    {
        return search(word, 0, m_pstRoot);
    }
    
private:

    bool search(const string & strWord, int iStartIndex, TrieNode * pstRoot)
    {
        if (pstRoot == NULL)
        {
            return false;
        }
        
        if (iStartIndex > strWord.size())
        {
            return false;
        }
        
        if (iStartIndex == strWord.size())
        {
            return pstRoot -> m_bValidWord;
        }
        
        vector<int> vecNextIndexList;
        
        if (strWord[iStartIndex] != '.')
        {
            int iDstIndex = (int)(strWord[iStartIndex] - 'a');
            
            if (pstRoot -> m_apstNext[iDstIndex] != NULL)
            {
                vecNextIndexList.push_back(iDstIndex);
            }
        }
        else
        {
            for (int jIndex = 0; jIndex < sizeof(pstRoot -> m_apstNext) / sizeof(pstRoot -> m_apstNext[0]); jIndex ++)
            {
                if (pstRoot -> m_apstNext[jIndex] != NULL)
                {
                    vecNextIndexList.push_back(jIndex);
                }
            }
        }
        
        for (int iIndex = 0; iIndex < vecNextIndexList.size(); iIndex ++)
        {
            if (search(strWord, iStartIndex + 1, pstRoot -> m_apstNext[vecNextIndexList[iIndex]]))
            {
                return true;
            }
        }
        
        return false;
    }
    
private:

    TrieNode * m_pstRoot;
};

/*

Backtracking and Trie. Not bug free... Index error which is too low.

Build a trie to store words. Insert the word as usual.

When searching, if the current charactor is '.', then, fetch all stored charactors in to a list vecNextIndexList

and do a deep first search. If a valid word found, then, return true.

There maybe a better solution, research it later.

*/
