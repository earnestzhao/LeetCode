class Solution
{
public:

    int longestValidParentheses(string s)
    {
        int iFinalResult = 0;
        
        stack<int> stackLeftParentheseIndex;
        
        for (int iIndex = 0, iRangeStartIndex = -1; iIndex < s.length(); iIndex ++)
        {
            if (s[iIndex] == '(')
            {
                stackLeftParentheseIndex.push(iIndex);
            }
            else
            {
                if (stackLeftParentheseIndex.empty())
                {
                    iRangeStartIndex = iIndex;
                }
                else
                {
                    stackLeftParentheseIndex.pop();
                    
                    int iCurrLength = 0;
                    
                    if (stackLeftParentheseIndex.empty())
                    {
                        iCurrLength = iIndex - iRangeStartIndex;
                    }
                    else
                    {
                        iCurrLength = iIndex - stackLeftParentheseIndex.top();
                    }
                    
                    if (iCurrLength > iFinalResult)
                    {
                        iFinalResult = iCurrLength;
                    }
                }
            }
        }
        
        return iFinalResult;
    }
};

/*

Thinking is right, but a bug at first at zero index.

Normal algorithm. Using stack to judge valid, and 'iRangeStartIndex' to identify valid range start index after invalid right parenthese.

*/
