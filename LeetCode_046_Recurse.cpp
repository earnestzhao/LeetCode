class Solution
{
public:

    vector<vector<int>> permute(vector<int> & nums)
    {
        vector<vector<int>> vecResult;
        
        permute(nums, 0, vecResult);
        
        return vecResult;
    }
    
private:

    void permute(const vector<int> & vecNumList, int iStartIndex, vector<vector<int>> & vecResult)
    {
        if (iStartIndex >= vecNumList.size())
        {
            return;
        }
        
        if (iStartIndex == vecNumList.size() - 1)
        {
            vecResult.push_back(vector<int>(1, vecNumList[iStartIndex]));
            return;
        }
        
        permute(vecNumList, iStartIndex + 1, vecResult);
        
        int iResultSize = vecResult.size();
        
        for (int iIndex = 0; iIndex < iResultSize; iIndex ++)
        {
            vector<int> vecCurrent = vecResult[iIndex];
            vecCurrent.push_back(vecNumList[iStartIndex]);
            
            for (int jIndex = vecCurrent.size() - 1; jIndex > 0; jIndex --)
            {
                swap(vecCurrent[jIndex], vecCurrent[jIndex - 1]);
                vecResult.push_back(vecCurrent);
            }
            
            vecResult[iIndex].push_back(vecNumList[iStartIndex]);
        }
    }
    
    void swap(int & iOper1, int & iOper2)
    {
        iOper1 ^= iOper2;
        iOper2 ^= iOper1;
        iOper1 ^= iOper2;
    }
};

/*

Bug free once. Normal recursing.

*/
