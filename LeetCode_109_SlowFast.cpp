/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

    TreeNode * sortedListToBST(ListNode * head)
    {
        return sortedArrayToBST(head, NULL);
    }
    
private:

    TreeNode * sortedArrayToBST(ListNode * pstBuildNodeStart, ListNode * pstBuildNodeEndNext)
    {
        if (pstBuildNodeStart == pstBuildNodeEndNext)
        {
            return NULL;
        }
        
        ListNode * pstFast = pstBuildNodeStart;
        ListNode * pstSlow = pstBuildNodeStart;
        
        while (pstFast != pstBuildNodeEndNext && pstFast -> next != pstBuildNodeEndNext)
        {
            pstSlow = pstSlow -> next;
            pstFast = pstFast -> next -> next;
        }
        
        TreeNode * pstRoot = new TreeNode(pstSlow -> val);
        pstRoot -> left    = sortedArrayToBST(pstBuildNodeStart, pstSlow);
        pstRoot -> right   = sortedArrayToBST(pstSlow -> next, pstBuildNodeEndNext);
        return pstRoot;
    }
};

/*

Using slow pointer and fast pointer to judge middle position, and then, do recursion.

The next node of list range ending is a good point!!!

T(n) = 2T(n/2) + O(n) = O(nlogn).

*/
