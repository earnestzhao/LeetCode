class Solution
{
public:

    void rotate(vector<vector<int>> & matrix)
    {
        for (int iAreaIndex = 0; iAreaIndex < matrix.size() / 2; iAreaIndex ++)
        {
            vector<int> vecSwapList;
            
            for (int jIndex = iAreaIndex; jIndex < matrix.size() - iAreaIndex; jIndex ++)
            {
                vecSwapList.push_back(matrix[iAreaIndex][jIndex]);
            }
            
            for (int jIndex = iAreaIndex; jIndex < matrix.size() - iAreaIndex; jIndex ++)
            {
                matrix[iAreaIndex][matrix.size() - jIndex - 1] = matrix[jIndex][iAreaIndex];
            }
            
            for (int jIndex = iAreaIndex; jIndex < matrix.size() - iAreaIndex; jIndex ++)
            {
                matrix[jIndex][iAreaIndex] = matrix[matrix.size() - iAreaIndex - 1][jIndex];
            }
            
            for (int jIndex = iAreaIndex; jIndex < matrix.size() - iAreaIndex; jIndex ++)
            {
                matrix[matrix.size() - iAreaIndex - 1][jIndex] = matrix[matrix.size() - jIndex - 1][matrix.size() - iAreaIndex - 1];
            }
            
            for (int jIndex = iAreaIndex; jIndex < matrix.size() - iAreaIndex; jIndex ++)
            {
                matrix[jIndex][matrix.size() - iAreaIndex - 1] = vecSwapList[jIndex - iAreaIndex];
            }
        }
    }
};

/*

Thinking is right, but not bug free.

1. matrix[i][i...n-i-1] -> vecSwapList

2. matrix[i...n-i-1][i] -> matrix[i][i...n-i-1]

3. matrix[n-i-1][i...n-i-1] -> matrix[i...n-i-1][i]

4. matrix[i...n-i-1][n-i-1] -> matrix[n-i-1][i...n-i-1]

5. vecSwapList -> matrix[i...n-i-1][n-i-1]

6. Outside loop swap complete, then do inner loop swap, until all elements are swaped. Thus, loop i from 0 to n-1.

*/
