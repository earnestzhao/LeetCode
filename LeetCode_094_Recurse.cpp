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

    vector<int> inorderTraversal(TreeNode * root)
    {
        vector<int> vecResult;
        
        inorderTraversal(root, vecResult);
        
        return vecResult;
    }
    
private:

    void inorderTraversal(TreeNode * pstRoot, vector<int> & vecResult)
    {
        if (pstRoot == NULL)
        {
            return;
        }
        
        inorderTraversal(pstRoot -> left, vecResult);
        
        vecResult.push_back(pstRoot -> val);
        
        inorderTraversal(pstRoot -> right, vecResult);
    }
};
