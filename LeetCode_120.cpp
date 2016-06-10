class Solution
{
public:

    int minimumTotal(vector<vector<int>> & triangle)
    {
        if (triangle.size() <= 0)
        {
            return 0;
        }
        
        if (triangle[0].size() <= 0)
        {
            return 0;
        }
        
        vector<int> vecLayerMin[2];
        
        for (int iIndex = 0; iIndex < 2; iIndex ++)
        {
            for (int jIndex = 0; jIndex < triangle.size(); jIndex ++)
            {
                vecLayerMin[iIndex].push_back(0);
            }
        }
        
        vecLayerMin[0][0] = triangle[0][0];
        
        int iActiveIndex = 1;
        
        for (int iIndex = 1; iIndex < triangle.size(); iIndex ++, iActiveIndex = !iActiveIndex)
        {
            for (int jIndex = 0; jIndex < triangle[iIndex].size(); jIndex ++)
            {
                int iMinPrevLayer = INT_MAX;
                
                if (jIndex > 0 && vecLayerMin[!iActiveIndex][jIndex - 1] < iMinPrevLayer)
                {
                    iMinPrevLayer = vecLayerMin[!iActiveIndex][jIndex - 1];
                }
                
                if (jIndex < iIndex && vecLayerMin[!iActiveIndex][jIndex] < iMinPrevLayer)
                {
                    iMinPrevLayer = vecLayerMin[!iActiveIndex][jIndex];
                }
                
                vecLayerMin[iActiveIndex][jIndex] = iMinPrevLayer + triangle[iIndex][jIndex];
            }
        }
        
        int iFinalResult = INT_MAX;
        
        for (int iIndex = 0; iIndex < vecLayerMin[!iActiveIndex].size(); iIndex ++)
        {
            if (vecLayerMin[!iActiveIndex][iIndex] < iFinalResult)
            {
                iFinalResult = vecLayerMin[!iActiveIndex][iIndex];
            }
        }
        
        return iFinalResult;
    }
};

/*

Thinking is right, but 2 corner condition bugs.

Dynamic programming. Define vecMinTotal[i][j] as the minimum total value of position triangle[i][j], which has:

vecMinTotal[i][j] = min { vecMinTotal[i-1][j-1], vecMinTotal[i][j] } + triangle[i][j].

If this method is used, the space complexity is O(n*n).

Optiminize method:

1. Define vecLayerMin[0/1][j] record the minimum total of previous layer and current layer.

2. Swap current layer and the previous layer before the next out-loop begins.

The optiminize method has space complexity 2n = O(n).

*/
