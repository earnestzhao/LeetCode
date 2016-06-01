class Solution
{
public:
    
    int minSubArrayLen(int s, vector<int> & nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }
        
        vector<int> vecSumList;
        vecSumList.push_back(0);
        
        for (int iIndex = 0; iIndex < nums.size(); iIndex ++)
        {
            vecSumList.push_back(vecSumList[iIndex] + nums[iIndex]);
        }
        
        int iResultLength = INT_MAX;
        
        for (int iIndex = 0; iIndex < vecSumList.size(); iIndex ++)
        {
            int iSearchResult = binarySearchBE(vecSumList, iIndex + 1, vecSumList.size() - 1, vecSumList[iIndex] + s);
            
            if (iSearchResult > 0 && iSearchResult - iIndex < iResultLength)
            {
                iResultLength = iSearchResult - iIndex;
            }
        }
        
        return iResultLength == INT_MAX ? 0 : iResultLength;
    }
    
private:

    int binarySearchBE(const vector<int> & vecNumList, int iStartIndex, int iEndIndex, int iTarget)
    {
        while (iStartIndex <= iEndIndex)
        {
            int iMidIndex = iStartIndex + (iEndIndex - iStartIndex) / 2;
            
            if (vecNumList[iMidIndex] == iTarget)
            {
                return iMidIndex;
            }
            
            if (iTarget < vecNumList[iMidIndex])
            {
                iEndIndex = iMidIndex - 1;
            }
            else
            {
                iStartIndex = iMidIndex + 1;
            }
        }
        
        return iStartIndex < vecNumList.size() ? iStartIndex : -1;
    }
};

/*

The algorithm is simply understanded based on binary search.

1. Build vecSumList, where vecSumList[i] = sigma(0<=j<=i-1) { nums[j] }, vecSumList[0] = 0.

2. For each element vecSumList[i] in vecSumList, binary search the element which is just no smaller than vecSumList[i] + s.

3. Update minimum result in each time of loop of step 2.

Time Complex: O(nlogn)

*/
