class RandomizedCollection
{
public:
    
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        m_vecElementList.push_back(val);
        
        unordered_map<int, unordered_set<int>>::iterator hmapIterator = m_hmapStorage.find(val);
        
        if (hmapIterator != m_hmapStorage.end())
        {
            hmapIterator -> second.insert(m_vecElementList.size() - 1);
            return hmapIterator -> second.size() == 1;
        }
        else
        {
            unordered_set<int> hsetIndexes;
            hsetIndexes.insert(m_vecElementList.size() - 1);
            m_hmapStorage[val] = hsetIndexes;
        }
        
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        unordered_map<int, unordered_set<int>>::iterator hmapIterator = m_hmapStorage.find(val);
        
        if (hmapIterator == m_hmapStorage.end() || hmapIterator -> second.empty())
        {
            return false;
        }
        
        int iDeleteIndex = *(hmapIterator -> second.begin());
        
        hmapIterator -> second.erase(iDeleteIndex);
        
        if (iDeleteIndex != m_vecElementList.size() - 1)
        {
            m_vecElementList[iDeleteIndex] = m_vecElementList[m_vecElementList.size() - 1];
            
            hmapIterator = m_hmapStorage.find(m_vecElementList[iDeleteIndex]);
            
            if (hmapIterator != m_hmapStorage.end())
            {
                hmapIterator -> second.erase(m_vecElementList.size() - 1);
                hmapIterator -> second.insert(iDeleteIndex);
            }
        }
        
        m_vecElementList.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom()
    {
        return m_vecElementList[rand() % m_vecElementList.size()];
    }
    
private:

    // Hash Storage
    unordered_map<int, unordered_set<int>> m_hmapStorage;
    
    // Element List
    vector<int> m_vecElementList;
};
