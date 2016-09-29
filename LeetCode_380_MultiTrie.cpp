
// Max Children Power
const int MAX_CHILDREN_POWER = 4;

// Max Children Number
const int MAX_CHILDREN_NUMBER = 2 << MAX_CHILDREN_POWER;

// Number Trie Node
struct NumberTrieNode
{
    // Constructor
    NumberTrieNode() : bEndPoint(false), numberCount(0)
    {
        bzero(next, sizeof(next));
    }
    
    // End Point
    bool bEndPoint;
    
    // Number count
    int numberCount;
    
    // Pointer to next
    struct NumberTrieNode * next[MAX_CHILDREN_NUMBER];
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
        return insert(&m_objNumberTrieRoot, val);
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        return remove(&m_objNumberTrieRoot, val);
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        return getRandom(&m_objNumberTrieRoot);
    }
    
private:

    bool insert(NumberTrieNode * pstCurrent, int iValue)
    {
        if (pstCurrent == NULL)
        {
            return false;
        }
        
        if (iValue == 0)
        {
            if (pstCurrent -> bEndPoint)
            {
                return false;
            }
            
            pstCurrent -> bEndPoint = true;
            pstCurrent -> numberCount ++;
            return true;
        }
        
        int iNextIndex = static_cast<int>(static_cast<unsigned>(iValue) & (MAX_CHILDREN_NUMBER - 1));
        int iNextValue = static_cast<int>(static_cast<unsigned>(iValue) >> MAX_CHILDREN_POWER);
        
        if (pstCurrent -> next[iNextIndex] == NULL)
        {
            pstCurrent -> next[iNextIndex] = new NumberTrieNode;
        }
        
        bool bResult = insert(pstCurrent -> next[iNextIndex], iNextValue);
        
        if (bResult)
        {
            pstCurrent -> numberCount ++;
        }
        
        return bResult;
    }
    
    bool remove(NumberTrieNode * pstCurrent, int iValue)
    {
        if (pstCurrent == NULL)
        {
            return false;
        }
        
        if (iValue == 0)
        {
            if (!pstCurrent -> bEndPoint)
            {
                return false;
            }
            
            pstCurrent -> bEndPoint = false;
            pstCurrent -> numberCount --;
            return true;
        }
        
        int iNextIndex = static_cast<int>(static_cast<unsigned>(iValue) & (MAX_CHILDREN_NUMBER - 1));
        int iNextValue = static_cast<int>(static_cast<unsigned>(iValue) >> MAX_CHILDREN_POWER);
        
        bool bResult = remove(pstCurrent -> next[iNextIndex], iNextValue);
        
        if (bResult)
        {
            pstCurrent -> numberCount --;
        }
        
        return bResult;
    }
    
    int getRandom(NumberTrieNode * pstCurrent)
    {
        if (pstCurrent == NULL)
        {
            throw exception();
        }
        
        if (pstCurrent -> numberCount <= 0)
        {
            throw exception();
        }
        
        int iChooseIndex = 0 - 1;
        int iChooseRound = rand() % pstCurrent -> numberCount;
        
        for (int iIndex = 0, iChooseRange = 0; iIndex < MAX_CHILDREN_NUMBER; iIndex ++)
        {
            if (pstCurrent -> next[iIndex] == NULL)
            {
                continue;
            }
            
            if (iChooseRound < iChooseRange + pstCurrent -> next[iIndex] -> numberCount)
            {
                iChooseIndex = iIndex;
                break;
            }
            
            iChooseRange += pstCurrent -> next[iIndex] -> numberCount;
        }
        
        if (iChooseIndex < 0)
        {
            if (pstCurrent -> bEndPoint)
            {
                return 0;
            }
            
            throw exception();
        }
        
        return (getRandom(pstCurrent -> next[iChooseIndex]) << MAX_CHILDREN_POWER) | iChooseIndex;
    }
    
private:

    NumberTrieNode m_objNumberTrieRoot;
};

/*

Change binary trie tree to multiple trie tree.

After test runtime by leetcode, the fastest 93ms occured on the condition that MAX_CHILDREN_POWER = 5.

Memory Limit Exceeded when MAX_CHILDREN_POWER > 7.

*/
