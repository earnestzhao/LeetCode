class Solution
{
public:

    void solveSudoku(vector<vector<char>> & board)
    {
        vector<vector<int>> vecFillNumbers(SUDOKU_SIZE, vector<int>());
        vector<vector<int>> vecFillIndexes(SUDOKU_SIZE, vector<int>());
        
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
                    vecFillIndexes[iIndex].push_back(jIndex);
                }
            }
        }
        
        for (int iIndex = 0; iIndex < vecExistRow.size(); iIndex ++)
        {
            for (int jIndex = 1; jIndex < vecExistRow[iIndex].size(); jIndex ++)
            {
                if (!vecExistRow[iIndex][jIndex])
                {
                    vecFillNumbers[iIndex].push_back(jIndex);
                }
            }
        }
        
        solveSudoku(board, 0, vecExistRow, vecExistCol, vecExistCub, vecFillNumbers, vecFillIndexes);
    }
    
private:

    bool solveSudoku(vector<vector<char>> & vecBoard, int iRowIndex, vector<vector<bool>> & vecExistRow, vector<vector<bool>> & vecExistCol, vector<vector<bool>> & vecExistCub, vector<vector<int>> & vecFillNumbers, vector<vector<int>> & vecFillIndexes)
    {
        if (iRowIndex >= SUDOKU_SIZE)
        {
            return true;
        }
        
        vector<int> & vecFillNum   = vecFillNumbers[iRowIndex];
        vector<int> & vecFillIndex = vecFillIndexes[iRowIndex];
        
        do
        {
            bool bCanFillAll = true;
            
            for (int iIndex = 0; iIndex < vecFillIndex.size(); iIndex ++)
            {
                if (!vecExistRow[iRowIndex][vecFillNum[iIndex]] && !vecExistCol[vecFillIndex[iIndex]][vecFillNum[iIndex]] && !vecExistCub[cubIndex(iRowIndex, vecFillIndex[iIndex])][vecFillNum[iIndex]])
                {
                    vecBoard[iRowIndex][vecFillIndex[iIndex]] = (char)('0' + vecFillNum[iIndex]);
                }
                else
                {
                    bCanFillAll = false;
                    break;
                }
            }
            
            if (bCanFillAll)
            {
                for (int iIndex = 0; iIndex < vecFillIndex.size(); iIndex ++)
                {
                    vecExistRow[iRowIndex][vecFillNum[iIndex]]                                 = true;
                    vecExistCol[vecFillIndex[iIndex]][vecFillNum[iIndex]]                      = true;
                    vecExistCub[cubIndex(iRowIndex, vecFillIndex[iIndex])][vecFillNum[iIndex]] = true;
                }
                
                if (solveSudoku(vecBoard, iRowIndex + 1, vecExistRow, vecExistCol, vecExistCub, vecFillNumbers, vecFillIndexes))
                {
                    return true;
                }
                
                for (int iIndex = 0; iIndex < vecFillIndex.size(); iIndex ++)
                {
                    vecExistRow[iRowIndex][vecFillNum[iIndex]]                                 = false;
                    vecExistCol[vecFillIndex[iIndex]][vecFillNum[iIndex]]                      = false;
                    vecExistCub[cubIndex(iRowIndex, vecFillIndex[iIndex])][vecFillNum[iIndex]] = false;
                }
            }
        }
        while (next_permutation(vecFillNum.begin(), vecFillNum.end()));
        
        return false;
    }
    
    int cubIndex(int iRowIndex, int iColIndex)
    {
        return (iRowIndex / CUBE_SIZE) * CUBE_SIZE + iColIndex / CUBE_SIZE;
    }
    
private:

    enum { SUDOKU_SIZE = 9, CUBE_SIZE = 3 };
};
