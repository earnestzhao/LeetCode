class Solution
{
public:

    bool repeatedSubstringPattern(string str)
    {
        for (int iIndex = 0; iIndex < str.length() / 2 + 1; iIndex ++)
        {
            if (str.length() % (iIndex + 1) == 0)
            {
                int iCompareStartIndex = iIndex + 1;
                
                if (iCompareStartIndex >= str.length())
                {
                    continue;
                }
                
                for (; iCompareStartIndex < str.length(); iCompareStartIndex += iIndex + 1)
                {
                    int iCompareCurrentIndex = 0;
                    
                    for (; iCompareCurrentIndex <= iIndex; iCompareCurrentIndex ++)
                    {
                        if (str[iCompareCurrentIndex] != str[iCompareStartIndex + iCompareCurrentIndex])
                        {
                            break;
                        }
                    }
                    
                    if (iCompareCurrentIndex <= iIndex)
                    {
                        break;
                    }
                }
                
                if (iCompareStartIndex >= str.length())
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
