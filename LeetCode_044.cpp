class Solution
{
public:

    bool isMatch(string s, string p)
    {
        int iSrcIndex     = 0;
        int iPatternIndex = 0;
        
        int iStarIndex    = -1;
        int iSrcStarIndex = -1;
        
        while (iSrcIndex < s.length())
        {
            if (iPatternIndex < p.length() && (p[iPatternIndex] == '?' || s[iSrcIndex] == p[iPatternIndex]))
            {
                iSrcIndex     ++;
                iPatternIndex ++;
            }
            else if (iPatternIndex < p.length() && p[iPatternIndex] == '*')
            {
                iStarIndex    = iPatternIndex ++;
                iSrcStarIndex = iSrcIndex;
            }
            else if (iStarIndex >= 0)
            {
                iPatternIndex = iStarIndex + 1;
                iSrcIndex     = ++ iSrcStarIndex;
            }
            else
            {
                return false;
            }
        }
        
        while (iPatternIndex < p.length() && p[iPatternIndex] == '*')
        {
            iPatternIndex ++;
        }
        
        return iPatternIndex >= p.length();
    }
};

/*

Backtracking without recursion.

*/
