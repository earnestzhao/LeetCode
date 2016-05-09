/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:

	int countNodes(TreeNode * root)
	{
		if (root == NULL)
		{
			return 0;
		}
		
		int iLeftHeight  = 0;
		int iRightHeight = 0;
		
		for (TreeNode * pstCurrent = root; pstCurrent != NULL; iLeftHeight ++,  pstCurrent = pstCurrent -> left);
		for (TreeNode * pstCurrent = root; pstCurrent != NULL; iRightHeight ++, pstCurrent = pstCurrent -> right);
		
		if (iLeftHeight == iRightHeight)
		{
			return (1 << iLeftHeight) - 1;
		}
		
		return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};

/*

Only thinking of middle-root traversal...

Using node number of full binary tree to reduce time complexity.

Caculate left height and right height of the complete binary tree.

If left height is equal to right height, then, the result is pow(2, h) - 1 which is the node number of full binary tree with height h.

Otherwise, recusive on left sub-tree and right sub-tree.

*/
