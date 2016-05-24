class Solution
{
public:

    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1.0F;
        }
        
        if (n < 0)
        {
            if (n == INT_MIN)
            {
                n = INT_MAX - 1;
            }
            else
            {
                n = 0 - n;
            }
            
            x = 1 / x;
        }
        
        if (n == 1)
        {
            return x;
        }
        
        double dPowDiv2 = myPow(x, n / 2);
        
        if (n % 2)
        {
            return dPowDiv2 * dPowDiv2 * x;
        }
        else
        {
            return dPowDiv2 * dPowDiv2;
        }
    }
};

/*

Using divide and conquer for reducing times of calculation.

pow(x, n) = pow(x, n / 2) * pow(x, n / 2).

1. Notice: odd number.

2. Notice: edge, such as INT_MIN.

*/
