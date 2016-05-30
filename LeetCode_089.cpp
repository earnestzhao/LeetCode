class Solution
{
public:

    vector<int> grayCode(int n)
    {
        if (n <= 0)
        {
            return vector<int>(1, 0);
        }
        
        vector<int> vecResult;
        vecResult.push_back(0);
        vecResult.push_back(1);
        
        if (n == 1)
        {
            return vecResult;
        }
        
        for (int iIndex = 2; iIndex <= n; iIndex ++)
        {
            int iHighBitMask  = (1 << (iIndex - 1));
            
            for (int jIndex = vecResult.size() - 1; jIndex >= 0; jIndex --)
            {
                vecResult.push_back(iHighBitMask | vecResult[jIndex]);
            }
        }
        
        return vecResult;
    }
};

/*

Almost bug free... Mistake in ++ or --...

Dynamic Programming. Thinking about the rule of the gray code...

vecResult[i] = vecResult[i-1] UNION { (1 << i) | vecResult[i-1](n...0) }

*/
