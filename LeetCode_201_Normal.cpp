class Solution
{
public:

    int rangeBitwiseAnd(int m, int n)
    {
        int iResult = 0;
        
        for (int iScanNumber = 0x40000000; iScanNumber > 0; iScanNumber >>= 1)
        {
            if ((m & iScanNumber) == (n & iScanNumber))
            {
                iResult |= (m & iScanNumber);
            }
            else
            {
                break;
            }
        }
        
        return iResult;
    }
};

/*

Thinking is right, and bug free!

Find the same high bit.

If a bit B is different between m and n, then, it must contain 0 every bit lower than B or equal to B from m to n. 

*/
