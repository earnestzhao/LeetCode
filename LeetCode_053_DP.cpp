class Solution
{
public:

    int maxSubArray(vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        vector<int> vecMaxIncludingIndex;
        vecMaxIncludingIndex.push_back(nums[0]);
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            vecMaxIncludingIndex.push_back(max(vecMaxIncludingIndex[iIndex - 1] + nums[iIndex], nums[iIndex]));
        }
        
        int iMaxResult = vecMaxIncludingIndex[0];
        
        for (int iIndex = 1; iIndex < vecMaxIncludingIndex.size(); iIndex ++)
        {
            if (vecMaxIncludingIndex[iIndex] > iMaxResult)
            {
                iMaxResult = vecMaxIncludingIndex[iIndex];
            }
        }
        
        return iMaxResult;
    }
    
private:

    int max(int iOper1, int iOper2)
    {
        return iOper1 > iOper2 ? iOper1 : iOper2;
    }
};

/*

Almost bug free, but a low compile error occured.

Normal dynamic programming.

vecMaxIncludingIndex[i] = max { vecMaxIncludingIndex[i-1] + nums[i], nums[i] }

iMaxResult = max (0<=i<n) { vecMaxIncludingIndex[i] }

*/
