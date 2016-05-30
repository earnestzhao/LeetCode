class Solution
{
public:

    int numDecodings(string s)
    {
        vector<int> vecResult;
        vecResult.push_back(1);
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            int iCurrentResult = 0;
            
            if ((int)(s[iIndex] - '0') > 0)
            {
                iCurrentResult += vecResult[iIndex];
            }
            
            if (iIndex > 0)
            {
                int iTailTwoNumberValue = (s[iIndex - 1] - '0') * 10 + (s[iIndex] - '0');
                
                if (iTailTwoNumberValue >= 10 && iTailTwoNumberValue <= 26)
                {
                    iCurrentResult += vecResult[iIndex - 1];
                }
            }
            
            vecResult.push_back(iCurrentResult);
        }
        
        vecResult[0] = 0;
        return vecResult[s.length()];
    }
};

/*

Thinking is right, but small bugs exist. I did not think about 0, but 0 is valid in 10 and 20.

Dynamic Programming.

vecResult[i] = (s[i] > 0 ? vecResult[i-1] : 0) + (10 <= s[i-1]s[i] <= 26 ? vecResult[i-2] : 0);

*/
