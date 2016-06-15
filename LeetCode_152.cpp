class Solution
{
public:

    int maxProduct(vector<int> & nums)
    {
        vector<int> vecMaxOnIndex;
        vecMaxOnIndex.push_back(nums[0]);
        
        vector<int> vecMinOnIndex;
        vecMinOnIndex.push_back(nums[0]);
        
        int iMaxProductIndex = 0;
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            int iCurrMaxMulValue = vecMaxOnIndex[iIndex - 1] * nums[iIndex];
            int iCurrMinMulValue = vecMinOnIndex[iIndex - 1] * nums[iIndex];
            
            vecMaxOnIndex.push_back(max(iCurrMaxMulValue, iCurrMinMulValue, nums[iIndex]));
            vecMinOnIndex.push_back(min(iCurrMaxMulValue, iCurrMinMulValue, nums[iIndex]));
            
            if (vecMaxOnIndex[iIndex] > vecMaxOnIndex[iMaxProductIndex])
            {
                iMaxProductIndex = iIndex;
            }
        }
        
        return vecMaxOnIndex[iMaxProductIndex];
    }
    
private:

    int max(int iOper1, int iOper2, int iOper3)
    {
        int iResult = iOper1;
        
        if (iOper2 > iResult)
        {
            iResult = iOper2;
        }
        
        if (iOper3 > iResult)
        {
            iResult = iOper3;
        }
        
        return iResult;
    }
    
    int min(int iOper1, int iOper2, int iOper3)
    {
        int iResult = iOper1;
        
        if (iOper2 < iResult)
        {
            iResult = iOper2;
        }
        
        if (iOper3 < iResult)
        {
            iResult = iOper3;
        }
        
        return iResult;
    }
};

/*

Thinking is not right at first. It is bug free once after the right thinking.

Dynamic programming. Time complexity: O(n).

Because of multiply calculation, the recursive relation is as follows:

vecMaxOnIndex[i] = max { vecMaxOnIndex[i-1] * nums[i], vecMinOnIndex[i-1] * nums[i], nums[i] }.

vecMinOnIndex[i] = min { vecMaxOnIndex[i-1] * nums[i], vecMinOnIndex[i-1] * nums[i], nums[i] }.

The result is max (0<=i<=n-1) { vecMaxOnIndex[i] }.

*/
