class Solution
{
public:

    void gameOfLife(vector<vector<int>> & board)
    {
        for (int iIndex = 0; iIndex < board.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < board[iIndex].size(); jIndex ++)
            {
                int iLiveCellNumber = 0;
                
                if (PositionIndexValid(board, iIndex - 1, jIndex - 1))
                {
                    if ((board[iIndex - 1][jIndex - 1] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if (PositionIndexValid(board, iIndex - 1, jIndex))
                {
                    if ((board[iIndex - 1][jIndex] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if (PositionIndexValid(board, iIndex - 1, jIndex + 1))
                {
                    if ((board[iIndex - 1][jIndex + 1] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if (PositionIndexValid(board, iIndex, jIndex - 1))
                {
                    if ((board[iIndex][jIndex - 1] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if (PositionIndexValid(board, iIndex, jIndex + 1))
                {
                    if ((board[iIndex][jIndex + 1] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if (PositionIndexValid(board, iIndex + 1, jIndex - 1))
                {
                    if ((board[iIndex + 1][jIndex - 1] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if (PositionIndexValid(board, iIndex + 1, jIndex))
                {
                    if ((board[iIndex + 1][jIndex] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if (PositionIndexValid(board, iIndex + 1, jIndex + 1))
                {
                    if ((board[iIndex + 1][jIndex + 1] & 0x1) == 1)
                    {
                        iLiveCellNumber ++;
                    }
                }
                
                if ((board[iIndex][jIndex] & 0x1) == 1)
                {
                    if (iLiveCellNumber == 2 || iLiveCellNumber == 3)
                    {
                        board[iIndex][jIndex] |= 0x2;
                    }
                }
                else
                {
                    if (iLiveCellNumber == 3)
                    {
                        board[iIndex][jIndex] |= 0x2;
                    }
                }
            }
        }
        
        for (int iIndex = 0; iIndex < board.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < board[iIndex].size(); jIndex ++)
            {
                board[iIndex][jIndex] >>= 1;
            }
        }
    }

private:

    bool PositionIndexValid(vector<vector<int>> & board, int rowIndex, int colIndex)
    {
        return rowIndex >= 0 && rowIndex < board.size() && colIndex >= 0 && colIndex < board[rowIndex].size();
    }
};
