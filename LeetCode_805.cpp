class Solution
{
public:

    bool splitArraySameAverage(vector<int> & A)
    {
        int iSumValue = 0;

        for (int iIndex = 0; iIndex < A.size(); iIndex ++)
        {
            iSumValue += A[iIndex];
        }

        return depthSearch(A, iSumValue, 0, 0, 0);
    }

    bool depthSearch(const vector<int> & vecValueList, int iTotalSumValue, int iCurrentSumValue, int iCurrentSumItemNumber, int iCurrentIndex)
    {
        if (iCurrentIndex >= vecValueList.size())
        {
            return false;
        }

        if (iCurrentSumValue > iTotalSumValue - iCurrentSumValue && iCurrentSumItemNumber < vecValueList.size() - iCurrentSumItemNumber)
        {
            return false;
        }

        if (iCurrentSumItemNumber > 0 && iCurrentSumValue * vecValueList.size() == iCurrentSumItemNumber * iTotalSumValue)
        {
            return true;
        }

        for (int iIndex = iCurrentIndex; iIndex < vecValueList.size(); iIndex ++)
        {
            if (depthSearch(vecValueList, iTotalSumValue, iCurrentSumValue + vecValueList[iIndex], iCurrentSumItemNumber + 1, iIndex + 1))
            {
                return true;
            }
        }

        return false;
    }
};

