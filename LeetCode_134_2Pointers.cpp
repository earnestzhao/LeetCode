class Solution
{
public:

    int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
    {
        for (int iBehindIndex = 0, iFrontIndex = 0, iSumValue = 0; iBehindIndex < gas.size();)
        {
            if (iSumValue >= 0)
            {
                iSumValue += gas[iFrontIndex] - cost[iFrontIndex];
                iFrontIndex = (iFrontIndex + 1) % gas.size();
                
                if (iFrontIndex == iBehindIndex && iSumValue >= 0)
                {
                    return iBehindIndex;
                }
            }
            else
            {
                iSumValue -= gas[iBehindIndex] - cost[iBehindIndex];
                iBehindIndex ++;
            }
        }
        
        return -1;
    }
};

/*

Bug free once !!!

Two pointers algorithm.

Time complexity: O(n). Space complexity: O(n).

1. Generate vecGasLeft, which vecGasLeft[i] = gas[i] - cost[i].

2. Define 2 Indexes iBehindIndex and iFrontIndex, calculate iSumValue = SIGMA (iBehindIndex<=i<=iFrontIndex) { vecGasLeft[i] }.

3. If iSumValue is non-negative, then, iFrontIndex = (iFrontIndex + 1) % vecGasLeft.size(). Otherwise, iBehindIndex ++. Calculate new iSumValue.

4. Finally, if iBehindIndex is equal to iFrontIndex and iSumValue is non-negative, the result is iBehindIndex. Otherwise, return -1.

----------------------------------------

Optiminize:

The space complexity can be optiminized to O(1), which the step 1 of the algorithm can be merged to step 2 and 3.

This program above is the optiminized version.

*/
