class Solution
{
public:

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> vecCombination;
        
        vector<vector<int>> vecFinalResult;
        
        if (k > 0 && k <= 9 && n <= 45)
        {
            combinationSumDFS(k, 1, n, vecFinalResult, vecCombination);
        }
        
        return vecFinalResult;
    }
    
private:

    void combinationSumDFS(int iCombNumber, int iStartValue, int iTarget, vector<vector<int>> & vecResult, vector<int> & vecComb)
    {
        if (iStartValue > 9)
        {
            return;
        }
        
        if (vecComb.size() >= iCombNumber)
        {
            return;
        }
        
        vecComb.push_back(iStartValue);
        
        int iTargetLeft = iTarget - iStartValue;
        
        if (iTargetLeft == 0)
        {
            if (vecComb.size() == iCombNumber)
            {
                vecResult.push_back(vecComb);
            }
        }
        else if (iTargetLeft > 0)
        {
            combinationSumDFS(iCombNumber, iStartValue + 1, iTargetLeft, vecResult, vecComb);
        }
        else
        {
            
        }
        
        vecComb.pop_back();
        
        combinationSumDFS(iCombNumber, iStartValue + 1, iTarget, vecResult, vecComb);
    }
};

/*

This one has a same method as LeetCode.039. 

*/
