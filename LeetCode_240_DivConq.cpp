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
        
        return searchMatrixInRange(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
    
private:

    bool searchMatrixInRange(const vector<vector<int>> & vecMatrix, int iStartRow, int iStartCol, int iEndRow, int iEndCol, int target)
    {
        if (iEndRow - iStartRow < 0 || iEndCol - iStartCol < 0)
        {
            return false;
        }
        
        if (iEndRow - iStartRow == 0)
        {
            return searchMatrixInSingleLine(vecMatrix, true, iStartRow, iStartCol, iEndCol, target);
        }
        
        if (iEndCol - iStartCol == 0)
        {
            return searchMatrixInSingleLine(vecMatrix, false, iStartCol, iStartRow, iEndRow, target);
        }
        
        int iSearchEndIndex = (iEndRow - iStartRow) < (iEndCol - iStartCol) ? (iEndRow - iStartRow) : (iEndCol - iStartCol);
        int iSearchEndRow   = iStartRow + iSearchEndIndex;
        int iSearchEndCol   = iStartCol + iSearchEndIndex;
        
        int iSearchStartRow = iStartRow;
        int iSearchStartCol = iStartCol;
        
        while (iSearchStartRow <= iSearchEndRow)
        {
            int iMidRow = iSearchStartRow + (iSearchEndRow - iSearchStartRow) / 2;
            int iMidCol = iSearchStartCol + (iSearchEndCol - iSearchStartCol) / 2;
            
            if (target == vecMatrix[iMidRow][iMidCol])
            {
                return true;
            }
            else if (target < vecMatrix[iMidRow][iMidCol])
            {
                iSearchEndRow = iMidRow - 1;
                iSearchEndCol = iMidCol - 1;
            }
            else
            {
                iSearchStartRow = iMidRow + 1;
                iSearchStartCol = iMidCol + 1;
            }
        }
        
        return searchMatrixInRange(vecMatrix, iSearchEndRow + 1, iStartCol,       iEndRow,             iSearchEndCol, target)
            || searchMatrixInRange(vecMatrix, iStartRow,         iSearchStartCol, iSearchStartRow - 1, iEndCol,       target);
    }
    
    bool searchMatrixInSingleLine(const vector<vector<int>> & vecMatrix, bool bRowLine, int iLineIndex, int iStartPos, int iEndPos, int target)
    {
        while (iStartPos <= iEndPos)
        {
            int iMidPos = iStartPos + (iEndPos - iStartPos) / 2;
            
            if ((bRowLine && target == vecMatrix[iLineIndex][iMidPos]) || (!bRowLine && target == vecMatrix[iMidPos][iLineIndex]))
            {
                return true;
            }
            else if ((bRowLine && target < vecMatrix[iLineIndex][iMidPos]) || (!bRowLine && target < vecMatrix[iMidPos][iLineIndex]))
            {
                iEndPos = iMidPos - 1;
            }
            else
            {
                iStartPos = iMidPos + 1;
            }
        }
        
        return false;
    }
};

/*

A right thinking, right logic, but bad compiling... Losing parameter, error variaty name. FUCK!!!

Binary search on Diagonal Elements, if equal element founded, then, return true

else, find L = max (m[i][j] < target) { m[i][j] } and R = min (m[i][j] > target) { m[i][j] }, then,

divide and conquer on left down corner of L and right up corner of R until there is only one line left.

Then, do binary searching on this single line and give out result. Time Complex: O(logn * logn)

Maybe it has a faster way. Think and do it later.

*/
