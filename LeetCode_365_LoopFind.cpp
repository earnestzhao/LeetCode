class Solution
{
public:

    bool canMeasureWater(int x, int y, int z)
    {
        if (z == 0)
        {
            return true;
        }
        
        if (z > x + y)
        {
            return false;
        }
        
        if (x == 0)
        {
            return z == y;
        }
        
        if (y == 0)
        {
            return z == x;
        }
        
        int iLargeCapacity = x > y ? x : y;
        int iSmallCapacity = x < y ? x : y;
        vector<bool> vecLargeCapacityModValueAppears(iLargeCapacity, false);
        
        for (int iTestFactor = (iLargeCapacity - z) / iSmallCapacity; true; iTestFactor ++)
        {
            int iTestModValue = (iTestFactor * (long long)iSmallCapacity + z) % iLargeCapacity;
            
            if (iTestModValue == 0)
            {
                return true;
            }
            
            if (vecLargeCapacityModValueAppears[iTestModValue])
            {
                break;
            }
            
            vecLargeCapacityModValueAppears[iTestModValue] = true;
        }
        
        return false;
    }
};

/*

Thinking is right, but a lot of bugs !!! My ability on math algorithm is too week !!!

If 'z' liters of water is measurable, then, it must have the relation as follow:

z = mx - ny  =>  m = (z + ny) / x  =>  Exist ((z + ny) % x == 0) { n }.

The loop is used for finding the 'n'.

*/
