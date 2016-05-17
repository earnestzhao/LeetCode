class Solution
{
public:

    Solution()
    {
        m_avecDigitLetter[0].push_back('a');
        m_avecDigitLetter[0].push_back('b');
        m_avecDigitLetter[0].push_back('c');
        
        m_avecDigitLetter[1].push_back('d');
        m_avecDigitLetter[1].push_back('e');
        m_avecDigitLetter[1].push_back('f');
        
        m_avecDigitLetter[2].push_back('g');
        m_avecDigitLetter[2].push_back('h');
        m_avecDigitLetter[2].push_back('i');
        
        m_avecDigitLetter[3].push_back('j');
        m_avecDigitLetter[3].push_back('k');
        m_avecDigitLetter[3].push_back('l');
        
        m_avecDigitLetter[4].push_back('m');
        m_avecDigitLetter[4].push_back('n');
        m_avecDigitLetter[4].push_back('o');
        
        m_avecDigitLetter[5].push_back('p');
        m_avecDigitLetter[5].push_back('q');
        m_avecDigitLetter[5].push_back('r');
        m_avecDigitLetter[5].push_back('s');
        
        m_avecDigitLetter[6].push_back('t');
        m_avecDigitLetter[6].push_back('u');
        m_avecDigitLetter[6].push_back('v');
        
        m_avecDigitLetter[7].push_back('w');
        m_avecDigitLetter[7].push_back('x');
        m_avecDigitLetter[7].push_back('y');
        m_avecDigitLetter[7].push_back('z');
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> vecFinalResult;
        
        letterCombinations(digits, 0, vecFinalResult);
        
        return vecFinalResult;
    }
    
private:

    void letterCombinations(const string & strDigits, int iStartIndex, vector<string> & vecResult)
    {
        if (iStartIndex >= strDigits.size())
        {
            return;
        }
        
        vector<char> & vecDstDigitList = m_avecDigitLetter[(int)(strDigits[iStartIndex] - '2')];
        
        if (iStartIndex == strDigits.size() - 1)
        {
            for (int iIndex = 0; iIndex < vecDstDigitList.size(); iIndex ++)
            {
                vecResult.push_back(string(1, vecDstDigitList[iIndex]));
            }
            
            return;
        }
        
        letterCombinations(strDigits, iStartIndex + 1, vecResult);
        
        int iResultRawSize = vecResult.size();
        
        for (int iIndex = 1; iIndex < vecDstDigitList.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < iResultRawSize; jIndex ++)
            {
                vecResult.push_back(string(1, vecDstDigitList[iIndex]).append(vecResult[jIndex]));
            }
        }
        
        for (int iIndex = 0; iIndex < iResultRawSize; iIndex ++)
        {
            vecResult[iIndex] = string(1, vecDstDigitList[0]).append(vecResult[iIndex]);
        }
    }
    
private:

    vector<char> m_avecDigitLetter[8];
};

/*

Thinking is right and simple, but 2 low compile errors...

Hold a list of letters of digit, and recursive on the left string.

Finally, combine them together.

*/
