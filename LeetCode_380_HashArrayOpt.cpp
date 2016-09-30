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
        if (m_hmapStorage.find(val) != m_hmapStorage.end())
        {
            return false;
        }
        
        m_vecElementList.push_back(val);
        m_hmapStorage[val] = m_vecElementList.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        unordered_map<int, int>::iterator hmapIterator = m_hmapStorage.find(val);
        
        if (hmapIterator == m_hmapStorage.end())
        {
            return false;
        }
        
        int iElementListTailValue = m_vecElementList[m_vecElementList.size() - 1];
        
        if (iElementListTailValue != val)
        {
            m_vecElementList[hmapIterator -> second] = iElementListTailValue;
            m_hmapStorage[iElementListTailValue]     = hmapIterator -> second;
        }
        
        m_vecElementList.pop_back();
        m_hmapStorage.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        return m_vecElementList[rand() % m_vecElementList.size()];
    }
    
private:

    // Hash Table Storage
    unordered_map<int, int> m_hmapStorage;
    
    // Element List
    vector<int> m_vecElementList;
};

/*

Optimization on DELETE: Change order !!!

*/
