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

    ListNode * oddEvenList(ListNode * head)
    {
        ListNode * pstDummyHead = new ListNode(0);
        pstDummyHead -> next    = head;
        
        ListNode * pstBehind = pstDummyHead;
        ListNode * pstFront  = pstDummyHead -> next;
        
        ListNode * pstEvenList     = new ListNode(0);
        ListNode * pstEvenListTail = pstEvenList;
        
        for (; pstFront != NULL && pstFront -> next != NULL; pstBehind = pstFront, pstFront = pstFront -> next)
        {
            ListNode * pstEvenNode  = pstFront -> next;
            pstFront -> next        = pstEvenNode -> next;
            pstEvenNode -> next     = NULL;
            pstEvenListTail -> next = pstEvenNode;
            pstEvenListTail         = pstEvenNode;
        }
        
        ListNode * pstOddListTail = (pstFront != NULL ? pstFront : pstBehind);
        pstOddListTail -> next    = pstEvenList -> next;
        return head;
    }
};
