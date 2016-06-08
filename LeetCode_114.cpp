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

    void flatten(TreeNode * root)
    {
        _flatten(root);
    }
    
private:

    TreeNode * _flatten(TreeNode * pstRoot)
    {
        if (pstRoot == NULL)
        {
            return NULL;
        }
        
        TreeNode * pstFlattenHeadLeft  = pstRoot -> left;
        TreeNode * pstFlattenHeadRight = pstRoot -> right;
        
        TreeNode * pstFlattenLeftRear  = _flatten(pstRoot -> left);
        TreeNode * pstFlattenRightRear = _flatten(pstRoot -> right);
        pstRoot -> left = NULL;
        
        if (pstFlattenHeadLeft != NULL)
        {
            pstRoot -> right            = pstFlattenHeadLeft;
            pstFlattenLeftRear -> right = pstFlattenHeadRight;
            pstFlattenLeftRear -> left  = NULL;
            
            if (pstFlattenLeftRear -> right == NULL)
            {
                return pstFlattenLeftRear;
            }
            
            return pstFlattenRightRear;
        }
        
        pstRoot -> right = pstFlattenHeadRight;
        
        if (pstRoot -> right == NULL)
        {
            return pstRoot;
        }
        
        return pstFlattenRightRear;
    }
};

/*

Bug free once!!! Corner conditions processed well.

Normal recursion. Do recusion on left and right, and then, combine them.

*/
