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
        if (root == NULL)
        {
            return NULL;
        }
        
        int iMinValue = p -> val < q -> val ? p -> val : q -> val;
        int iMaxValue = p -> val > q -> val ? p -> val : q -> val;
        
        if (root -> val >= iMinValue && root -> val <= iMaxValue)
        {
            return root;
        }
        
        if (root -> val < iMinValue)
        {
            return lowestCommonAncestor(root -> right, p, q);
        }
        else
        {
            return lowestCommonAncestor(root -> left, p, q);
        }
    }
};
