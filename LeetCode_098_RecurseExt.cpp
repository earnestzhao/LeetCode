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
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
private:

    bool isValidBST(TreeNode * root, long lMinValue, long lMaxValue)
    {
        if (root == NULL)
        {
            return true;
        }
        
        if (root -> val <= lMinValue || root -> val >= lMaxValue)
        {
            return false;
        }
        
        return isValidBST(root -> left, lMinValue, root -> val) && isValidBST(root -> right, root -> val, lMaxValue);
    }
};

/*

Normal recursion with a range value limit.

lMinValue is the sub tree's minimum value, and lMaxValue is the sub tree's maximum value.

The method is so smart, which gives out only top and bottom value. A more thinking reaches that...

*/
