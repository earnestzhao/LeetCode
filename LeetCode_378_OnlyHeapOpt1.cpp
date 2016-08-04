class Solution
{
public:

    int kthSmallest(vector<vector<int>> & matrix, int k)
    {
        priority_queue<int, vector<int>, less<int>> priqMaxRootHeap;
        
        int iKSqrtCeil   = (int)(ceil(sqrt(k)));
        int iEndRowIndex = iKSqrtCeil < matrix.size() ? iKSqrtCeil - 1 : matrix.size() - 1;
        int iEndColIndex = iEndRowIndex;
        
        for (int iRowIndex = 0; iRowIndex <= iEndRowIndex; iRowIndex ++)
        {
            for (int iColIndex = iRowIndex; iColIndex < matrix.size(); iColIndex ++)
            {
                if (priqMaxRootHeap.size() < k)
                {
                    priqMaxRootHeap.push(matrix[iRowIndex][iColIndex]);
                }
                else
                {
                    if (matrix[iRowIndex][iColIndex] < priqMaxRootHeap.top())
                    {
                        priqMaxRootHeap.pop();
                        priqMaxRootHeap.push(matrix[iRowIndex][iColIndex]);
                    }
                }
                
                if (iRowIndex != iColIndex)
                {
                    if (priqMaxRootHeap.size() < k)
                    {
                        priqMaxRootHeap.push(matrix[iColIndex][iRowIndex]);
                    }
                    else
                    {
                        if (matrix[iColIndex][iRowIndex] < priqMaxRootHeap.top())
                        {
                            priqMaxRootHeap.pop();
                            priqMaxRootHeap.push(matrix[iColIndex][iRowIndex]);
                        }
                    }
                }
                
                if (iRowIndex == iEndRowIndex && iColIndex >= iEndColIndex)
                {
                    break;
                }
            }
        }
        
        return priqMaxRootHeap.top();
    }
};

/*

Optimization:

1. Add two elements which is symmetrical each time to reduce loop times.

2. Only scan elements from (0, 0) to (sqrt(k), sqrt(k)) both by rows and columns.

Time complexity: O(klogk), runtime: 100ms

*/
