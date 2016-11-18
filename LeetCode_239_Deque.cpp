class Solution
{
public:

    vector<int> maxSlidingWindow(vector<int> & nums, int k)
    {
        vector<int> vecResult;
        
        if (nums.size() < k)
        {
            return vecResult;
        }
        
        deque<int> dequeDesc;
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            if (!dequeDesc.empty() && dequeDesc.front() <= iIndex - k)
            {
                dequeDesc.pop_front();
            }
            
            while (!dequeDesc.empty() && nums[dequeDesc.back()] <= nums[iIndex])
            {
                dequeDesc.pop_back();
            }
            
            dequeDesc.push_back(iIndex);
            
            if (iIndex >= k - 1)
            {
                vecResult.push_back(nums[dequeDesc.front()]);
            }
        }
        
        return vecResult;
    }
};

/*

Smart !!! Wonderful !!!

Using deque to keep index, delete the indices which is smaller than nums[i] from back.

The deque is used for keeping a decrease sequence.

*/
