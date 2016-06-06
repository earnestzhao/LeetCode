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

    bool isValidBST(TreeNode * root)
    {
        if (root == NULL)
        {
            return true;
        }
        
        bool bLeftValidBST  = isValidBST(root -> left);
        bool bRightValidBST = isValidBST(root -> right);
        
        if (bLeftValidBST && bRightValidBST)
        {
            int iLeftMaxValue  = INT_MIN;
            int iRightMinValue = INT_MAX;
            
            for (TreeNode * pstCurrent = root -> left; pstCurrent != NULL; pstCurrent = pstCurrent -> right)
            {
                if (pstCurrent -> val > iLeftMaxValue)
                {
                    iLeftMaxValue = pstCurrent -> val;
                }
            }
            
            for (TreeNode * pstCurrent = root -> right; pstCurrent != NULL; pstCurrent = pstCurrent -> left)
            {
                if (pstCurrent -> val < iRightMinValue)
                {
                    iRightMinValue = pstCurrent -> val;
                }
            }
            
            if ((root -> left == NULL || iLeftMaxValue < root -> val) && (root -> right == NULL || iRightMinValue > root -> val))
            {
                return true;
            }
        }
        
        return false;
    }
};

/*

Thinking is not right, and a lot of small bugs.

Normal recursion.

A binary tree is a binary search tree, whether its left sub tree and right sub tree are binary search trees, and MAX(LST) < root -> val < MIN(RST)

Time complexity: T(n) = T(n/2) + O(logn) = O(logn * logn)

*/
