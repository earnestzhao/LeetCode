class Solution
{
public:

    string longestPalindrome(string s)
    {
        vector<char> vecAddHelpList;
        vecAddHelpList.push_back('#');
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            vecAddHelpList.push_back(s[iIndex]);
            vecAddHelpList.push_back('#');
        }
        
        vector<int> vecResultList;
        vecResultList.push_back(1);
        
        for (int iIndex = 1, iCenterId = 0, iMaxId = 1; iIndex < vecAddHelpList.size(); iIndex ++)
        {
            if (iCenterId + iCenterId - iIndex >= 0 && iMaxId - iIndex > 0)
            {
                vecResultList.push_back(vecResultList[iCenterId + iCenterId - iIndex] < iMaxId - iIndex ? vecResultList[iCenterId + iCenterId - iIndex] : iMaxId - iIndex);
            }
            else
            {
                vecResultList.push_back(1);
            }
            
            while (iIndex - vecResultList[vecResultList.size() - 1] >= 0 && iIndex + vecResultList[vecResultList.size() - 1] < vecAddHelpList.size() && vecAddHelpList[iIndex - vecResultList[vecResultList.size() - 1]] == vecAddHelpList[iIndex + vecResultList[vecResultList.size() - 1]])
            {
                vecResultList[vecResultList.size() - 1] ++;
            }
            
            if (iIndex + vecResultList[vecResultList.size() - 1] > iMaxId)
            {
                iCenterId = iIndex;
                iMaxId = iIndex + vecResultList[vecResultList.size() - 1];
            }
        }
        
        int iFinalResultIndex = 0;
        
        for (int iIndex = 1; iIndex < vecResultList.size(); iIndex ++)
        {
            if (vecResultList[iIndex] > vecResultList[iFinalResultIndex])
            {
                iFinalResultIndex = iIndex;
            }
        }
        
        return s.substr((iFinalResultIndex - vecResultList[iFinalResultIndex] + 1) / 2, vecResultList[iFinalResultIndex] - 1);
    }
};

/*

Algorithm Manacher.

1. Add '#' to each space between adjacent characters, including before head and after tail. After that, the new string can be defined as 'ExtString'.

2. Define 'PalindromeRadius[i]' as the half length + 1 of palindrome whose center is ExtString[i].

3. PalindromeRadius[i] >= min(PalindromeRadius[2 * id - i], maxId - i), where 'maxId' is the end of the current fastest palindrome and 'id' is the center of it.

*/
