/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:

    int sumNumbers(TreeNode * root)
    {
        if (root == NULL)
        {
            return 0;
        }
        
        int iFinalResult   = 0;
        int iCurrentResult = 0;
        
        sumNumbersDFS(root, iCurrentResult, iFinalResult);
        return iFinalResult;
    }
    
private:

    void sumNumbersDFS(TreeNode * pstRoot, int & iCurrentResult, int & iFinalResult)
    {
        if (pstRoot -> left == NULL && pstRoot -> right == NULL)
        {
            iFinalResult += iCurrentResult * 10 + pstRoot -> val;
            return;
        }
        
        iCurrentResult = iCurrentResult * 10 + pstRoot -> val;
        
        if (pstRoot -> left != NULL)
        {
            sumNumbersDFS(pstRoot -> left, iCurrentResult, iFinalResult);
        }
        
        if (pstRoot -> right != NULL)
        {
            sumNumbersDFS(pstRoot -> right, iCurrentResult, iFinalResult);
        }
        
        iCurrentResult /= 10;
    }
};

/*

Bug free once, but it seems slow.

Normal depth-first search.

*/
