class Solution
{
public:

    int countBattleships(vector<vector<char>> & board)
    {
        int iCountResult = 0;
        
        for (int iRowIndex = 0; iRowIndex < board.size(); iRowIndex ++)
        {
            for (int iColIndex = 0; iColIndex < board[iRowIndex].size(); iColIndex ++)
            {
                if (board[iRowIndex][iColIndex] == 'X' && (iRowIndex == 0 || board[iRowIndex - 1][iColIndex] == '.') && (iColIndex == 0 || board[iRowIndex][iColIndex - 1] == '.'))
                {
                    iCountResult ++;
                }
            }
        }
        
        return iCountResult;
    }
};
