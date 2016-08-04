class Solution
{
public:

    int kthSmallest(vector<vector<int>> & matrix, int k)
    {
        int iFromHeadKth = k;
        int iFromTailKth = matrix.size() * matrix.size() - k + 1;
        int iFinalResult = 0;
        
        if (iFromHeadKth <= iFromTailKth)
        {
            int iKSqrtCeil   = (int)(ceil(sqrt(iFromHeadKth)));
            int iEndRowIndex = iKSqrtCeil - 1;
            int iEndColIndex = iEndRowIndex;
            
            priority_queue<int, vector<int>, less<int>> priqMaxRootHeap;
            
            for (int iRowIndex = 0; iRowIndex <= iEndRowIndex; iRowIndex ++)
            {
                for (int iColIndex = iRowIndex; iColIndex < matrix.size(); iColIndex ++)
                {
                    if (priqMaxRootHeap.size() < iFromHeadKth)
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
                        if (priqMaxRootHeap.size() < iFromHeadKth)
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
            
            iFinalResult = priqMaxRootHeap.top();
        }
        else
        {
            int iKSqrtCeil   = (int)(ceil(sqrt(iFromTailKth)));
            int iEndRowIndex = matrix.size() - iKSqrtCeil;
            int iEndColIndex = iEndRowIndex;
            
            priority_queue<int, vector<int>, greater<int>> priqMinRootHeap;
            
            for (int iRowIndex = matrix.size() - 1; iRowIndex >= iEndRowIndex; iRowIndex --)
            {
                for (int iColIndex = iRowIndex; iColIndex >= 0; iColIndex --)
                {
                    if (priqMinRootHeap.size() < iFromTailKth)
                    {
                        priqMinRootHeap.push(matrix[iRowIndex][iColIndex]);
                    }
                    else
                    {
                        if (matrix[iRowIndex][iColIndex] > priqMinRootHeap.top())
                        {
                            priqMinRootHeap.pop();
                            priqMinRootHeap.push(matrix[iRowIndex][iColIndex]);
                        }
                    }
                    
                    if (iRowIndex != iColIndex)
                    {
                        if (priqMinRootHeap.size() < iFromTailKth)
                        {
                            priqMinRootHeap.push(matrix[iColIndex][iRowIndex]);
                        }
                        else
                        {
                            if (matrix[iColIndex][iRowIndex] > priqMinRootHeap.top())
                            {
                                priqMinRootHeap.pop();
                                priqMinRootHeap.push(matrix[iColIndex][iRowIndex]);
                            }
                        }
                    }
                    
                    if (iRowIndex == iEndRowIndex && iColIndex <= iEndColIndex)
                    {
                        break;
                    }
                }
            }
            
            iFinalResult = priqMinRootHeap.top();
        }
        
        return iFinalResult;
    }
};

/*

Optimization:

The result can be described as 'kth smallest' or '(ek = matrix.size() * matrix.size() - k + 1)th biggest'.

Let mk = min(k, ek) and using 'mk' for scanning.

Time complexity: O((mk)log(mk)), runtime: 84ms

*/
