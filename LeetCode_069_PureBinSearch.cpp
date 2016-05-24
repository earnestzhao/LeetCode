class Solution
{
public:

    int mySqrt(int x)
    {
        if (x < 0)
        {
            return INT_MIN;
        }
        
        int iResultMin = 0;
        int iResultMax = INT_MAX >> (sizeof(int) * 4 - 2);
        
        while (iResultMin <= iResultMax)
        {
            int iResultMid    = iResultMin + (iResultMax - iResultMin) / 2;
            int iResultMidSqu = iResultMid * iResultMid;
            
            if (iResultMidSqu == x)
            {
                return iResultMid;
            }
            
            if (iResultMidSqu > x || iResultMidSqu % 10 != (iResultMid % 10) * (iResultMid % 10) % 10)
            {
                iResultMax = iResultMid - 1;
            }
            else
            {
                iResultMin = iResultMid + 1;
            }
        }
        
        return iResultMax;
    }
};

/*

Pure binary search. Thinking is exactly right, but not bug free.

Edge max is INT_MAX >> (sizeof(int) * 8 / 2 - 2)

*/
