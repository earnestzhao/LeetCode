class Solution
{
public:

    string removeDuplicateLetters(string s)
	{
		string strResult = "";
	
		int aiLetterCount[26] = 0;
		
		for (int iIndex = 0; iIndex < s.length(); iIndex ++)
		{
			aiLetterCount[s[iIndex] - 'a'] ++;
		}
		
		for (int iIndex = 0; iIndex < 26; iIndex ++)
		{
			if (aiLetterCount[iIndex] > 0)
			{
				strResult.push_back((char)(iIndex + 'a'));
			}
		}
		
		return strResult;
    }
};
