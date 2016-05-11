class Trie;


class TrieNode
{
public:
    
    // Initialize your data structure here.
    TrieNode() : m_bValidWord(false)
    {
        memset(m_apstNext, NULL, sizeof(m_apstNext));
    }
    
private:

    // Valid word flags
    bool m_bValidWord;
    
    // Array of next nodes
    TrieNode * m_apstNext[26];
    
    // Friend class
    friend class Trie;
};


class Trie
{
public:

    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word)
    {
        TrieNode * pstCurrent = root;
        
        for (int iIndex = 0; iIndex < word.length(); iIndex ++)
        {
            int iDstIndex = (int)(word[iIndex] - 'a');
            
            if (pstCurrent -> m_apstNext[iDstIndex] == NULL)
            {
                pstCurrent -> m_apstNext[iDstIndex] = new TrieNode();
            }
            
            pstCurrent = pstCurrent -> m_apstNext[iDstIndex];
        }
        
        pstCurrent -> m_bValidWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word)
    {
        TrieNode * pstCurrent = root;
        
        for (int iIndex = 0; iIndex < word.size(); iIndex ++)
        {
            int iDstIndex = (int)(word[iIndex] - 'a');
            
            if (pstCurrent -> m_apstNext[iDstIndex] == NULL)
            {
                return false;
            }
            
            pstCurrent = pstCurrent -> m_apstNext[iDstIndex];
        }
        
        return pstCurrent -> m_bValidWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        TrieNode * pstCurrent = root;
        
        for (int iIndex = 0; iIndex < prefix.size(); iIndex ++)
        {
            int iDstIndex = (int)(prefix[iIndex] - 'a');
            
            if (pstCurrent -> m_apstNext[iDstIndex] == NULL)
            {
                return false;
            }
            
            pstCurrent = pstCurrent -> m_apstNext[iDstIndex];
        }
        
        return true;
    }

private:

    TrieNode * root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
