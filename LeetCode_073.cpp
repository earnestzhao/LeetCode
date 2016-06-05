class Solution
{
public:

    void setZeroes(vector<vector<int>> & matrix)
    {
        int iRecordRowIndex = -1;
        int iRecordColIndex = -1;
        
        for (int iIndex = 0; iIndex < matrix.size(); iIndex ++)
        {
            for (int jIndex = 0; jIndex < matrix[iIndex].size(); jIndex ++)
            {
                if (matrix[iIndex][jIndex] == 0)
                {
                    if (iRecordRowIndex < 0)
                    {
                        iRecordRowIndex = iIndex;
                        iRecordColIndex = jIndex;
                    }
                    
                    matrix[iRecordRowIndex][jIndex] = 0;
                    matrix[iIndex][iRecordColIndex] = 0;
                }
            }
        }
        
        if (iRecordRowIndex >= 0)
        {
            for (int iIndex = 0; iIndex < matrix.size(); iIndex ++)
            {
                if (matrix[iIndex][iRecordColIndex] == 0)
                {
                    for (int jIndex = 0; jIndex < matrix[iIndex].size(); jIndex ++)
                    {
                        if (iIndex != iRecordRowIndex)
                        {
                            matrix[iIndex][jIndex] = 0;
                        }
                    }
                }
            }
            
            for (int iIndex = 0; iIndex < matrix[0].size(); iIndex ++)
            {
                if (matrix[iRecordRowIndex][iIndex] == 0)
                {
                    for (int jIndex = 0; jIndex < matrix.size(); jIndex ++)
                    {
                        matrix[jIndex][iIndex] = 0;
                    }
                }
            }
            
            for (int iIndex = 0; iIndex < matrix[iRecordRowIndex].size(); iIndex ++)
            {
                matrix[iRecordRowIndex][iIndex] = 0;
            }
        }
    }
};

/*

Thinking is right, but cost so much time... a small bug...

Normal algorithm, using a row and a column which will be set to zero to store zero setting information.

Because of using row and column in raw matrix, so the space complexity is O(1).

*/
