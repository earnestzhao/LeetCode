class Solution
{
public:

    string convert(string s, int numRows)
    {
        if (s.empty())
        {
            return "";
        }
        
        if (numRows == 1)
        {
            return s;
        }
        
        string strResult;
        
        for (int iRowIndex = 0, iNumberInGroup = numRows + numRows - 2; iRowIndex < numRows; iRowIndex ++)
        {
            if (iRowIndex == 0 || iRowIndex == numRows - 1)
            {
                for (int iCharIndex = iRowIndex; iCharIndex < s.length(); iCharIndex += iNumberInGroup)
                {
                    strResult.push_back(s[iCharIndex]);
                }
            }
            else
            {
                for (int iCharIndex = iRowIndex, iBaseIncr = iNumberInGroup - 2 * iRowIndex; iCharIndex < s.length(); iCharIndex += iNumberInGroup)
                {
                    strResult.push_back(s[iCharIndex]);
                    
                    if (iCharIndex + iBaseIncr < s.length())
                    {
                        strResult.push_back(s[iCharIndex + iBaseIncr]);
                    }
                }
            }
        }
        
        return strResult;
    }
};
