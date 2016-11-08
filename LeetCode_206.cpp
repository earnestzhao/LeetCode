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

    ListNode * reverseList(ListNode * head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        ListNode * pstBehind = head;
        
        for (ListNode * pstFront = head -> next; pstFront != NULL;)
        {
            ListNode * pstNext = pstFront -> next;
            pstFront -> next   = pstBehind;
            pstBehind          = pstFront;
            pstFront           = pstNext;
        }
        
        return pstBehind;
    }
};
