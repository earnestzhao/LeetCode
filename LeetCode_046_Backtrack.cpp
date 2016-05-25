class Solution
{
public:

    vector<vector<int>> permute(vector<int> & nums)
    {
        vector<vector<int>> vecResult;
        
        permute(nums, 0, vecResult, true);
        
        return vecResult;
    }
    
private:

    void permute(vector<int> & vecNumList, int iStartIndex, vector<vector<int>> & vecResult, bool bNew)
    {
        if (bNew)
        {
            vecResult.push_back(vecNumList);
        }
        
        for (int iIndex = iStartIndex; iIndex < vecNumList.size(); iIndex ++)
        {
            if (iStartIndex == iIndex)
            {
                permute(vecNumList, iStartIndex + 1, vecResult, false);
            }
            else
            {
                swap(vecNumList[iStartIndex], vecNumList[iIndex]);
                
                permute(vecNumList, iStartIndex + 1, vecResult, true);
                
                swap(vecNumList[iStartIndex], vecNumList[iIndex]);
            }
        }
    }
    
    void swap(int & iOper1, int & iOper2)
    {
        int iSwap = iOper1; iOper1 = iOper2; iOper2 = iSwap;
    }
};

/*

Shit!!! Still not familar with backtracking!!!

Normal backtracking.

*/
