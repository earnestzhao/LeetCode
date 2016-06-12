class Solution
{
public:

    void solve(vector<vector<char>> & board)
    {
        if (board.size() <= 0)
        {
            return;
        }
        
        if (board[0].size() <= 0)
        {
            return;
        }
        
        for (int iIndex = 0; iIndex < board.size(); iIndex ++)
        {
            if (board[iIndex][0] == 'O')
            {
                search(board, iIndex, 0);
            }
            
            if (board[iIndex][board[0].size() - 1] == 'O')
            {
                search(board, iIndex, board[0].size() - 1);
            }
        }
        
        for (int iIndex = 0; iIndex < board[0].size(); iIndex ++)
        {
            if (board[0][iIndex] == 'O')
            {
                search(board, 0, iIndex);
            }
            
            if (board[board.size() - 1][iIndex] == 'O')
            {
                search(board, board.size() - 1, iIndex);
            }
        }
        
        for (int iIndex = 0; iIndex < board.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < board[iIndex].size(); jIndex ++)
            {
                board[iIndex][jIndex] = (board[iIndex][jIndex] == 'K' ? 'O' : 'X');
            }
        }
    }
    
private:

    void search(vector<vector<char>> & vecBoard, int iRowIndex, int iColIndex)
    {
        stack<int> stackRow;
        stack<int> stackCol;
        
        stackRow.push(iRowIndex);
        stackCol.push(iColIndex);
        
        while (!stackRow.empty())
        {
            int iCurrRowIndex = stackRow.top(); stackRow.pop();
            int iCurrColIndex = stackCol.top(); stackCol.pop();
            vecBoard[iCurrRowIndex][iCurrColIndex] = 'K';
            
            int aiNextPosition[4][2] =
            {
                { iCurrRowIndex, iCurrColIndex - 1 },
                { iCurrRowIndex, iCurrColIndex + 1 },
                { iCurrRowIndex - 1, iCurrColIndex },
                { iCurrRowIndex + 1, iCurrColIndex }
            };
            
            for (int iPosIndex = 0; iPosIndex < 4; iPosIndex ++)
            {
                if (aiNextPosition[iPosIndex][0] >= 0 && aiNextPosition[iPosIndex][0] < vecBoard.size()
                 && aiNextPosition[iPosIndex][1] >= 0 && aiNextPosition[iPosIndex][1] < vecBoard[0].size()
                 && vecBoard[aiNextPosition[iPosIndex][0]][aiNextPosition[iPosIndex][1]] == 'O')
                {
                    stackRow.push(aiNextPosition[iPosIndex][0]);
                    stackCol.push(aiNextPosition[iPosIndex][1]);
                }
            }
        }
    }
};

/*

Thinking is right, almost bug free, but a 'Runtime Error' happened, because of too many recursion depth.

Normal depth-first search. Search from 'O' element on edge. Using stack to prevent from recursion RE.

Optiminze result: space complexity O(1).

*/
