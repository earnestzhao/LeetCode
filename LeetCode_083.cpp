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

    ListNode * deleteDuplicates(ListNode * head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        if (head -> next == NULL)
        {
            return head;
        }
        
        ListNode * pstBehind = head;
        ListNode * pstFront  = head -> next;
        
        while (pstFront != NULL)
        {
            if (pstFront -> val == pstBehind -> val)
            {
                pstBehind -> next = pstFront  -> next;
                pstFront          = pstBehind -> next;
            }
            else
            {
                pstBehind = pstFront;
                pstFront  = pstFront -> next;
            }
        }
        
        return head;
    }
};

/*

Bug free once. Just normal algorithm.

*/
