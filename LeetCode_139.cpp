class Solution
{
public:

    bool wordBreak(string s, unordered_set<string> & wordDict)
    {
        vector<int> vecMatchIndex;
        vecMatchIndex.push_back(-1);
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            for (int iMatchIndex = 0; iMatchIndex < vecMatchIndex.size(); iMatchIndex ++)
            {
                if (wordDict.find(s.substr(vecMatchIndex[iMatchIndex] + 1, iIndex - vecMatchIndex[iMatchIndex])) != wordDict.end())
                {
                    vecMatchIndex.push_back(iIndex);
                    break;
                }
            }
        }
        
        return vecMatchIndex[vecMatchIndex.size() - 1] == s.length() - 1;
    }
};

/*

Thinking is right, and bug free, but TLE occured at first.

Using vecMatchIndex to store each matched indexes.

The index 'i' would be added into vecMatchIndex only when the substring of 's' which start from either vecMatchIndex[j] + 1 and end to i is in the 'wordDict'.

There must be better solutions. Research it later.

*/
