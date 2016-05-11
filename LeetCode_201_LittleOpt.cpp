class Solution
{
public:

    int rangeBitwiseAnd(int m, int n)
    {
        int iFinalOper = 0;
        
        for (int iScanNumber = m ^ n; iScanNumber > 0; iScanNumber >>= 1)
        {
            iFinalOper = (iFinalOper << 1) + 1;
        }
        
        return m & ~iFinalOper;
    }
};

/*

A little Optiminize. 

*/
