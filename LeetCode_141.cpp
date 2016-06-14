/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:

    bool hasCycle(ListNode * head)
    {
        if (head == NULL)
        {
            return false;
        }
        
        ListNode * pstSlow = head;
        ListNode * pstFast = head -> next;
        
        while (pstFast != NULL)
        {
            if (pstFast == pstSlow || pstFast -> next == pstSlow)
            {
                return true;
            }
            
            pstSlow = pstSlow -> next;
            pstFast = pstFast -> next;
            
            if (pstFast != NULL)
            {
                pstFast = pstFast -> next;
            }
        }
        
        return false;
    }
};

/*

Bug free once.

Normal two pointers algorithm.

A fast pointer and a slow pointer.

*/
