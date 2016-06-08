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
        connect(root, true);
    }
    
private:

    void connect(TreeLinkNode * pstRoot, bool bNextFromLeftToRight)
    {
        if (pstRoot == NULL)
        {
            return;
        }
        
        connect(pstRoot -> left,  false);
        connect(pstRoot -> right, true);
        
        TreeLinkNode * pstLeft  = pstRoot -> left;
        TreeLinkNode * pstRight = pstRoot -> right;
        
        while ((bNextFromLeftToRight && pstLeft != NULL) || (!bNextFromLeftToRight && pstRight != NULL))
        {
            TreeLinkNode * pstLeftNext  = pstLeft;
            TreeLinkNode * pstRightNext = pstRight;
            
            while (pstLeftNext != NULL && pstLeftNext -> right == NULL && pstLeftNext -> left == NULL)
            {
                pstLeftNext = pstLeftNext -> next;
            }
            
            while (pstRightNext != NULL && pstRightNext -> right == NULL && pstRightNext -> left == NULL)
            {
                pstRightNext = pstRightNext -> next;
            }
            
            if (pstLeftNext != NULL)
            {
                pstLeftNext = (pstLeftNext -> right != NULL ? pstLeftNext -> right : pstLeftNext -> left);
            }
            
            if (pstRightNext != NULL)
            {
                pstRightNext = (pstRightNext -> left != NULL ? pstRightNext -> left : pstRightNext -> right);
            }
            
            if (bNextFromLeftToRight)
            {
                for (TreeLinkNode * pstRevBehind = pstLeft, * pstRevFront = pstLeft -> next; pstRevFront != NULL;)
                {
                    TreeLinkNode * pstRevFrontNext = pstRevFront -> next;
                    pstRevFront -> next            = pstRevBehind;
                    pstRevBehind                   = pstRevFront;
                    pstRevFront                    = pstRevFrontNext;
                }
                
                pstLeft -> next = pstRight;
            }
            else
            {
                for (TreeLinkNode * pstRevBehind = pstRight, * pstRevFront = pstRight -> next; pstRevFront != NULL;)
                {
                    TreeLinkNode * pstRevFrontNext = pstRevFront -> next;
                    pstRevFront -> next            = pstRevBehind;
                    pstRevBehind                   = pstRevFront;
                    pstRevFront                    = pstRevFrontNext;
                }
                
                pstRight -> next = pstLeft;
            }
            
            pstLeft  = pstLeftNext;
            pstRight = pstRightNext;
        }
    }
};

/*

Thinking is right, but a compile error and a small key bug.

1. Recurse on left sub-tree, and make the next field of each node point to left.

2. Recurse on right sub-tree, and make the next field of each node point to right.

3. For each level, reverse the next field linked list of left sub-tree, and then, make the right node point to the left node of the right sub-tree.

4. Generate the first nodes of the left sub-tree and right sub-tree before step 3. If the current node has no child, check the next link node. 

*/
