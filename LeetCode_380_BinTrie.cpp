
// Number Trie Node
struct NumberTrieNode
{
    // Constructor
    NumberTrieNode() : next0(NULL), next1(NULL), count0(0), count1(0)
    {
        
    }
    
    // Pointer Next 0
    struct NumberTrieNode * next0;
    
    // Pointer Next 1
    struct NumberTrieNode * next1;
    
    // Count 0
    int count0;
    
    // Count 1
    int count1;
};

class RandomizedSet
{
public:

    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        return insert(&m_objNumberTrieRoot, val, 0, false);
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        return remove(&m_objNumberTrieRoot, val, 0);
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        int iBitIndex     = 0;
        int iSelectValue  = 0;
        int iRandomResult = 0;
        
        for (NumberTrieNode * pstCurrent = &m_objNumberTrieRoot; pstCurrent != NULL; iBitIndex ++)
        {
            if (pstCurrent -> count0 > 0 && pstCurrent -> count1 > 0)
            {
                iSelectValue = rand() % (pstCurrent -> count0 + pstCurrent -> count1);
                
                if (iSelectValue < pstCurrent -> count0)
                {
                    pstCurrent = pstCurrent -> next0;
                }
                else
                {
                    pstCurrent = pstCurrent -> next1, iRandomResult |= (1 << iBitIndex);
                }
            }
            else
            {
                if (pstCurrent -> count0 > 0)
                {
                    pstCurrent = pstCurrent -> next0;
                }
                else if (pstCurrent -> count1 > 0)
                {
                    pstCurrent = pstCurrent -> next1, iRandomResult |= (1 << iBitIndex);
                }
                else
                {
                    break;
                }
            }
        }
        
        return iRandomResult;
    }
    
private:

    bool insert(NumberTrieNode * pstCurrent, int iValue, int iBitIndex, bool bNodeCreated)
    {
        if (iBitIndex >= sizeof(int) * 8)
        {
            return bNodeCreated;
        }
        
        bool bNextInsertResult = false;
        
        if (iValue & (1 << iBitIndex))
        {
            if (pstCurrent -> next1 == NULL)
            {
                bNodeCreated = true;
                pstCurrent -> next1 = new NumberTrieNode;
            }
            
            bNextInsertResult = insert(pstCurrent -> next1, iValue, iBitIndex + 1, bNodeCreated);
            
            if (bNextInsertResult)
            {
                pstCurrent -> count1 ++;
            }
        }
        else
        {
            if (pstCurrent -> next0 == NULL)
            {
                bNodeCreated = true;
                pstCurrent -> next0 = new NumberTrieNode;
            }
            
            bNextInsertResult = insert(pstCurrent -> next0, iValue, iBitIndex + 1, bNodeCreated);
            
            if (bNextInsertResult)
            {
                pstCurrent -> count0 ++;
            }
        }
        
        return bNextInsertResult;
    }
    
    bool remove(NumberTrieNode * pstCurrent, int iValue, int iBitIndex)
    {
        if (iBitIndex >= sizeof(int) * 8)
        {
            return true;
        }
        
        if (pstCurrent == NULL)
        {
            return false;
        }
        
        bool bNextDeleteResult = false;
        
        if (iValue & (1 << iBitIndex))
        {
            bNextDeleteResult = remove(pstCurrent -> next1, iValue, iBitIndex + 1);
            
            if (bNextDeleteResult)
            {
                pstCurrent -> count1 --;
                
                if (pstCurrent -> next1 != NULL && pstCurrent -> next1 -> next0 == NULL && pstCurrent -> next1 -> next1 == NULL)
                {
                    pstCurrent -> next1 = NULL;
                }
            }
        }
        else
        {
            bNextDeleteResult = remove(pstCurrent -> next0, iValue, iBitIndex + 1);
            
            if (bNextDeleteResult)
            {
                pstCurrent -> count0 --;
                
                if (pstCurrent -> next0 != NULL && pstCurrent -> next0 -> next0 == NULL && pstCurrent -> next0 -> next1 == NULL)
                {
                    pstCurrent -> next0 = NULL;
                }
            }
        }
        
        return bNextDeleteResult;
    }
    
private:

    NumberTrieNode m_objNumberTrieRoot;
};

/*

Thinking is right, but a lot of bugs in pointer operation.

Binary Trie Tree. Time complexity: O(sizeof(int) * 8) = O(1).

1. Store integer as a path of bit trie node.

2. Record subtree's count, and generate random select value by this count.

*/
