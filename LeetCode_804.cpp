class Solution
{
public:
    
    int uniqueMorseRepresentations(vector<string> & words)
    {
        char * apszLetterCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        int iUniqueMorse = 0;
        unordered_set<string> hsetEncodeString;

        for (int iIndex = 0; iIndex < words.size(); iIndex ++)
        {
            string strEncode = "";

            for (int jIndex = 0; jIndex < words[iIndex].size(); jIndex ++)
            {
                strEncode.append(apszLetterCode[words[iIndex][jIndex] - 'a']);
            }

            if (hsetEncodeString.find(strEncode) == hsetEncodeString.end())
            {
                hsetEncodeString.insert(strEncode);
                iUniqueMorse ++;
            }
        }

        return iUniqueMorse;
    }
};

