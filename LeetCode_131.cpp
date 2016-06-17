class Solution
{
public:

    vector<vector<string>> partition(string s)
    {
        vector<string> vecSubResult;
        vector<vector<string>> vecResult;
        partition(s, 0, vecSubResult, vecResult);
        return vecResult;
    }
    
private:

    void partition(const string & strSrc, int iStartIndex, vector<string> & vecSubResult, vector<vector<string>> & vecResult)
    {
        if (iStartIndex >= strSrc.size())
        {
            vecResult.push_back(vecSubResult);
            return;
        }
        
        for (int iIndex = iStartIndex; iIndex < strSrc.size(); iIndex ++)
        {
            vecSubResult.push_back(strSrc.substr(iStartIndex, iIndex - iStartIndex + 1));
            partition(strSrc, iIndex + 1, vecSubResult, vecResult);
            vecSubResult.pop_back();
        }
    }
};
