class Solution
{
public:

    int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid)
    {
        int iRowNumber = obstacleGrid.size();
        
        if (iRowNumber <= 0)
        {
            return 0;
        }
        
        int iColNumber = obstacleGrid[0].size();
        
        if (iColNumber <= 0)
        {
            return 0;
        }
        
        if (obstacleGrid[iRowNumber - 1][iColNumber - 1])
        {
            return 0;
        }
        
        vector<vector<int>> vecResultArray(iRowNumber, vector<int>(iColNumber, 0));
        vecResultArray[iRowNumber - 1][iColNumber - 1] = 1;
        
        for (int iIndex = iRowNumber - 2; iIndex >= 0; iIndex --)
        {
            if (obstacleGrid[iIndex][iColNumber - 1])
            {
                vecResultArray[iIndex][iColNumber - 1] = 0;
            }
            else
            {
                vecResultArray[iIndex][iColNumber - 1] = vecResultArray[iIndex + 1][iColNumber - 1];
            }
        }
        
        for (int iIndex = iColNumber - 2; iIndex >= 0; iIndex --)
        {
            if (obstacleGrid[iRowNumber - 1][iIndex])
            {
                vecResultArray[iRowNumber - 1][iIndex] = 0;
            }
            else
            {
                vecResultArray[iRowNumber - 1][iIndex] = vecResultArray[iRowNumber - 1][iIndex + 1];
            }
        }
        
        for (int iIndex = iRowNumber - 2; iIndex >= 0; iIndex --)
        {
            for (int jIndex = iColNumber - 2; jIndex >= 0; jIndex --)
            {
                if (obstacleGrid[iIndex][jIndex])
                {
                    vecResultArray[iIndex][jIndex] = 0;
                }
                else
                {
                    vecResultArray[iIndex][jIndex] = vecResultArray[iIndex][jIndex + 1] + vecResultArray[iIndex + 1][jIndex];
                }
            }
        }
        
        return vecResultArray[0][0];
    }
};

/*

There is only one bug which occured on obstacle destination.

Dynamic Programming as Leetcode.062, set result[i] = 0 when obstacleGrid[i] is 1.

*/
