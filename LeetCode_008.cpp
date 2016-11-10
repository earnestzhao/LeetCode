class Solution
{
public:

    int myAtoi(string str)
    {
        if (str.empty())
        {
            return 0;
        }
        
        int iStartIndex  = 0;
        int iEndIndex    = str.length() - 1;
        
        for (; iStartIndex < str.length(); iStartIndex ++)
        {
            if (str[iStartIndex] != ' ')
            {
                break;
            }
        }
        
        for (; iEndIndex >= 0; iEndIndex --)
        {
            if (str[iEndIndex] != ' ')
            {
                break;
            }
        }
        
        if (iEndIndex < iStartIndex)
        {
            return 0;
        }
        
        int iIndex = iStartIndex;
        
        if (str[iStartIndex] == '-' || str[iStartIndex] == '+')
        {
            iIndex = iStartIndex + 1;
        }
        
        bool bNegative = false;
        
        if (str[iStartIndex] == '-')
        {
            bNegative = true;
        }
        
        int iResultValue = 0;
        
        for (; iIndex <= iEndIndex; iIndex ++)
        {
            if (str[iIndex] < '0' || str[iIndex] > '9')
            {
                break;
            }
            
            int iCurrValue = str[iIndex] - '0';
            
            if (bNegative)
            {
                if (iResultValue < (INT_MIN + iCurrValue) / 10)
                {
                    return INT_MIN;
                }
                
                iResultValue = iResultValue * 10 - iCurrValue;
            }
            else
            {
                if (iResultValue > (INT_MAX - iCurrValue) / 10)
                {
                    return INT_MAX;
                }
                
                iResultValue = iResultValue * 10 + iCurrValue;
            }
        }
        
        return iResultValue;
    }
};

/*

Although taking care, I miss a lot of edge conditions.

1. The first '+' character.

2. Spaces ...

3. Fuck strange: return value before invalid character ...

4. Fuck strange: return MAX when overflow ...




The edge conditions which I wasn't miss:

1. The first '-' character.

2. Overflow judgement and processing ...

*/
