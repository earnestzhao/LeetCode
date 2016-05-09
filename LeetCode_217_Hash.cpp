class HashTable
{
public:
    
    HashTable()
    {
        ppstHashList = new HashNode *[HASH_KEY_DIV]; memset(ppstHashList, NULL, sizeof(HashNode *) * HASH_KEY_DIV);
    }
    
    ~HashTable()
    {
        delete [] ppstHashList;
    }
    
    void insert(int iValue)
    {
        HashNode * pstHashNode = new HashNode;
        pstHashNode -> iValue  = iValue;
        pstHashNode -> pstNext = ppstHashList[abs(iValue) % HASH_KEY_DIV];
        ppstHashList[abs(iValue) % HASH_KEY_DIV] = pstHashNode;
    }
    
    bool elementExist(int iValue)
    {
        for (HashNode * pstHashNode = ppstHashList[abs(iValue) % HASH_KEY_DIV]; pstHashNode != NULL; pstHashNode = pstHashNode -> pstNext)
        {
            if (pstHashNode -> iValue == iValue)
            {
                return true;
            }
        }
        
        return false;
    }
    
private:

    enum
    {
        HASH_KEY_DIV = 32749,
    };

    struct HashNode
    {
        int iValue;
        
        struct HashNode * pstNext;
        
        HashNode() : iValue(0), pstNext(NULL)
        {
            
        }
    };
    
    HashNode ** ppstHashList;
};

class Solution
{
public:

    bool containsDuplicate(vector<int> & nums)
    {
        HashTable objHashTable;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            if (objHashTable.elementExist(nums[iIndex]))
            {
                return true;
            }
            else
            {
                objHashTable.insert(nums[iIndex]);
            }
        }
        
        return false;
    }
};

/*

Hash Table: O(n).

Space Complexity: O(max(hash))

Many compile errors and bugs when implement hash table.

Negative MOD...!!!

*/
