/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode
 * {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution
{
public:

    void connect(TreeLinkNode * root)
    {
        if (root == NULL || root -> left == NULL)
        {
            return;
        }
        
        connect(root -> left);
        connect(root -> right);
        
        for (TreeLinkNode * pstLeft = root -> left, * pstRight = root -> right; pstLeft != NULL; pstLeft = pstLeft -> right, pstRight = pstRight -> left)
        {
            pstLeft -> next = pstRight;
        }
    }
};
