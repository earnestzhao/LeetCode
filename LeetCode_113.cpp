/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:

    vector<vector<int>> pathSum(TreeNode * root, int sum)
    {
        vector<int> vecCombine;
        vector<vector<int>> vecResult;
        pathSum(root, sum, vecCombine, vecResult);
        return vecResult;
    }
    
private:

    void pathSum(TreeNode * pstRoot, int iSumValue, vector<int> & vecCurrResult, vector<vector<int>> & vecResult)
    {
        if (pstRoot == NULL)
        {
            return;
        }
        
        if (pstRoot -> left == NULL && pstRoot -> right == NULL)
        {
            if (iSumValue == pstRoot -> val)
            {
                vecCurrResult.push_back(pstRoot -> val);
                vecResult.push_back(vecCurrResult);
                vecCurrResult.pop_back();
            }
            
            return;
        }
        
        vecCurrResult.push_back(pstRoot -> val);
        pathSum(pstRoot -> left,  iSumValue - pstRoot -> val, vecCurrResult, vecResult);
        pathSum(pstRoot -> right, iSumValue - pstRoot -> val, vecCurrResult, vecResult);
        vecCurrResult.pop_back();
    }
};

/*

Bug free once !!! Normal backtracking.

*/
