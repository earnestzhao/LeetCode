class Solution
{
public:
    
    vector<string> findWords(vector<string> & words)
    {
        vector<string> vecResult;

        for (int iIndex = 0; iIndex < words.size(); iIndex ++)
        {
            if (keyboardSingleLine(words[iIndex]))
            {
                vecResult.push_back(words[iIndex]);
            }
        }

        return vecResult;
    }

    bool keyboardSingleLine(const string & strWord)
    {
        static int aiLetterLine[] = { 2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3 };

        int iWordLineIndex = 0;

        for (int iIndex = 0; iIndex < strWord.size(); iIndex ++)
        {
            int iCurrentLetterLine = (strWord[iIndex] >= 'A' && strWord[iIndex] <= 'Z' ? aiLetterLine[strWord[iIndex] - 'A'] : aiLetterLine[strWord[iIndex] - 'a']);

            if (iIndex == 0)
            {
                iWordLineIndex = iCurrentLetterLine;
            }

            if (iCurrentLetterLine != iWordLineIndex)
            {
                return false;
            }
        }

        return true;
    }
};

