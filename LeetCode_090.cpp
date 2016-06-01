class Solution
{
public:

    vector<vector<int>> subsetsWithDup(vector<int> & nums)
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> vecResult;
        subsetsWithDup(nums, 0, vecResult);
        return vecResult;
    }
    
private:

    int subsetsWithDup(const vector<int> & vecNumList, int iStartIndex, vector<vector<int>> & vecResult)
    {
        if (iStartIndex >= vecNumList.size())
        {
            vecResult.push_back(vector<int>());
            return 0;
        }
        
        int iCurrDupNumber = subsetsWithDup(vecNumList, iStartIndex + 1, vecResult);
        int iResultNumber  = vecResult.size();
        
        for (int iIndex = 0; iIndex < iResultNumber; iIndex ++)
        {
            if (iCurrDupNumber == 0 || vecNumList[iStartIndex] != vecNumList[iStartIndex + 1] || (vecResult[iIndex].size() >= iCurrDupNumber && vecNumList[iStartIndex] == vecResult[iIndex][iCurrDupNumber - 1]))
            {
                vector<int> vecSubResult = vector<int>(1, vecNumList[iStartIndex]);
                
                for (int jIndex = 0; jIndex < vecResult[iIndex].size(); jIndex ++)
                {
                    vecSubResult.push_back(vecResult[iIndex][jIndex]);
                }
                
                vecResult.push_back(vecSubResult);
            }
        }
        
        if (iCurrDupNumber == 0 || vecNumList[iStartIndex] != vecNumList[iStartIndex + 1])
        {
            return 1;
        }
        
        return iCurrDupNumber + 1;
    }
};

/*

Thinking is finally right after several test cases wrong...

Normal recursing, but special judgement is needed when previous recursing returns and data collection.

To prevent repeat and no missing, we should add the current element into previous subsets if the subset contains all duplicate element with the current one.

*/
