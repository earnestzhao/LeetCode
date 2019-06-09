class Solution
{
public:

    Solution(vector<int> nums)
    {
        m_vecNumbers = std::move(nums);
    }
    
    int pick(int target)
    {
        auto hmapIterator = m_hmapValueIndices.find(target);
        if (hmapIterator == m_hmapValueIndices.end())
        {
            vector<int> vecIndices;
            for (int i = 0; i < m_vecNumbers.size(); i++)
            {
                if (target == m_vecNumbers[i])
                {
                    vecIndices.push_back(i);
                }
            }

            m_hmapValueIndices[target] = std::move(vecIndices);
            hmapIterator = m_hmapValueIndices.find(target);
        }
        
        if (hmapIterator->second.size() <= 0)
        {
            return -1;
        }

        return hmapIterator->second[rand() % hmapIterator->second.size()];
    }
    
private:
    
    vector<int> m_vecNumbers;  
    unordered_map<int, vector<int>> m_hmapValueIndices;
};

