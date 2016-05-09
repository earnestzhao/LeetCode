class Solution
{
public:
    
    int reverse(int x)
    {
        int iResult = 0, iResultLast = 0;
        
        for (int iPositive = abs(x); iPositive > 0; iPositive /= 10)
        {
            iResult = iResult * 10 + iPositive % 10;
            
            if (iResult % 10 != iPositive % 10)
            {
                return 0;
            }
            else
            {
                iResultLast = iResult;
            }
        }
        
        return (x < 0 ? - 1 : 1) * iResult;
    }
};
