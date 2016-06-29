class Solution
{
public:

    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hsetCurrentSubChar;
        
        int iResultLength = 0, iCurrentLength = 0;
        
        unsigned uiIndex = 0, uiEarlistIndexInSet = 0;
        
        while (uiIndex < s.length())
        {
            if (hsetCurrentSubChar.find(s[uiIndex]) != hsetCurrentSubChar.end())
            {
                if (iResultLength < iCurrentLength)
                {
                    iResultLength = iCurrentLength;
                }
                
                iCurrentLength --;
                hsetCurrentSubChar.erase(s[uiEarlistIndexInSet]);
                uiEarlistIndexInSet ++;
            }
            else
            {
                hsetCurrentSubChar.insert(s[uiIndex]);
                iCurrentLength ++;
                uiIndex ++;
                
                if (uiIndex >= s.length() && iResultLength < iCurrentLength)
                {
                    iResultLength = iCurrentLength;
                }
            }
        }
        
        return iResultLength;
    }
};

/*

Two pointers.

1. Front pointer is used for collecting new character and check whether it is already exist.

2. Behind pointer is used for keeping the current longest no repeat substring's start index.

3. 'iCurrentLength' and 'iResultLength' are used for updating result.

*/
