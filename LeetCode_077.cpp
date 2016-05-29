class Solution
{
public:

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> vecCombine;
        vector<vector<int>> vecResult;
        combine(n, k, vecResult, vecCombine);
        return vecResult;
    }
    
private:

    void combine(int iNumNumber, int iCombineLength, vector<vector<int>> & vecResult, vector<int> & vecCombine)
    {
        if (vecCombine.size() == iCombineLength)
        {
            vecResult.push_back(vecCombine);
            return;
        }
        
        for (int iIndex = (vecCombine.size() > 0 ? vecCombine[vecCombine.size() - 1] + 1 : 1); iIndex <= iNumNumber; iIndex ++)
        {
            if (vecCombine.size() + iNumNumber - iIndex + 1 >= iCombineLength)
            {
                vecCombine.push_back(iIndex);
                combine(iNumNumber, iCombineLength, vecResult, vecCombine);
                vecCombine.pop_back();
            }
            else
            {
                break;
            }
        }
    }
};

/*

Almost bug free, except some small compile errors.

Normal backtracking. Choose a bigger number than the last element in current combine list.

*/
