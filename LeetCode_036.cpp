class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<unsigned> vecRowValid(9, 0);
        vector<unsigned> vecColValid(9, 0);
        vector<unsigned> vecBlkValid(9, 0);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                unsigned uiCurrentMask = (1 << (board[i][j] - '0'));
                unsigned uiRowIndex    = i;
                unsigned uiColIndex    = j;
                unsigned uiBlkIndex    = (i / 3) * 3 + j / 3;

                if ((vecRowValid[uiRowIndex] & uiCurrentMask) || (vecColValid[uiColIndex] & uiCurrentMask) || (vecBlkValid[uiBlkIndex] & uiCurrentMask))
                {
                    return false;
                }

                vecRowValid[uiRowIndex] |= uiCurrentMask;
                vecColValid[uiColIndex] |= uiCurrentMask;
                vecBlkValid[uiBlkIndex] |= uiCurrentMask;
            }
        }

        return true;
    }
};

/*
 * 1. Compile Error
 *
 * 2. Forget to initialize assistant array
 *
 * 3. Bug free but low mistakes
 *
 * 4. Complex: O(n^2)
 */

