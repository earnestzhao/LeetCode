class NumMatrix
{
public:

    NumMatrix(vector<vector<int>> & matrix)
    {
        for (int iIndex = 0; iIndex < matrix.size(); iIndex ++)
        {
            m_vecMatrixSum.push_back(vector<int>());
            
            for (int jIndex = 0; jIndex < matrix[iIndex].size(); jIndex ++)
            {
                if (jIndex == 0)
                {
                    m_vecMatrixSum[iIndex].push_back(matrix[iIndex][jIndex]);
                }
                else
                {
                    m_vecMatrixSum[iIndex].push_back(matrix[iIndex][jIndex] + m_vecMatrixSum[iIndex][jIndex - 1]);
                }
            }
        }
        
        for (int iIndex = 1; iIndex < m_vecMatrixSum.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < m_vecMatrixSum[iIndex].size(); jIndex ++)
            {
                m_vecMatrixSum[iIndex][jIndex] += m_vecMatrixSum[iIndex - 1][jIndex];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return getSumValue(row2, col2) - getSumValue(row1 - 1, col2) - getSumValue(row2, col1 - 1) + getSumValue(row1 - 1, col1 - 1);
    }
    
private:

    vector<vector<int>> m_vecMatrixSum;
    
    int getSumValue(int iRowIndex, int iColIndex)
    {
        if (iRowIndex < 0 || iColIndex < 0)
        {
            return 0;
        }
        
        return m_vecMatrixSum[iRowIndex][iColIndex];
    }
};

/*

看到这个题目就又想起线段树了，没好好想就看了 Tag，该打啊！

不过知道是动态规划以后，思路倒是挺清晰的，就是每个存储格里取从 (0,0) 到当前格子的所有元素和，这样任何一个矩阵块的和都可以通过简单加减得出。

sumRange(row1, col1, row2, col2) = storeSum[row2][col2] - storeSum[row1 - 1][col2] - storeSum[row2][col1 - 1] + store[row1 - 1][col1 - 1];

这次边界条件注意得挺好的，但是初始化的时候内外循环变量位置搞错了，该打该打该打！

*/
