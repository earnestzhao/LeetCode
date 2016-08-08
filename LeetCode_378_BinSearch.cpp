class Solution
{
public:

    int kthSmallest(vector<vector<int>> & matrix, int k)
    {
        int iRowNumber = matrix.size();
        
        if (iRowNumber <= 0)
        {
            return INT_MIN;
        }
        
        int iMinValue = matrix[0][0];
        int iMaxValue = matrix[iRowNumber - 1][iRowNumber - 1];
                
        while (iMinValue < iMaxValue)
        {
            int iMidValue  = iMinValue + (iMaxValue - iMinValue) / 2;
            int iCountLess = 0;
            
            for (int iIndex = 0; iIndex < matrix.size(); iIndex ++)
            {
                iCountLess += upper_bound(matrix[iIndex].begin(), matrix[iIndex].end(), iMidValue) - matrix[iIndex].begin();
            }
            
            if (iCountLess < k)
            {
                iMinValue = iMidValue + 1;
            }
            else
            {
                iMaxValue = iMidValue;
            }
        }
        
        return iMinValue;
    }
};

/*

Binary search.

When a vector is sortted by increasing order, the 'upper_bound' return the first iterator which *iterator is greater than 'key'.

Why the 'iMinValue' is the final result?

I only know the loop condition is 'iMinValue <= Solution <= iMaxValue', after loop, the relation is 'iMaxValue <= iMinValue'.

Then, 'iMinValue <= Solution <= iMaxValue <= iMinValue'. So, 'iMinValue = Solution'.

How about the solution is not in the matrix, but can satisfy this condition above? It still puzzles me ...

*/
