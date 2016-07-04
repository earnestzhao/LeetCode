class Solution
{
public:

    void solveSudoku(vector<vector<char>> & board)
    {
        vector<int> vecFillRowIndex;
        vector<int> vecFillColIndex;
        
        vector<vector<bool>> vecExistRow(SUDOKU_SIZE, vector<bool>(SUDOKU_SIZE + 1, false));
        vector<vector<bool>> vecExistCol(SUDOKU_SIZE, vector<bool>(SUDOKU_SIZE + 1, false));
        vector<vector<bool>> vecExistCub(SUDOKU_SIZE, vector<bool>(SUDOKU_SIZE + 1, false));
        
        for (int iIndex = 0; iIndex < SUDOKU_SIZE; iIndex ++)
        {
            for (int jIndex = 0; jIndex < SUDOKU_SIZE; jIndex ++)
            {
                if (board[iIndex][jIndex] != '.')
                {
                    int iCurrValue = (int)(board[iIndex][jIndex] - '0');
                    vecExistRow[iIndex][iCurrValue]                   = true;
                    vecExistCol[jIndex][iCurrValue]                   = true;
                    vecExistCub[cubIndex(iIndex, jIndex)][iCurrValue] = true;
                }
                else
                {
                    vecFillRowIndex.push_back(iIndex);
                    vecFillColIndex.push_back(jIndex);
                }
            }
        }
        
        solveSudoku(board, vecFillRowIndex, vecFillColIndex, 0, vecExistRow, vecExistCol, vecExistCub);
    }
    
private:

    bool solveSudoku(vector<vector<char>> & vecBoard, vector<int> & vecFillRowIndex, vector<int> & vecFillColIndex, int iCurrentFill, vector<vector<bool>> & vecExistRow, vector<vector<bool>> & vecExistCol, vector<vector<bool>> & vecExistCub)
    {
        if (iCurrentFill >= vecFillRowIndex.size())
        {
            return true;
        }
        
        int iCurrentFillRowIndex = vecFillRowIndex[iCurrentFill];
        int iCurrentFillColIndex = vecFillColIndex[iCurrentFill];
        int iCurrentFillCubIndex = cubIndex(iCurrentFillRowIndex, iCurrentFillColIndex);
        
        for (char cFill = '1'; cFill <= '9'; cFill ++)
        {
            int iValueExistIndex = (int)(cFill - '0');
            
            if (!vecExistRow[iCurrentFillRowIndex][iValueExistIndex]
             && !vecExistCol[iCurrentFillColIndex][iValueExistIndex]
             && !vecExistCub[iCurrentFillCubIndex][iValueExistIndex])
            {
                vecBoard[iCurrentFillRowIndex][iCurrentFillColIndex] = cFill;
                vecExistRow[iCurrentFillRowIndex][iValueExistIndex]  = true;
                vecExistCol[iCurrentFillColIndex][iValueExistIndex]  = true;
                vecExistCub[iCurrentFillCubIndex][iValueExistIndex]  = true;
                
                if (solveSudoku(vecBoard, vecFillRowIndex, vecFillColIndex, iCurrentFill + 1, vecExistRow, vecExistCol, vecExistCub))
                {
                    return true;
                }
                
                vecExistCub[iCurrentFillCubIndex][iValueExistIndex]  = false;
                vecExistCol[iCurrentFillColIndex][iValueExistIndex]  = false;
                vecExistRow[iCurrentFillRowIndex][iValueExistIndex]  = false;
                vecBoard[iCurrentFillRowIndex][iCurrentFillColIndex] = '.';
            }
        }
        
        return false;
    }
    
    int cubIndex(int iRowIndex, int iColIndex)
    {
        return (iRowIndex / CUBE_SIZE) * CUBE_SIZE + iColIndex / CUBE_SIZE;
    }
    
private:

    enum { SUDOKU_SIZE = 9, CUBE_SIZE = 3 };
};

/*

Normal depth-first search.

Using hash table to reduce runtime.

*/
