class Solution
{
public:

    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        
        int iFinalResult = 0;
        
        for (int iDivisior = 2; iDivisior < n; iDivisior ++)
        {
            int iProductBase    = n / iDivisior;
            int iProductAlter   = n % iDivisior;
            int iCurrentProduct = 1;
            
            for (int iCalLoopTimes = iDivisior; iCalLoopTimes > 0; iCalLoopTimes --, iProductAlter --)
            {
                iCurrentProduct *= (iProductAlter > 0 ? iProductBase + 1 : iProductBase);
            }
            
            if (iCurrentProduct > iFinalResult)
            {
                iFinalResult = iCurrentProduct;
            }
        }
        
        return iFinalResult;
    }
};

/*

Thinking is right, but some bugs occur because of optimization.

If we would want a greater product, the each result of the break must be equal.

So, define a divisior from 2 to n-1, we can just test the product of equal break.

*/
