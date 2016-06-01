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

    ListNode * reverseBetween(ListNode * head, int m, int n)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        if (head -> next == NULL)
        {
            return head;
        }
        
        if (m == n)
        {
            return head;
        }
        
        int iRangeIndexStart = m - 1;
        int iRangeIndexEnd   = n;
        
        ListNode * pstRevNewHead     = NULL;
        ListNode * pstAfterRevRange  = NULL;
        ListNode * pstBeforeRevRange = head;
        
        while (-- iRangeIndexStart > 0)
        {
            pstBeforeRevRange = pstBeforeRevRange -> next;
        }
        
        pstRevNewHead    = pstBeforeRevRange -> next;
        pstAfterRevRange = pstRevNewHead     -> next;
        
        for (; pstAfterRevRange != NULL && iRangeIndexEnd > (m == 1 ? 2 : m); iRangeIndexEnd --)
        {
            ListNode * pstAfterRevRangeNext = pstAfterRevRange -> next;
            pstAfterRevRange -> next        = pstRevNewHead;
            pstRevNewHead                   = pstAfterRevRange;
            pstAfterRevRange                = pstAfterRevRangeNext;
        }
        
        if (m == 1)
        {
            head -> next -> next = head;
            head -> next         = pstAfterRevRange;
            return pstRevNewHead;
        }
        
        pstBeforeRevRange -> next -> next = pstAfterRevRange;
        pstBeforeRevRange -> next         = pstRevNewHead;
        return head;
    }
};

/*

Thinking is right, but because of too many corner conditions, too many bugs.

Normal algorithm. Take care of the condition which m is 1.

Normal reversing. If m is 1, reverse it from 2, then, process the head singly.

There must be better solutions. This solution is complex.

*/
