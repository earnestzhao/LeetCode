class Solution
{
public:

    vector<vector<int>> permuteUnique(vector<int> & nums)
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> vecResult;
        
        unordered_set<string> hsetAntiRepeat;
        
        permuteUnique(nums, 0, vecResult, true, hsetAntiRepeat);
        
        return vecResult;
    }
    
private:

    void permuteUnique(vector<int> & vecNumList, int iStartIndex, vector<vector<int>> & vecResult, bool bNew, unordered_set<string> & hsetAntiRepeat)
    {
        if (bNew)
        {
            string strVectorId = vectorId(vecNumList);
            
            if (hsetAntiRepeat.find(strVectorId) == hsetAntiRepeat.end())
            {
                vecResult.push_back(vecNumList);
                hsetAntiRepeat.insert(strVectorId);
            }
        }
        
        for (int iIndex = iStartIndex; iIndex < vecNumList.size(); iIndex ++)
        {
            if (vecNumList[iStartIndex] == vecNumList[iIndex])
            {
                if (iStartIndex == iIndex)
                {
                    permuteUnique(vecNumList, iStartIndex + 1, vecResult, false, hsetAntiRepeat);
                }
            }
            else
            {
                swap(vecNumList[iStartIndex], vecNumList[iIndex]);
                
                permuteUnique(vecNumList, iStartIndex + 1, vecResult, true, hsetAntiRepeat);
                
                swap(vecNumList[iStartIndex], vecNumList[iIndex]);
            }
        }
    }
    
    void swap(int & iOper1, int & iOper2)
    {
        int iSwap = iOper1; iOper1 = iOper2; iOper2 = iSwap;
    }
    
    string vectorId(vector<int> & vecList)
    {
        ostringstream ossResult;
        
        for (int iIndex = 0; iIndex < vecList.size(); iIndex ++)
        {
            ossResult << vecList[iIndex] << ",";
        }
        
        return ossResult.str();
    }
};

/*

Thinking is complex... Sort, Jump Repeat Element and Using Hash to anti repeat...

There must be better solutions!!!

*/
