class Solution
{
public:

    int integerReplacement(int n)
    {
        int iResult = 0;
        
        for (; n > 1; iResult ++)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                if (n == 3)
                {
                    n = 1;
                }
                else
                {
                    n = (n - 1) % 4 ? n / 2 + 1 : n / 2;
                }
                
                iResult ++;
            }
        }
        
        return iResult;
    }
};

/*

INT_MAX !!! INT_MAX !!!

The edge INT_MAX in problem whose type is calculation is VERY IMPORTANT !!!

Take care in INT_MAX '+' and '*' operation.

*/
