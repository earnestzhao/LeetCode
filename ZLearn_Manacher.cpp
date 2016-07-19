
const char C_UNIT_SEPARATOR = '\x1F';

int Min(int iOper1, int iOper2)
{
    return iOper1 < iOper2 ? iOper1 : iOper2;
}

vector<string> Manacher(const string & strSrc)
{
    string strExtend;
    strExtend.push_back(C_UNIT_SEPARATOR);
    
    for (int iIndex = 0; iIndex < strSrc.size(); iIndex ++)
    {
        strExtend.push_back(strSrc[iIndex]);
        strExtend.push_back(C_UNIT_SEPARATOR);
    }
    
    vector<int> vecPalindromicRadius;
    
    for (int iIndex = 0, iMaxPalindromeCenterIndex = 0, iMaxPalindromeEndIndex = 0; iIndex < strExtend.size(); iIndex ++)
    {
        if (iIndex < iMaxPalindromeEndIndex)
        {
            vecPalindromicRadius.push_back(Min(vecPalindromicRadius[2 * iMaxPalindromeCenterIndex - iIndex], iMaxPalindromeEndIndex - iIndex + 1));
        }
        else
        {
            vecPalindromicRadius.push_back(1);
        }
        
        for (int iLeftIndex = iIndex - vecPalindromicRadius[iIndex], iRightIndex = iIndex + vecPalindromicRadius[iIndex]; iLeftIndex >= 0 && iRightIndex < strExtend.size() && strExtend[iLeftIndex] == strExtend[iRightIndex]; iLeftIndex --, iRightIndex ++)
        {
            vecPalindromicRadius[iIndex] ++;
        }
        
        int iCurrentPalindromeEndIndex = iIndex + vecPalindromicRadius[iIndex] - 1;
        
        if (iCurrentPalindromeEndIndex > iMaxPalindromeEndIndex)
        {
            iMaxPalindromeEndIndex    = iCurrentPalindromeEndIndex;
            iMaxPalindromeCenterIndex = iIndex;
        }
    }
    
    vector<string> vecResult;
    
    for (int iIndex = 1; iIndex < vecPalindromicRadius.size() - 1; iIndex ++)
    {
        vecResult.push_back(strSrc.substr((iIndex - vecPalindromicRadius[iIndex] + 2) / 2, vecPalindromicRadius[iIndex] - 1));
    }
    
    return vecResult;
}
