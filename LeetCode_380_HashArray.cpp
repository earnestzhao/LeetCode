class RandomizedSet
{
public:

    /** Initialize your data structure here. */
    RandomizedSet() : m_bElementListAvaliable(true)
    {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m_hsetStorage.find(val) != m_hsetStorage.end())
        {
            return false;
        }
        
        m_hsetStorage.insert(val);
        
        if (m_bElementListAvaliable)
        {
            m_vecElementList.push_back(val);
        }
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (m_hsetStorage.find(val) == m_hsetStorage.end())
        {
            return false;
        }
        
        m_hsetStorage.erase(val);
        
        if (m_vecElementList[m_vecElementList.size() - 1] == val)
        {
            m_vecElementList.pop_back();
        }
        else
        {
            m_bElementListAvaliable = false;
        }
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        if (!m_bElementListAvaliable)
        {
            m_vecElementList.clear();
            
            for (unordered_set<int>::iterator hsetIterator = m_hsetStorage.begin(); hsetIterator != m_hsetStorage.end(); hsetIterator ++)
            {
                m_vecElementList.push_back(*hsetIterator);
            }
            
            m_bElementListAvaliable = true;
        }
        
        return m_vecElementList[rand() % m_vecElementList.size()];
    }
    
private:

    // Hash Table Storage
    unordered_set<int> m_hsetStorage;
    
    // Element List
    vector<int> m_vecElementList;
    
    // Element List Avaliable
    bool m_bElementListAvaliable;
};
