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

    TreeNode * buildTree(vector<int> & inorder, vector<int> & postorder)
    {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
private:

    TreeNode * buildTree(const vector<int> & vecInorder, const vector<int> & vecPostorder, int iInStartIndex, int iInEndIndex, int iPostStartIndex, int iPostEndIndex)
    {
        if (iInStartIndex > iInEndIndex || iPostStartIndex > iPostEndIndex)
        {
            return NULL;
        }
        
        int iRootValue             = vecPostorder[iPostEndIndex];
        int iRootValueInorderIndex = 0;
        
        for (iRootValueInorderIndex = iInStartIndex; iRootValueInorderIndex <= iInEndIndex; iRootValueInorderIndex ++)
        {
            if (iRootValue == vecInorder[iRootValueInorderIndex])
            {
                break;
            }
        }
        
        int iPostRightEndIndex   = iPostEndIndex - 1;
        int iPostRightStartIndex = iPostEndIndex - iInEndIndex + iRootValueInorderIndex;
        int iPostLeftEndIndex    = iPostRightStartIndex - 1;
        
        TreeNode * pstRoot = new TreeNode(iRootValue);
        pstRoot -> left    = buildTree(vecInorder, vecPostorder, iInStartIndex, iRootValueInorderIndex - 1, iPostStartIndex, iPostLeftEndIndex);
        pstRoot -> right   = buildTree(vecInorder, vecPostorder, iRootValueInorderIndex + 1, iInEndIndex, iPostRightStartIndex, iPostRightEndIndex);
        return pstRoot;
    }
};

/*

Normal Recursion.

*/
