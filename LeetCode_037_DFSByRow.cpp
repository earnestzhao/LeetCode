class Solution
{
public:

    void solveSudoku(vector<vector<char>> & board)
    {
        vector<vector<int>> vecFillNumbers(board.size(), vector<int>());
        vector<vector<int>> vecFillIndexes(board.size(), vector<int>());
        
        vector<vector<bool>> vecExistRow(board.size(), vector<bool>(board.size() + 1, false));
        vector<vector<bool>> vecExistCol(board.size(), vector<bool>(board.size() + 1, false));
        
        for (int iIndex = 0; iIndex < board.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < board[iIndex].size(); jIndex ++)
            {
                if (board[iIndex][jIndex] != '.')
                {
                    vecExistRow[iIndex][(int)(board[iIndex][jIndex] - '0')] = true;
                    vecExistCol[jIndex][(int)(board[iIndex][jIndex] - '0')] = true;
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
        
        solveSudoku(board, 0, vecExistRow, vecExistCol, vecFillNumbers, vecFillIndexes);
    }
    
private:

    bool solveSudoku(vector<vector<char>> & vecBoard, int iRowIndex, vector<vector<bool>> & vecExistRow, vector<vector<bool>> & vecExistCol, vector<vector<int>> & vecFillNumbers, vector<vector<int>> & vecFillIndexes)
    {
        if (iRowIndex >= vecBoard.size())
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
                if (!vecExistRow[iRowIndex][vecFillNum[iIndex]] && !vecExistCol[vecFillIndex[iIndex]][vecFillNum[iIndex]])
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
                    vecExistRow[iRowIndex][vecFillNum[iIndex]]            = true;
                    vecExistCol[vecFillIndex[iIndex]][vecFillNum[iIndex]] = true;
                }
                
                if (solveSudoku(vecBoard, iRowIndex + 1, vecExistRow, vecExistCol, vecFillNumbers, vecFillIndexes))
                {
                    return true;
                }
                
                for (int iIndex = 0; iIndex < vecFillIndex.size(); iIndex ++)
                {
                    vecExistRow[iRowIndex][vecFillNum[iIndex]]            = false;
                    vecExistCol[vecFillIndex[iIndex]][vecFillNum[iIndex]] = false;
                }
            }
        }
        while (next_permutation(vecFillNum.begin(), vecFillNum.end()));
        
        return false;
    }
};
