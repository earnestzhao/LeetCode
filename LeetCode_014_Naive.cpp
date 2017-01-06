class Solution
{
public:

    string longestCommonPrefix(vector<string> & strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        
        if (strs.size() == 1)
        {
            return strs[0];
        }
        
        int iResultLength = strs[0].length();
        
        for (int iStrIndex = 1; iStrIndex < strs.size(); iStrIndex ++)
        {
            if (iResultLength > strs[iStrIndex].length())
            {
                iResultLength = strs[iStrIndex].length();
            }
            
            for (int iCharIndex = 0; iCharIndex < iResultLength; iCharIndex ++)
            {
                if (strs[iStrIndex][iCharIndex] != strs[0][iCharIndex])
                {
                    iResultLength = iCharIndex;
                    break;
                }
            }
        }
        
        return strs[0].substr(0, iResultLength);
    }
};
