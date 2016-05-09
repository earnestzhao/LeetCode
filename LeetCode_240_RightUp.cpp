class Solution
{
public:

    bool searchMatrix(vector<vector<int>> & matrix, int target)
    {
        if (matrix.size() <= 0)
        {
            return false;
        }
        
        if (matrix[0].size() <= 0)
        {
            return false;
        }
        
        for (int iRowIndex = 0, iColIndex = matrix[iRowIndex].size() - 1; iRowIndex < matrix.size() && iColIndex >= 0;)
        {
            if (target == matrix[iRowIndex][iColIndex])
            {
                return true;
            }
                
            if (target > matrix[iRowIndex][iColIndex])
            {
                iRowIndex ++;
            }
            else
            {
                iColIndex --;
            }
        }
        
        return false;
    }
};

/*

Not bug free once, because of low comprehension.

The algorithm is smart. Start at Right Up Corner.

If target is bigger than matrix[i][j] which means target is bigger than the biggest element of this row, so it cannot appear in this row, you can see the next row.

If target is smaller than matrix[i][j] which means target is smaller than the smallest element of this column, so it cannot appear in this column.

The smart point is choosing the start point at right up. It can reduce a row or a column in any conditions with only one comparation. 

*/
