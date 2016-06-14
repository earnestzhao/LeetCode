class Solution
{
public:

    int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
    {
        int iSubSumValue      = 0;
        int iTotalSumValue    = 0;
        int iFinalResultIndex = 0;
        
        for (int iIndex = 0; iIndex < gas.size(); iIndex ++)
        {
            iSubSumValue   += gas[iIndex] - cost[iIndex];
            iTotalSumValue += gas[iIndex] - cost[iIndex];
            
            if (iSubSumValue < 0)
            {
                iSubSumValue      = 0;
                iFinalResultIndex = iIndex + 1;
            }
        }
        
        return iTotalSumValue < 0 ? -1 : iFinalResultIndex;
    }
};

/*

Greedy.

The smart point is the calculation and judgement of 'iSubSumValue'.

*/
