class Solution
{
public:

    vector<vector<int>> permuteUnique(vector<int> & nums)
    {
        vector<vector<int>> vecResult;
        
        vector<int> vecSubResult;
        
        vector<bool> vecAccessed(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        
        permuteUnique(nums, vecSubResult, vecResult, vecAccessed);
        
        return vecResult;
    }
    
private:

    void permuteUnique(vector<int> & vecNumList, vector<int> & vecSubResult, vector<vector<int>> & vecResult, vector<bool> & vecAccessed)
    {
        if (vecSubResult.size() == vecNumList.size())
        {
            vecResult.push_back(vecSubResult);
            return;
        }
        
        for (int iIndex = 0; iIndex < vecNumList.size(); iIndex ++)
        {
            if (!vecAccessed[iIndex])
            {
                vecAccessed[iIndex] = true;
                
                vecSubResult.push_back(vecNumList[iIndex]);
                
                permuteUnique(vecNumList, vecSubResult, vecResult, vecAccessed);
                
                vecSubResult.pop_back();
                
                vecAccessed[iIndex] = false;
                
                while (iIndex < vecNumList.size() - 1 && vecNumList[iIndex] == vecNumList[iIndex + 1])
                {
                    iIndex ++;
                }
            }
        }
    }
};

/*

Still not very familar with backtracking... but a good practice.

1. Sort once, and do not change raw list.

2. Choose one, and using whole raw list in next recursion.

3. Choose a different element in next time of loop to anti repeat.

*/
