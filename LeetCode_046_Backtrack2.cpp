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

    void permute(vector<int> & vecNumList, int iStartIndex, vector<vector<int>> & vecResult)
    {
        if (iStartIndex == vecNumList.size() - 1)
        {
            vecResult.push_back(vecNumList);
            return;
        }
        
        for (int iIndex = iStartIndex; iIndex < vecNumList.size(); iIndex ++)
        {
            swap(vecNumList[iStartIndex], vecNumList[iIndex]);
            
            permute(vecNumList, iStartIndex + 1, vecResult);
            
            swap(vecNumList[iStartIndex], vecNumList[iIndex]);
        }
    }
    
    void swap(int & iOper1, int & iOper2)
    {
        int iSwap = iOper1; iOper1 = iOper2; iOper2 = iSwap;
    }
};

/*

Normal better backtracking.

*/
