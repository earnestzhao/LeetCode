class Solution
{
public:

    int numTrees(int n)
    {
        vector<vector<int>> vecResult;
        vecResult.push_back(vector<int>());
        vecResult.push_back(vector<int>());
        
        vecResult[0].push_back(1);
        vecResult[1].push_back(0);
        vecResult[1].push_back(1);
        
        for (int iIndex = 2; iIndex <= n; iIndex ++)
        {
            vecResult.push_back(vector<int>(iIndex + 1, 0));
            
            for (int jIndex = 1; jIndex < vecResult[iIndex - 1].size(); jIndex ++)
            {
                for (int kIndex = 1; kIndex <= jIndex + 1; kIndex ++)
                {
                    vecResult[iIndex][kIndex] += vecResult[iIndex - 1][jIndex];
                }
            }
        }
        
        int iFinalResult = 0;
        
        for (int iIndex = 0; iIndex < vecResult[n].size(); iIndex ++)
        {
            iFinalResult += vecResult[n][iIndex];
        }
        
        return iFinalResult;
    }
};

/*

Thinking is right, and almost bug free, but TLE occured on first time.

Dynamic programming. Define vecResult[i][j] as the number of the right side nodes of the 'jth' binary search tree when 'i' nodes, which has the follow relation:

vecResult[i] = UNION (0<=j<vecResult[i-1].size()) Range[1, vecResult[i-1][j] + 1], and the final result is vecResult[n].size().

Time complexity: O(n!), space complexity: O(n!). TLE and MLE must happen.

----------------------------------------------------------------------------------------------------

Optiminize dynamic programming relation.

Define vecResult[i][j] as the binary search tree number which has 'j' right side nodes when 'i' nodes, which has the follow releation:

vecResult[i][j] = SIGMA (1<=k<=j+1<=i-1) { vecResult[i-1][k] }

Time complexity: O(n^3), space comlexity: O(n^2).

*/
