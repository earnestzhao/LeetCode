class Solution
{
public:
        
    int maxIncreaseKeepingSkyline(vector<vector<int>> & grid)
    {
        vector<int> vecRowMax(grid.size(), 0);
        vector<int> vecColMax(grid.size(), 0);

        for (int iIndex = 0; iIndex < grid.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < grid[iIndex].size(); jIndex ++)
            {
                if (grid[iIndex][jIndex] > vecRowMax[iIndex])
                {
                    vecRowMax[iIndex] = grid[iIndex][jIndex];
                }

                if (grid[iIndex][jIndex] > vecColMax[jIndex])
                {
                    vecColMax[jIndex] = grid[iIndex][jIndex];
                }
            }
        }

        int iMaxIncrease = 0;
        for (int iIndex = 0; iIndex < grid.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < grid[iIndex].size(); jIndex ++)
            {
                iMaxIncrease += (vecRowMax[iIndex] < vecColMax[jIndex] ? vecRowMax[iIndex] : vecColMax[jIndex]) - grid[iIndex][jIndex];
            }
        }

        return iMaxIncrease;
    }
};

