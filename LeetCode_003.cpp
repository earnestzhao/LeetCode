class Solution
{
public:

	int lengthOfLongestSubstring(string s)
	{
		set<char> setCurrentSubChar;
		
		int iResultLength = 0, iCurrentLength = 0;
		
		unsigned uiIndex = 0, uiEarlistIndexInSet = 0;
		
		while (uiIndex < s.length())
		{
			if (setCurrentSubChar.find(s[uiIndex]) != setCurrentSubChar.end())
			{
				if (iResultLength < iCurrentLength)
				{
					iResultLength = iCurrentLength;
				}
				
				iCurrentLength --;
				setCurrentSubChar.erase(s[uiEarlistIndexInSet]);
				uiEarlistIndexInSet ++;
			}
			else
			{
				setCurrentSubChar.insert(s[uiIndex]);
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
