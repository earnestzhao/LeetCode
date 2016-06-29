class Solution
{
public:

    int lengthOfLongestSubstring(string s)
    {
        int iResultLength = 0, iCurrentLength = 0;
        
        int iIndex = 0, iEarlistIndexInSet = 0;
        
        int aiCharEarlistIndex[256];
        
        memset((char *)aiCharEarlistIndex, -1, sizeof(aiCharEarlistIndex));
        
        while (iIndex < s.length())
        {
            if (aiCharEarlistIndex[s[iIndex]] >= 0)
            {
                if (iResultLength < iCurrentLength)
                {
                    iResultLength = iCurrentLength;
                }
                
                iCurrentLength --;
                aiCharEarlistIndex[s[iEarlistIndexInSet]] = -1;
                iEarlistIndexInSet ++;
            }
            else
            {
                aiCharEarlistIndex[s[iIndex]] = iIndex;
                iCurrentLength ++;
                iIndex ++;
            }
        }
        
        if (iResultLength < iCurrentLength)
        {
            iResultLength = iCurrentLength;
        }
        
        return iResultLength;
    }
};

/*

Two pointers.

1. Front pointer is used for collecting new character and check whether it is already exist.

2. Behind pointer is used for keeping the current longest no repeat substring's start index.

3. 'iCurrentLength' and 'iResultLength' are used for updating result.

----------------------------------------

Optimization:

Change unordered_map to a whole character set indexed array.

*/
