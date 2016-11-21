/*

285. Inorder Successor in BST

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

*/

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
    
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p)
    {
        if (p == NULL)
        {
            return NULL;
        }
        
        TreeNode * pstResult = p -> right;
        
        while (pstResult != NULL && pstResult -> left != NULL)
        {
            pstResult = pstResult -> left;
        }
        
        if (pstResult == NULL)
        {
            for (TreeNode * pstFinder = root; pstFinder != p;)
            {
                if (p -> val < pstFinder -> val)
                {
                    pstResult = pstFinder;
                    pstFinder = pstFinder -> left;
                }
                else
                {
                    pstFinder = pstFinder -> right;
                }
            }
        }
        
        return pstResult;
    }
};

/*

NOTICE !!! If p has no right child ... !!!

*/
