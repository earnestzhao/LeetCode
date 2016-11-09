class Solution
{
public:

    int maxRotateFunction(vector<int> & A)
    {
        int iSumValue   = 0;
        int iMaxResult  = 0;
        int iStepResult = 0;
        
        for (int iIndex = 0; iIndex < A.size(); iIndex ++)
        {
            iSumValue   += A[iIndex];
            iStepResult += A[iIndex] * iIndex;
        }
        
        iMaxResult = iStepResult;
        
        for (int iIndex = A.size() - 1; iIndex > 0; iIndex --)
        {
            iStepResult += iSumValue - A[iIndex] - (A.size() - 1) * A[iIndex];
            
            if (iMaxResult < iStepResult)
            {
                iMaxResult = iStepResult;
            }
        }
        
        return iMaxResult;
    }
};

/*

Dynamic Programming.

Fantastic !!! Smart !!! Bug free !!!

*/
