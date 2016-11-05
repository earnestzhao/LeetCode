class Solution
{
public:

    vector<int> productExceptSelf(vector<int> & nums)
    {
        vector<int> vecResult;
        
        if (nums.size() <= 0)
        {
            return vecResult;
        }
        
        vecResult.push_back(1);
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            vecResult.push_back(vecResult[iIndex - 1] * nums[iIndex - 1]);
        }
        
        for (int iIndex = nums.size() - 1, iMultiResult = 1; iIndex >= 0; iMultiResult *= nums[iIndex], iIndex --)
        {
            vecResult[iIndex] *= iMultiResult;
        }
        
        return vecResult;
    }
};
