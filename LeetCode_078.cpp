class Solution
{
public:

    vector<vector<int>> subsets(vector<int> & nums)
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> vecResult;
        subsets(nums, 0, vecResult);
        return vecResult;
    }
    
private:
    
    void subsets(vector<int> & vecNumList, int iStartIndex, vector<vector<int>> & vecResult)
    {
        if (iStartIndex >= vecNumList.size())
        {
            vecResult.push_back(vector<int>());
            return;
        }
        
        subsets(vecNumList, iStartIndex + 1, vecResult);
        
        int iPrevResultNumber = vecResult.size();
        
        for (int iIndex = 0; iIndex < iPrevResultNumber; iIndex ++)
        {
            vecResult.push_back(vector<int>(1, vecNumList[iStartIndex]));
            
            for (int jIndex = 0; jIndex < vecResult[iIndex].size(); jIndex ++)
            {
                vecResult[vecResult.size() - 1].push_back(vecResult[iIndex][jIndex]);
            }
        }
    }
};

/*

Almost bug free, but a big bug on recursion exit.

Normal recursion. result(i) = i UNION { result(i-1) }; result(n + 1) = { }

*/
