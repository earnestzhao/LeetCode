
struct LRUListNode
{
    LRUListNode(int iKey, int iValue) : key(iKey), value(iValue), left(NULL), right(NULL)
    {
        
    }
    
    // Key
    int key;
    
    // Value
    int value;
    
    // Left Pointer
    struct LRUListNode * left;
    
    // Right Pointer
    struct LRUListNode * right;
};

class LRUCache
{
public:

    LRUCache(int capacity) : m_iCount(0), m_iCapacity(capacity), m_pstHead(NULL), m_pstTail(NULL), m_hmapIndex(2 * capacity)
    {
        m_pstHead = new LRUListNode(INT_MIN, INT_MIN);
        m_pstTail = new LRUListNode(INT_MAX, INT_MAX);
        
        m_pstTail -> left  = m_pstHead;
        m_pstHead -> right = m_pstTail;
    }
    
    int get(int key)
    {
        unordered_map<int, LRUListNode *>::iterator hmapIterator = m_hmapIndex.find(key);
        
        if (hmapIterator != m_hmapIndex.end())
        {
            LRUListNode * pstDstNode     = hmapIterator -> second;
            pstDstNode -> left  -> right = pstDstNode -> right;
            pstDstNode -> right -> left  = pstDstNode -> left;
            
            pstDstNode -> left           = m_pstHead;
            pstDstNode -> right          = m_pstHead -> right;
            pstDstNode -> left  -> right = pstDstNode;
            pstDstNode -> right -> left  = pstDstNode;
            
            return pstDstNode -> value;
        }
        
        return -1;
    }
    
    void set(int key, int value)
    {
        unordered_map<int, LRUListNode *>::iterator hmapIterator = m_hmapIndex.find(key);
        
        LRUListNode * pstDstNode = NULL;
        
        if (hmapIterator != m_hmapIndex.end())
        {
            pstDstNode                   = hmapIterator -> second;
            pstDstNode -> value          = value;
            pstDstNode -> left  -> right = pstDstNode -> right;
            pstDstNode -> right -> left  = pstDstNode -> left;
        }
        else
        {
            if (m_iCount >= m_iCapacity)
            {
                pstDstNode = m_pstTail -> left;
                m_hmapIndex.erase(pstDstNode -> key);
                
                pstDstNode -> key            = key;
                pstDstNode -> value          = value;
                pstDstNode -> left  -> right = pstDstNode -> right;
                pstDstNode -> right -> left  = pstDstNode -> left;
            }
            else
            {
                pstDstNode = new LRUListNode(key, value);
                m_iCount ++;
            }
        }
        
        pstDstNode -> left           = m_pstHead;
        pstDstNode -> right          = m_pstHead -> right;
        pstDstNode -> left  -> right = pstDstNode;
        pstDstNode -> right -> left  = pstDstNode;
        m_hmapIndex[key]             = pstDstNode;
    }
    
private:

    // Count
    int m_iCount;

    // Capacity
    int m_iCapacity;
    
    // Head of list
    LRUListNode * m_pstHead;
    
    // Tail of list
    LRUListNode * m_pstTail;
    
    // Node Index
    unordered_map<int, LRUListNode *> m_hmapIndex;
};
