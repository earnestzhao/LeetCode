class Solution
{
public:

    vector<int> maxSlidingWindow(vector<int> & nums, int k)
    {
        vector<int> vecResult;
        
        if (nums.size() <= 0)
        {
            return vecResult;
        }
        
        multiset<int> msetWindowSizeElements;
        
        for (int iIndex = 0; iIndex < k; iIndex ++)
        {
            msetWindowSizeElements.insert(nums[iIndex]);
        }
        
        vecResult.push_back(*msetWindowSizeElements.rbegin());
        
        for (int iIndex = k; iIndex < nums.size(); iIndex ++)
        {
            msetWindowSizeElements.erase(msetWindowSizeElements.find(nums[iIndex - k]));
            msetWindowSizeElements.insert(nums[iIndex]);
            vecResult.push_back(*msetWindowSizeElements.rbegin());
        }
        
        return vecResult;
    }
};

/*

Using 'multiset'. Time complexity: O(nlogn)

*/
