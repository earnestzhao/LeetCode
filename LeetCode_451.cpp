
bool greaterThan(const pair<int, char> & stOper1, const pair<int, char> & stOper2)
{
    return stOper1.first > stOper2.first;
}

class Solution
{
public:

    string frequencySort(string s)
    {
        vector<pair<int, char>> vecFreqCount(256, make_pair(0, 0));
        
        for (int iIndex = 0; iIndex < s.length(); iIndex ++)
        {
            vecFreqCount[s[iIndex]].first ++;
            vecFreqCount[s[iIndex]].second = s[iIndex];
        }
        
        sort(vecFreqCount.begin(), vecFreqCount.end(), greaterThan);
        
        string strResult;
        
        for (int iIndex = 0; iIndex < vecFreqCount.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < vecFreqCount[iIndex].first; jIndex ++)
            {
                strResult.push_back(vecFreqCount[iIndex].second);
            }
        }
        
        return strResult;
    }
};
