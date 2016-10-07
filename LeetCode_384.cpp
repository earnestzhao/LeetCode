class Solution
{
public:

    Solution(vector<int> nums)
    {
        m_vecNumberListRaw     = nums;
        m_vecNumberListCurrent = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        m_vecNumberListCurrent = m_vecNumberListRaw;
        return m_vecNumberListCurrent;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int iIndex = 0; iIndex < m_vecNumberListCurrent.size(); iIndex ++)
        {
            int iSwapIndex                     = rand() % m_vecNumberListCurrent.size();
            int iSwapValue                     = m_vecNumberListCurrent[iSwapIndex];
            m_vecNumberListCurrent[iSwapIndex] = m_vecNumberListCurrent[iIndex];
            m_vecNumberListCurrent[iIndex]     = iSwapValue;
        }
        
        return m_vecNumberListCurrent;
    }
    
private:

    vector<int> m_vecNumberListRaw;
    vector<int> m_vecNumberListCurrent;
};
