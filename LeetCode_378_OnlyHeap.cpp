class Solution
{
public:

    int kthSmallest(vector<vector<int>> & matrix, int k)
    {
        priority_queue<int, vector<int>, less<int>> priqMaxRootHeap;
        
        for (int iRowIndex = 0; iRowIndex < matrix.size(); iRowIndex ++)
        {
            for (int iColIndex = 0; iColIndex < matrix.size(); iColIndex ++)
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
            }
        }
        
        return priqMaxRootHeap.top();
    }
};

/*

Bug free once !!!

Using heap (priority_queue) to keep maximum 'k' elements.

Time complexity: O(n*n*logk), runtime: 116ms

*/
