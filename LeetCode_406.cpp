class Solution
{
public:

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> & people)
    {
        if (people.size() <= 1)
        {
            return people;
        }

        bool PairSmaller(const pair<int, int> & operandLeft, const pair<int, int> & operandRight);
        vector<pair<int, int>> vecResult = people;
        sort(vecResult.begin(), vecResult.end(), PairSmaller);
        
        vector<int> vecPreEqualNumber;
        vecPreEqualNumber.push_back(0);

        for (int iIndex = 1; iIndex < vecResult.size(); iIndex ++)
        {
            if (vecResult[iIndex].first == vecResult[iIndex - 1].first)
            {
                vecPreEqualNumber.push_back(vecPreEqualNumber[iIndex - 1] + 1);
            }
            else
            {
                vecPreEqualNumber.push_back(0);
            }
        }

        for (int iIndex = vecResult.size() - 2; iIndex >= 0; iIndex --)
        {
            int iSetIndex  = iIndex;
            pair<int, int> pairCurrent = vecResult[iIndex];
            int iMoveTimes = pairCurrent.second - vecPreEqualNumber[iIndex];

            for (; iMoveTimes > 0; iMoveTimes --, iSetIndex ++)
            {
                vecResult[iSetIndex] = vecResult[iSetIndex + 1];
            }

            vecResult[iSetIndex] = pairCurrent;
        }

        return vecResult;
    }
};

bool PairSmaller(const pair<int, int> & operandLeft, const pair<int, int> & operandRight)
{
    if (operandLeft.first == operandRight.first)
    {
        return operandLeft.second < operandRight.second;
    }

    return operandLeft.first < operandRight.first;
}


/*

The way of thinking is OK. Sort first, then, use k as reverse number to re-position.

Compile Error !!! Array Overflow Error !!!

That's because this is the first problem of this year !!!

*/

