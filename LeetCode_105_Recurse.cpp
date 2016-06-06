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

    TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder)
    {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
private:

    TreeNode * buildTree(const vector<int> & vecPreorder, const vector<int> & vecInorder, int iPreStartIndex, int iPreEndIndex, int iInStartIndex, int iInEndIndex)
    {
        if (iPreStartIndex > iPreEndIndex || iInStartIndex > iInEndIndex)
        {
            return NULL;
        }
        
        int iRootValue             = vecPreorder[iPreStartIndex];
        int iRootValueInorderIndex = 0;
        
        for (iRootValueInorderIndex = iInStartIndex; iRootValueInorderIndex <= iInEndIndex; iRootValueInorderIndex ++)
        {
            if (iRootValue == vecInorder[iRootValueInorderIndex])
            {
                break;
            }
        }
        
        int iLeftPreStartIndex  = iPreStartIndex + 1;
        int iLeftPreEndIndex    = iPreStartIndex + iRootValueInorderIndex - iInStartIndex;
        int iRightPreStartIndex = iLeftPreEndIndex + 1;
        
        TreeNode * pstRoot = new TreeNode(iRootValue);
        pstRoot -> left    = buildTree(vecPreorder, vecInorder, iLeftPreStartIndex, iLeftPreEndIndex, iInStartIndex, iRootValueInorderIndex - 1);
        pstRoot -> right   = buildTree(vecPreorder, vecInorder, iRightPreStartIndex, iPreEndIndex, iRootValueInorderIndex + 1, iInEndIndex);
        return pstRoot;
    }
};
