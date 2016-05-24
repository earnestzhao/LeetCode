class Solution
{
public:

    int mySqrt(int x)
    {
        if (x < 0)
        {
            return INT_MIN;
        }
        
        int iHighestOneTest = (1 << (sizeof(int) * 8 - 2));
        int iHighestOnePos  = sizeof(int) * 8 - 1;
        
        while (iHighestOneTest > 0 && (x & iHighestOneTest) == 0)
        {
            iHighestOnePos --, iHighestOneTest >>= 1;
        }
        
        if (iHighestOnePos <= 0)
        {
            return 0;
        }
        
        if (iHighestOnePos == 1)
        {
            return 1;
        }
        
        int iResultMin = (1 << (iHighestOnePos / 2 - 1));
        int iResultMax = (1 << (iHighestOnePos / 2 + 1));
        
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

Thinking is right, but a lot of bugs.

1. Edge condition

2. Not using binary search at last.

Correct algorithm:

1. Calculate possible range of solution, using bit operation. Possible range: [1 << (hpos(x) / 2 - 1), 1 << (hpos(x) / 2 + 1)]. O(1)

2. Do binary search in this range.

It is better than pure binary search, but pure binary search's real runtime is better.

It is because 'step 1' will do O(sizeof(int)) operations, and 'step 2' will do O(logn) operations.

If 'step 1' is omitted, only 'step 2' cost O(logn). Although the range is small, the O(sizeof(int)) operations cost more time.

*/
