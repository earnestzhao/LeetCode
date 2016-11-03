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

    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        
        TreeNode * pstResultLeft  = lowestCommonAncestor(root -> left,  p, q);
        TreeNode * pstResultRight = lowestCommonAncestor(root -> right, p, q);
        
        if (pstResultLeft == NULL)
        {
            return pstResultRight;
        }
        
        if (pstResultRight == NULL)
        {
            return pstResultLeft;
        }
        
        return root;
    }
};

/*

Smart !!! Excellent !!! Wonderful !!!

*/
