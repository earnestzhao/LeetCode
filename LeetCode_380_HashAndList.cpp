class RandomizedSet
{
public:

    /** Initialize your data structure here. */
    RandomizedSet() : bElementListAvaliable(true)
    {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (hsetStorage.find(val) != hsetStorage.end())
        {
            return false;
        }
        
        hsetStorage.insert(val);
        
        if (bElementListAvaliable)
        {
            vecElementList.push_back(val);
        }
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (hsetStorage.find(val) == hsetStorage.end())
        {
            return false;
        }
        
        hsetStorage.erase(val);
        
        if (vecElementList[vecElementList.size() - 1] == val)
        {
            vecElementList.pop_back();
        }
        else
        {
            bElementListAvaliable = false;
        }
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        if (!bElementListAvaliable)
        {
            vecElementList.clear();
            
            for (unordered_set<int>::iterator hsetIterator = hsetStorage.begin(); hsetIterator != hsetStorage.end(); hsetIterator ++)
            {
                vecElementList.push_back(*hsetIterator);
            }
            
            bElementListAvaliable = true;
        }
        
        return vecElementList[rand() % vecElementList.size()];
    }
    
private:

    // Hash Table Storage
    unordered_set<int> hsetStorage;
    
    // Element List
    vector<int> vecElementList;
    
    // Element List Avaliable
    bool bElementListAvaliable;
};
