class Solution
{
public:

    vector<int> largestDivisibleSubset(vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return vector<int>();
        }
        
        int iResultLastIndex = 0;
        vector<int> vecThisLastIndexLDSLength;
        vector<int> vecThisLastIndexLDSPrevIndex;
        
        sort(nums.begin(), nums.end());
        vecThisLastIndexLDSLength.push_back(1);
        vecThisLastIndexLDSPrevIndex.push_back(-1);
        
        for (int iIndex = 1; iIndex < nums.size(); iIndex ++)
        {
            vecThisLastIndexLDSLength.push_back(1);
            vecThisLastIndexLDSPrevIndex.push_back(-1);
            
            for (int jIndex = iIndex - 1; jIndex >= 0; jIndex --)
            {
                if (nums[iIndex] % nums[jIndex] == 0 && vecThisLastIndexLDSLength[jIndex] + 1 > vecThisLastIndexLDSLength[iIndex])
                {
                    vecThisLastIndexLDSLength[iIndex]    = vecThisLastIndexLDSLength[jIndex] + 1;
                    vecThisLastIndexLDSPrevIndex[iIndex] = jIndex;
                }
            }
            
            if (vecThisLastIndexLDSLength[iResultLastIndex] < vecThisLastIndexLDSLength[iIndex])
            {
                iResultLastIndex = iIndex;
            }
        }
        
        vector<int> vecResult;
        
        for (int iIndex = iResultLastIndex; iIndex >= 0; iIndex = vecThisLastIndexLDSPrevIndex[iIndex])
        {
            vecResult.push_back(nums[iIndex]);
        }
        
        return vecResult;
    }
};

/*

Thinking is wrong at first !!! Earnest, you must keep your brain active every day !!!

Dynamic Programming. Define vecThisLastIndexLDSLength[i] as the length of largest divisible subset of which nums[i] is the last element.

The recursive relation is as follow:

vecThisLastIndexLDSLength[i] = max (0<=j<i, nums[i] % nums[j] == 0) { vecThisLastIndexLDSLength[j] + 1 }

*/
