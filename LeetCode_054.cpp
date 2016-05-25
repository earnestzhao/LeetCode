class Solution
{
public:

    vector<int> spiralOrder(vector<vector<int>> & matrix)
    {
        int iRowNumber = matrix.size();
        
        if (iRowNumber <= 0)
        {
            return vector<int>();
        }
        
        int iColNumber = matrix[0].size();
        
        if (iColNumber <= 0)
        {
            return vector<int>();
        }
        
        int iTotalElemNumber = iRowNumber * iColNumber;
        
        vector<int> vecSpiralOrder;
        
        int iAreaIndex = 0;
        
        for (; iAreaIndex < iRowNumber / 2; iAreaIndex ++)
        {
            for (int jIndex = iAreaIndex; jIndex < iColNumber - iAreaIndex - 1; jIndex ++)
            {
                vecSpiralOrder.push_back(matrix[iAreaIndex][jIndex]);
            }
            
            for (int jIndex = iAreaIndex; jIndex < iRowNumber - iAreaIndex - 1; jIndex ++)
            {
                vecSpiralOrder.push_back(matrix[jIndex][iColNumber - iAreaIndex - 1]);
            }
            
            for (int jIndex = iAreaIndex; jIndex < iColNumber - iAreaIndex - 1; jIndex ++)
            {
                vecSpiralOrder.push_back(matrix[iRowNumber - iAreaIndex - 1][iColNumber - jIndex - 1]);
            }
            
            for (int jIndex = iAreaIndex; jIndex < iRowNumber - iAreaIndex - 1; jIndex ++)
            {
                vecSpiralOrder.push_back(matrix[iRowNumber - jIndex - 1][iAreaIndex]);
            }
        }
        
        if (iRowNumber % 2 && vecSpiralOrder.size() < iTotalElemNumber)
        {
            for (int jIndex = iAreaIndex; jIndex < iColNumber - iAreaIndex; jIndex ++)
            {
                vecSpiralOrder.push_back(matrix[iAreaIndex][jIndex]);
                
                if (vecSpiralOrder.size() >= iTotalElemNumber)
                {
                    break;
                }
            }
        }
        
        while (vecSpiralOrder.size() > iTotalElemNumber)
        {
            vecSpiralOrder.pop_back();
        }
        
        return vecSpiralOrder;
    }
};

/*

Thinking is right, but not bug free, and complex...

1. Traverse elements by spiral order.

2. If row number is odd number, traverse the last single line.

3. The sequence is right now, but maybe some elements is accessed not only once. So, delete the tail elements which is more than total element number.

The method is not simple, too many points are needed to notice. Is there any simple method? Research it later.

*/
