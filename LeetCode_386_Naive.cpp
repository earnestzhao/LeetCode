class Solution
{
public:

    vector<int> lexicalOrder(int n)
    {
        vector<int> vecResult;
        vecResult.push_back(1);
        
        for (int iIndex = 1; iIndex < n; iIndex ++)
        {
            int iPrevNumber = vecResult[iIndex - 1];
            int iCurrNumber = iPrevNumber * 10;
            
            if (iCurrNumber > n)
            {
                iCurrNumber = iPrevNumber + 1;
                
                while (iCurrNumber % 10 == 0)
                {
                    iCurrNumber /= 10;
                }
                
                if (iCurrNumber > n)
                {
                    iCurrNumber = iCurrNumber / 10 + 1;
                }
            }
            
            vecResult.push_back(iCurrNumber);
        }
        
        return vecResult;
    }
};

/*

Thinking is right, but not bug free.

Naive algorithm.

1. iCurrNumber = iPrevNumber * 10, if iPrevNumber * 10 <= n.

2. iCurrNumber = DeleteAllTailZero(iPrevNumber) + 1, if DeleteAllTailZero(iPrevNumber) + 1 <= n.

3. iCurrNumber = (iPrevNumber + 1) / 10 + 1, if iPrevNumber + 1 > n.

4. vecResult[0] = 1.

*/
