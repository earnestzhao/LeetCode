class Solution
{
public:

    int minPathSum(vector<vector<int>> & grid)
    {
        int iRowNumber = grid.size();
        
        if (iRowNumber <= 0)
        {
            return -1;
        }
        
        int iColNumber = grid[0].size();
        
        if (iColNumber <= 0)
        {
            return -1;
        }
        
        vector<vector<int>> vecMinPathSum(iRowNumber, vector<int>(iColNumber, 0));
        vecMinPathSum[iRowNumber - 1][iColNumber - 1] = grid[iRowNumber - 1][iColNumber - 1];
        
        for (int iIndex = iRowNumber - 2; iIndex >= 0; iIndex --)
        {
            vecMinPathSum[iIndex][iColNumber - 1] = grid[iIndex][iColNumber - 1] + vecMinPathSum[iIndex + 1][iColNumber - 1];
        }
        
        for (int jIndex = iColNumber - 2; jIndex >= 0; jIndex --)
        {
            vecMinPathSum[iRowNumber - 1][jIndex] = grid[iRowNumber - 1][jIndex] + vecMinPathSum[iRowNumber - 1][jIndex + 1];
        }
        
        for (int iIndex = iRowNumber - 2; iIndex >= 0; iIndex --)
        {
            for (int jIndex = iColNumber - 2; jIndex >= 0; jIndex --)
            {
                vecMinPathSum[iIndex][jIndex] = grid[iIndex][jIndex] + min(vecMinPathSum[iIndex + 1][jIndex], vecMinPathSum[iIndex][jIndex + 1]);
            }
        }
        
        return vecMinPathSum[0][0];
    }
    
private:

    int min(int iOper1, int iOper2)
    {
        return iOper1 < iOper2 ? iOper1 : iOper2;
    }
};

/*

A little bug occured when result array initialization.

Dynamic Programming.

vecMinPathSum[i][n-1] = grid[i][n-1] + vecMinPathSum[i+1][n-1]

vecMinPathSum[m-1][j] = grid[m-1][j] + vecMinPathSum[m-1][j+1]

vecMinPathSum[i][j] = grid[i][j] + max { vecMinPathSum[i+1][j], vecMinPathSum[i][j+1] }

*/
