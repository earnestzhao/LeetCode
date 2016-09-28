class Solution
{
public:

    vector<string> generateParenthesis(int n)
    {
        string strCurrentResult;
        vector<string> vecFinalResult;
        generateParenthesis(vecFinalResult, strCurrentResult, n, 0);
        return vecFinalResult;
    }
    
private:

    void generateParenthesis(vector<string> & vecFinalResult, string & strCurrentResult, int iLeftCount, int iRightCount)
    {
        if (iLeftCount == 0 && iRightCount == 0)
        {
            vecFinalResult.push_back(strCurrentResult);
            return;
        }
        
        if (iRightCount > 0)
        {
            strCurrentResult.push_back(')');
            generateParenthesis(vecFinalResult, strCurrentResult, iLeftCount, iRightCount - 1);
            strCurrentResult.pop_back();
        }
        
        if (iLeftCount > 0)
        {
            strCurrentResult.push_back('(');
            generateParenthesis(vecFinalResult, strCurrentResult, iLeftCount - 1, iRightCount + 1);
            strCurrentResult.pop_back();
        }
    }
};

/*

Normal backtracking. The smart point is the number of left and right parenthesis.

*/
