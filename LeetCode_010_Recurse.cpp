class Solution
{
public:

    bool isMatch(string s, string p)
    {
        return isMatch(s, 0, p, 0);
    }

private:

    bool isMatch(const string & strSrc, int iSrcStartIndex, const string & strPattern, int iPatternStartIndex)
    {
        if (iSrcStartIndex >= strSrc.size() && iPatternStartIndex >= strPattern.size())
        {
            return true;
        }
        
        if (iPatternStartIndex + 1 < strPattern.size() && strPattern[iPatternStartIndex + 1] == '*')
        {
            if (iSrcStartIndex < strSrc.size() && (strSrc[iSrcStartIndex] == strPattern[iPatternStartIndex] || strPattern[iPatternStartIndex] == '.'))
            {
                return isMatch(strSrc, iSrcStartIndex + 1, strPattern, iPatternStartIndex)
                    || isMatch(strSrc, iSrcStartIndex, strPattern, iPatternStartIndex + 2);
            }
            else
            {
                return isMatch(strSrc, iSrcStartIndex, strPattern, iPatternStartIndex + 2);
            }
        }
        else
        {
            if (iSrcStartIndex < strSrc.size() && (strSrc[iSrcStartIndex] == strPattern[iPatternStartIndex] || strPattern[iPatternStartIndex] == '.'))
            {
                return isMatch(strSrc, iSrcStartIndex + 1, strPattern, iPatternStartIndex + 1);
            }
        }
        
        return false;
    }
};

/*

Thinking is right, but a lot of corner condition bugs.

Normal recursion. The method should choose whether using current character for matching or not when meet '*' in pattern.

*/
