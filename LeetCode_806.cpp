class Solution
{
public:

    vector<int> numberOfLines(vector<int> & widths, string S)
    {
        int iLineLength = 0;
        int iLineNumber = 1;
        
        for (int iIndex = 0; iIndex < S.size(); iIndex ++)
        {
            if (iLineLength + widths[S[iIndex] - 'a'] > 100)
            {
                iLineLength = widths[S[iIndex] - 'a'];
                iLineNumber ++;
            }
            else
            {
                iLineLength += widths[S[iIndex] - 'a'];
            }
        }

        vector<int> vecResult;
        vecResult.push_back(iLineNumber);
        vecResult.push_back(iLineLength);
        return vecResult;
    }
};

