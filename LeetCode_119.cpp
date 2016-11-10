class Solution
{
public:

    vector<int> getRow(int rowIndex)
    {
        vector<int> vecResult[2];
        vecResult[0].push_back(1);
        
        int iPrevIndex = 0;
        int iCurrIndex = 1;
        
        for (int iRowIndex = 1; iRowIndex <= rowIndex; iRowIndex ++)
        {
            vecResult[iCurrIndex].clear();
            vecResult[iCurrIndex].push_back(1);
            
            for (int iFillIndex = 1; iFillIndex < vecResult[iPrevIndex].size(); iFillIndex ++)
            {
                vecResult[iCurrIndex].push_back(vecResult[iPrevIndex][iFillIndex] + vecResult[iPrevIndex][iFillIndex - 1]);
            }
            
            vecResult[iCurrIndex].push_back(1);
            iPrevIndex = !iPrevIndex;
            iCurrIndex = !iCurrIndex;
        }
        
        return vecResult[iPrevIndex];
    }
};
