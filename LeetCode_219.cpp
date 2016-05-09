class HashTable
{
public:
    
    HashTable() : iElementNotFoundResult(-1)
    {
        ppstHashList = new HashNode *[HASH_KEY_DIV]; memset(ppstHashList, 0, sizeof(HashNode *) * HASH_KEY_DIV);
    }
    
    ~HashTable()
    {
        delete [] ppstHashList;
    }
    
    void insert(int iValue, int iIndex)
    {
        HashNode * pstHashNode = new HashNode;
        pstHashNode -> iValue  = iValue;
        pstHashNode -> iIndex  = iIndex;
        pstHashNode -> pstNext = ppstHashList[abs(iValue) % HASH_KEY_DIV];
        ppstHashList[abs(iValue) % HASH_KEY_DIV] = pstHashNode;
    }
    
    int & elementIndex(int iValue)
    {
        for (HashNode * pstHashNode = ppstHashList[abs(iValue) % HASH_KEY_DIV]; pstHashNode != NULL; pstHashNode = pstHashNode -> pstNext)
        {
            if (pstHashNode -> iValue == iValue)
            {
                return pstHashNode -> iIndex;
            }
        }
        
        return iElementNotFoundResult;
    }
    
private:

    enum
    {
        HASH_KEY_DIV = 32749,
    };

    struct HashNode
    {
        int iValue;
        
        int iIndex;
        
        struct HashNode * pstNext;
        
        HashNode() : iValue(0), iIndex(-1), pstNext(NULL)
        {
            
        }
    };
    
    HashNode ** ppstHashList;
    
    int iElementNotFoundResult;
};

class Solution
{
public:

    bool containsNearbyDuplicate(vector<int> & nums, int k)
    {
        HashTable objHashTable;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            int & iElemIndex = objHashTable.elementIndex(nums[iIndex]);
            
            if (iElemIndex >= 0)
            {
                if (abs(iIndex - iElemIndex) <= k)
                {
                    return true;
                }
                else
                {
                    iElemIndex = iIndex;
                }
            }
            else
            {
                objHashTable.insert(nums[iIndex], iIndex);
            }
        }
        
        return false;
    }
};

/*

Hash Table: O(n)

Replace smaller index with bigger one on the same element.

*/
