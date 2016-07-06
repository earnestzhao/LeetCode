class Solution
{
public:

    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z)
        {
            return false;
        }
        
        if (x == z || y == z || x + y == z)
        {
            return true;
        }
        
        return z % gcd(x, y) == 0;
    }
    
private:

    int gcd(int iOper1, int iOper2)
    {
        return iOper2 == 0 ? iOper1 : gcd(iOper2, iOper1 % iOper2);
    }
};

/*

Using 'Euclidean Algorithm' to calculate GCD (Greatest Common Divisor).

If 'z' is measurable, it must be a multiple of 'GCD'.

*/
