/*

270. Closest Binary Search Tree Value

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

1. Given target value is a floating point.

2. You are guaranteed to have only one unique value in the BST that is closest to the target.

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

    int closestValue(TreeNode * root, double target)
    {
        int iClosest = root -> val;
        
        double dMinDifferent = fabs(target - root -> val);
        
        if (root -> left != NULL)
        {
            int iLeftClosest = closestValue(root -> left, target);
            
            double dMinDiffLeft = fabs(target - iLeftClosest);
            
            if (dMinDiffLeft < dMinDifferent)
            {
                dMinDifferent = dMinDiffLeft;
                iClosest      = iLeftClosest;
            }
        }
        
        if (root -> right != NULL)
        {
            int iRightClosest = closestValue(root -> right, target);
            
            double dMinDiffRight = fabs(target - iRightClosest);
            
            if (dMinDiffRight < dMinDifferent)
            {
                dMinDifferent = dMinDiffRight;
                iClosest      = iRightClosest;
            }
        }
        
        return iClosest;
    }
};
