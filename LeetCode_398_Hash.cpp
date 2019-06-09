class Solution
{
public:

    Solution(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            m_hmapValueIndices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target)
    {
        auto vecIndices = m_hmapValueIndices[target];
        return vecIndices[rand() % vecIndices.size()];
    }
    
private:
    
    unordered_map<int, vector<int>> m_hmapValueIndices;
};

