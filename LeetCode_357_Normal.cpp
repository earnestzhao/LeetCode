class Solution
{
public:

    int countNumbersWithUniqueDigits(int n)
    {
        vector<int> vecNineFactDesc;
        vecNineFactDesc.push_back(1);
        
        int iLoopTimes = (n > 10 ? 10 : n);
        
        for (int iIndex = 0, iCurrValue = 9; iIndex < iLoopTimes - 1; iIndex ++, iCurrValue --)
        {
            vecNineFactDesc.push_back(vecNineFactDesc[iIndex] * iCurrValue);
        }
        
        vector<int> vecResultList;
        vecResultList.push_back(1);
        
        for (int iIndex = 1; iIndex <= iLoopTimes; iIndex ++)
        {
            vecResultList.push_back(9 * vecNineFactDesc[iIndex - 1] + vecResultList[iIndex - 1]);
        }
        
        return vecResultList[iLoopTimes];
    }
};

/*

Bug free once !!!

Dynamic programming and combinatorial mathematics.

----------------------------------------

Recursive relation:

result[0] = 1;

result[i] = C(9,1) * MUL(0<=j<i-1) { C(9-j, 1) } + result[i-1].

If 'j' cannot be valid, the result value of MUL expression is 1.

----------------------------------------

Analyze:

1. 'result[i-1]' is a part of 'result[i]' where the highest 'k' digits is 0.

2. Consider the condition where the highest digit is not 0, the number of the possible condition is C(9,1) * C(9,1) * C(8,1)...

*/
