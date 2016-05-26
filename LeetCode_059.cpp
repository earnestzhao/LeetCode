class Solution
{
public:

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> vecResult(n, vector<int>(n, 0));
        
        if (n <= 0)
        {
            return vecResult;
        }
        
        int iNumber = 1, iSquareEdgeSize = vecResult.size();
        
        for (int iAreaIndex = 0; iAreaIndex < iSquareEdgeSize / 2; iAreaIndex ++)
        {
            for (int jIndex = iAreaIndex; jIndex < iSquareEdgeSize - iAreaIndex - 1; jIndex ++)
            {
                vecResult[iAreaIndex][jIndex] = iNumber ++;
            }
            
            for (int jIndex = iAreaIndex; jIndex < iSquareEdgeSize - iAreaIndex - 1; jIndex ++)
            {
                vecResult[jIndex][iSquareEdgeSize - iAreaIndex - 1] = iNumber ++;
            }
            
            for (int jIndex = iAreaIndex; jIndex < iSquareEdgeSize - iAreaIndex - 1; jIndex ++)
            {
                vecResult[iSquareEdgeSize - iAreaIndex - 1][iSquareEdgeSize - jIndex - 1] = iNumber ++;
            }
            
            for (int jIndex = iAreaIndex; jIndex < iSquareEdgeSize - iAreaIndex - 1; jIndex ++)
            {
                vecResult[iSquareEdgeSize - jIndex - 1][iAreaIndex] = iNumber ++;
            }
        }
        
        if (iSquareEdgeSize % 2)
        {
            vecResult[iSquareEdgeSize / 2][iSquareEdgeSize / 2] = iNumber;
        }
        
        return vecResult;
    }
};

/*

Thinking is right, but not bug free.

Normal method: loop from outside to inside.

*/
