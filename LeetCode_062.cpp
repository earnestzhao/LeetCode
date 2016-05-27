class Solution
{
public:

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> vecResultArray(m, vector<int>(n, 0));
        
        for (int iIndex = 0; iIndex < m; iIndex ++)
        {
            vecResultArray[iIndex][n - 1] = 1;
        }
        
        for (int iIndex = 0; iIndex < n; iIndex ++)
        {
            vecResultArray[m - 1][iIndex] = 1;
        }
        
        for (int iIndex = m - 2; iIndex >= 0; iIndex --)
        {
            for (int jIndex = n - 2; jIndex >= 0; jIndex --)
            {
                vecResultArray[iIndex][jIndex] = vecResultArray[iIndex + 1][jIndex] + vecResultArray[iIndex][jIndex + 1];
            }
        }
        
        return vecResultArray[0][0];
    }
};

/*

Bug free once.

Normal dynamic programming.

result[m-1][j] = 1, result[i][n-1] = 1

result[i][j] = result[i+1][j] + result[i][j+1]

*/
