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
        ListNode * pstDummyHead = new ListNode(0);
        pstDummyHead -> next    = head;
        
        ListNode * pstBeforeRev = pstDummyHead;
        ListNode * pstAfterRev  = NULL;
        
        int iRevNumber = n - m;
        
        while (-- m)
        {
            pstBeforeRev = pstBeforeRev -> next;
        }
        
        ListNode * pstWorkerBehind = pstBeforeRev    -> next;
        ListNode * pstWorkerFront  = pstWorkerBehind -> next;
        pstAfterRev = pstWorkerFront;
        
        while (pstWorkerFront != NULL && iRevNumber --)
        {
            pstAfterRev            = pstWorkerFront -> next;
            pstWorkerFront -> next = pstWorkerBehind;
            pstWorkerBehind        = pstWorkerFront;
            pstWorkerFront         = pstAfterRev;
        }
        
        pstBeforeRev -> next -> next = pstAfterRev;
        pstBeforeRev -> next         = pstWorkerBehind;
        return pstDummyHead -> next;
    }
};

/*

Use dummy node to reduce complex.

*/
