class Solution
{
public:

    bool repeatedSubstringPattern(string str)
    {
        if (str.length() <= 1)
        {
            return false;
        }
        
        int iBehindIndex = 0;
        int iFrontIndex  = 1;
        
        while (iFrontIndex < str.length())
        {
            if (str[iBehindIndex] == str[iFrontIndex])
            {
                iBehindIndex ++;
                iFrontIndex  ++;
            }
            else
            {
                if (iBehindIndex == 0)
                {
                    iFrontIndex ++;
                }
                
                iBehindIndex = 0;
                
                if (str.length() - iFrontIndex < iFrontIndex)
                {
                    return false;
                }
            }
        }
        
        return iBehindIndex >= str.length() / 2 && iBehindIndex % (str.length() - iBehindIndex) == 0;
    }
};
