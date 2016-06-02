class Solution
{
public:

    bool exist(vector<vector<char>> & board, string word)
    {
        if (word.length() <= 0)
        {
            return false;
        }
        
        if (board.size() <= 0)
        {
            return false;
        }
        
        if (board[0].size() <= 0)
        {
            return false;
        }
        
        for (int iIndex = 0; iIndex < board.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < board[iIndex].size(); jIndex ++)
            {
                if (exist(board, iIndex, jIndex, word, 0))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:

    bool exist(vector<vector<char>> & vecBoard, int iRowIndex, int iColIndex, const string & strDstWord, int iWordCharIndex)
    {
        if (iWordCharIndex >= strDstWord.size())
        {
            return true;
        }
        
        if (iRowIndex < 0 || iRowIndex >= vecBoard.size() || iColIndex < 0 || iColIndex >= vecBoard[0].size())
        {
            return false;
        }
        
        if (vecBoard[iRowIndex][iColIndex] != strDstWord[iWordCharIndex])
        {
            return false;
        }
        
        vecBoard[iRowIndex][iColIndex] = 0;
        
        if (exist(vecBoard, iRowIndex - 1, iColIndex, strDstWord, iWordCharIndex + 1))
        {
            return true;
        }
        
        if (exist(vecBoard, iRowIndex, iColIndex - 1, strDstWord, iWordCharIndex + 1))
        {
            return true;
        }
        
        if (exist(vecBoard, iRowIndex + 1, iColIndex, strDstWord, iWordCharIndex + 1))
        {
            return true;
        }
        
        if (exist(vecBoard, iRowIndex, iColIndex + 1, strDstWord, iWordCharIndex + 1))
        {
            return true;
        }
        
        vecBoard[iRowIndex][iColIndex] = strDstWord[iWordCharIndex];
        return false;
    }
};

/*

I should think about it simply when I did it first time...

*/
